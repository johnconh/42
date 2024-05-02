<script>
    import { browser } from '$app/environment';
    import { onMount } from 'svelte';
    import * as THREE from "three"
	import { cube, cube2, esfera, camera, scene } from './gameComponents.ts'
	import { saveGame } from '../manageSockets.ts'
    import {localizationDict, localize} from '../../../localization/localize.js'

	export let data;
	let language = data.mainUserData ? data.mainUserData.lang : 'en';
    let renderer;
	let playerId;
	let container;
	let player_1, player_2;
	let score_1 = 0, score_2 = 0;
	let game_ended = false;
	let modal;
	let gameID;
	let winner = "";
	let playername, opponentname;
	let url;

    onMount(() => {
		url = window.location.href;
		url = url.split("/")[4];
		gameID = url.split("?")[0];
		gameID = gameID.replace(/\-/g, "");
		// url = url.split("?")[1];
		// playername = url.split("&")[0];
		// opponentname = url.split("&")[1];
		// console.log("playername: ", playername);
		const windowWidth = 800;
		const windowHeight = 500;

		renderer = new THREE.WebGLRenderer({ alpha: true });
    	renderer.setClearColor(0x000000, 0); // Fondo transparente
		renderer.setSize(windowWidth, windowHeight);
		container.appendChild(renderer.domElement);

		renderer.render(scene, camera);

        /* const socket = new WebSocket( */
        /*     'ws://' */
        /*     + 'localhost:61001' // cambiar si aplica para porduccion *1/ */
        /*     + '/ws/game/' */
			/* + gameID */
        /*     + '&' // cambiar con uuid para cada partida *1/ */
			/* + data.mainUserData.user_name */
			/* + '/' // cambiar con uuid para cada partida *1/ */
        /* ) */

        const socket = new WebSocket(
            'wss://'
            + 'localhost' // cambiar si aplica para porduccion
            + '/ws/game/'
			+ gameID
			+ '&' // cambiar con uuid para cada partida
			+ data.mainUserData.user_name
			+ '/' // cambiar con uuid para cada partida
        )


		socket.addEventListener('message', function (event) {
			const response = JSON.parse(event.data);
			console.log("socket: ", socket)
			/* console.log("response: ", response); */
			if(response.type == "playerNames")
			{
				console.log("response: ", response);
				player_1 = response.player1;
				player_2 = response.player2;
			}
			else if(response.type == "id_banned")
				window.location.href = '/';
			else if (response.type == "stateUpdate")
			{
				/* console.log(response); */
				/* console.log("response: ", response); */
				esfera.position.z = response.objects.ball_y;
				esfera.position.x = response.objects.ball_x;
				cube.position.z = response.objects.p1_y;
				cube2.position.z = response.objects.p2_y;
				renderer.render(scene, camera);
				score_1 = response.objects.score_1;
				score_2 = response.objects.score_2;
				player_1 = response.objects.player1;
				player_2 = response.objects.player2;
			}
			else if (response.type == "playerId")
			{
				playerId = response.playerId;
			}
			else if(response.type = "finish_game")
			{
				socket.close();
				game_ended = true;
				// if (score_1 > score_2)
				// 	winner = player_1;
				// else
				// 	winner = player_2
				winner = response.winner;
				console.log("player_1: ", player_1)
				console.log("player_2: ", player_2)
				console.log("score_1: ", score_1)
				console.log("score_2: ", score_2)
				saveGame(gameID, player_1, player_2, score_1, score_2, "matchmaking")
				modal.showModal();
			}
		});

        window.addEventListener('keydown', function(event) {
            if (event.key === 'ArrowDown') { // key code for the arrow down key
                const message = {
					playerId: playerId,
                    type: 'up',
                }
                socket.send(JSON.stringify(message));
				console.log("up");
            }

			else if (event.key === 'ArrowUp') { // key code for the arrow down key
                const message = {
					playerId: playerId,
                    type: 'down',
                }
                socket.send(JSON.stringify(message));
            }

			else if (event.key === 32 ) { // key code for the space
                const message = {
                    playerId: sessionStorage.getItem('playerId'),
                    type: 'pause',
                }
                socket.send(JSON.stringify(message));
            }
        });
	});


</script>


<div class="flex justify-center flex-col items-center">
	<div class="w-800 h-800" bind:this={container}></div>
	<div class="flex justify-center">
		<div class="stats shadow">
			<div class="stat">
				<div class="stat-title">{player_1}</div>
				<div class="stat-value">{score_1}</div>
			</div>
		</div>
		<div class="stats shadow">
			<div class="stat">
				<div class="stat-title">{player_2}</div>
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
