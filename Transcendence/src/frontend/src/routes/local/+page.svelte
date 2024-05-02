<script>
    import { browser } from '$app/environment';
    import { onMount } from 'svelte';
    import * as THREE from "three";
	import { cube, cube2, esfera, camera, scene, updateGame } from './gameComponents.ts';
	import { handleKeyDown, handleKeyUp, newSocket, saveGame } from './manageSockets.ts';
    import {localizationDict, localize} from '../../localization/localize.js';


	export let data;
	let language = data.mainUserData ? data.mainUserData.lang : 'en';

    let renderer;
	let playerId, playerId2;
	let container;
	let player_1, player_2;
	let score_1 = 0, score_2 = 0;
	let game_ended = false;
	let winner = "";
	let modal;


    onMount(() => {
		const windowWidth = 800;
		const windowHeight = 500;

		renderer = new THREE.WebGLRenderer({ alpha: true });
    	renderer.setClearColor(0x000000, 0); // Fondo transparente
		renderer.setSize(windowWidth, windowHeight);
		container.appendChild(renderer.domElement);

		renderer.render(scene, camera);

		const uniqueNumber = Math.floor(Math.random() * 1000000);
        const socket = newSocket(uniqueNumber)
        const socket2 = newSocket(uniqueNumber)

		console.log(socket)

		const controller = {
			'w': {pressed: false, direction: 'down', socket: socket, playerId: 0},
			's': {pressed: false, direction: 'up', socket: socket, playerId: 0},
			'ArrowUp': {pressed: false, direction: 'down', socket: socket2, playerId: 0},
			'ArrowDown': {pressed: false, direction: 'up', socket:socket2, playerId: 0},
		}

		socket2.addEventListener('message', event => {
			const { playerId } = JSON.parse(event.data);
			if (playerId){
				controller['ArrowUp'].playerId = playerId
				controller['ArrowDown'].playerId = playerId
				playerId2 = playerId;
			}
		});


		socket.addEventListener('message', function (event) {
			const response = JSON.parse(event.data);
			if (response.type == "stateUpdate")
			{
				updateGame(response)
				renderer.render(scene, camera);
				score_1 = response.objects.score_1;
				score_2 = response.objects.score_2;
			}
			else if (response.type == "playerId")
			{
				controller['w'].playerId = response.playerId;
				controller['s'].playerId = response.playerId;
				playerId = response.playerId;
			}
			else if(response.type = "finish_game")
			{
				socket.close();
				socket2.close();
				console.log(response)
				game_ended = true;
				if (score_1 > score_2)
					winner = localize('player1', language);
				else
					winner = "Player 2";
				modal.showModal();
			}
		});

		window.addEventListener('keydown', e => handleKeyDown(e, controller, playerId));
		window.addEventListener('keyup', e => handleKeyUp(e, controller, playerId2));
	});


</script>


<div class="flex justify-center flex-col items-center">
	<div class="w-800 h-800" bind:this={container}></div>
	<div class="flex justify-center">
		<div class="stats shadow">
			<div class="stat">
				<div class="stat-title">{localize('player1', language)}</div>
				<div class="stat-value">{score_1}</div>
			</div>
		</div>
		<div class="stats shadow">
			<div class="stat">
				<div class="stat-title">{localize('player2', language)}</div>
				<div class="stat-value">{score_2}</div>
			</div>
		</div>
	</div>
</div>

<dialog close="false" bind:this={modal} class="modal modal-bottom sm:modal-middle" on:keydown|preventDefault={() => {if(modal.open) window.location.href='/'}}>
	<div class="modal-box">
		<h3 class="font-bold text-lg">{localize('winner', language)}: {winner}</h3>
		<p class="py-4">{localize('press_key_to_close', language)}</p>
		<div class="modal-action">
			<form method="dialog">
				<!-- if there is a button in form, it will close the modal -->
				<button class="btn"><a href="/">{localize('close', language)}</a></button>
			</form>
		</div>
	</div>
</dialog>
