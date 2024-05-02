<script>
    import { browser } from '$app/environment';
    import { onMount } from 'svelte';
    import * as THREE from "three"
	import { cube, cube2, esfera, camera, scene } from './gameComponents.ts'
    import {localizationDict, localize} from '../../localization/localize.js'

	export let data;
	let language = data.mainUserData ? data.mainUserData.lang : 'en';
    let renderer;
	let playerId;
	let container;
	let player_1, player_2;
	let score_1 = 0, score_2 = 0;
	let game_ended = false;
	let modal;

    onMount(() => {
		gameID = window.location.href;
		gameID = gameID.split("/")[5];
		gameID = gameID.replace(/\-/g, "");
		console.log("gameID: ", gameID);
		const windowWidth = 800;
		const windowHeight = 500;

		renderer = new THREE.WebGLRenderer();
		renderer.setSize(windowWidth, windowHeight);
		container.appendChild(renderer.domElement);

		renderer.render(scene, camera);

        const socket = new WebSocket(
            'ws://'
            + '/ws/game/'
			+ gameID
            + '/' // cambiar con uuid para cada partida
        )
			console.log(response);
			if (response.type == "stateUpdate")
			{
				/* console.log(response); */
				esfera.position.z = response.objects.ball_y;
				esfera.position.x = response.objects.ball_x;
				cube.position.z = response.objects.p1_y;
				cube2.position.z = response.objects.p2_y;
				renderer.render(scene, camera);
				score_1 = response.objects.score_1;
				score_2 = response.objects.score_2;
			}
			else if (response.type == "playerId")
			{
				playerId = response.playerId;
			}
			else if(response.type = "finish_game")
			{
				socket.close();
				game_ended = true;
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
                    type: 'puase',
                }
                socket.send(JSON.stringify(message));
            }
        });


</script>


<div class="flex justify-center flex-col items-center">
	<div class="w-800 h-800 bg-gray-200" bind:this={container}></div>
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

<dialog bind:this={modal} class="modal modal-bottom sm:modal-middle">
  <div class="modal-box">
    <h3 class="font-bold text-lg">{localize('hello', language)}</h3>
    <p class="py-4">{localize('press_ESC', language)}</p>
    <div class="modal-action">
      <form method="dialog">
        <!-- if there is a button in form, it will close the modal -->
        <button class="btn"><a href="/">{localize('close', language)}</a></button>
      </form>
    </div>
  </div>
</dialog>
