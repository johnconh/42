<script lang="ts">
  import type { PageData } from "./$types";
  import { onMount } from "svelte";
  import { goto } from "$app/navigation";
  import { get } from "svelte/store";
  import { user } from "../../stores";
  import crownImage from "../../lib/images/crown.webp";
  import { browser } from "$app/environment";
  import * as THREE from "three";
	import { cube, cube2, esfera, camera, scene, updateGame } from './gameComponents.ts';
	import { handleKeyDown, handleKeyUp, newSocket, saveGame } from './manageSockets.ts';
  import { localizationDict, localize } from "../../localization/localize.js";

  let playerId, playerId2;
	let container;
  let renderer;

  let foundtext = false;

  let gameOn = false;
  let finalOn = false;
  let tournamentOn = false;

  let player_1, player_2;
  let score_1 = 0,
    score_2 = 0;
  let counter;

  export let data: PageData;
  let language = data.mainUserData ? data.mainUserData.lang : "en";

  let game1socket;
  let finalsocket;

  let player1 = {
    user_name: "Player 1",
    avatar_fileName: "media/user.png",
    winner: "true",
  };

  let player2 = {
    user_name: "Player 2",
    avatar_fileName: "media/user.png",
    winner: "true",
  };

  let player3 = {
    user_name: "Player 3",
    avatar_fileName: "media/user.png",
    winner: "true",
  };

  let player4 = {
    user_name: "Player 4",
    avatar_fileName: "media/user.png",
    winner: "true",
  };

  let winner1 = {
    user_name: "",
    avatar_fileName: "",
    winner: "true",
  };
  let winner2 = {
    user_name: "",
    avatar_fileName: "",
    winner: "true",
  };

  let finalWinner = {
    user_name: "",
    avatar_fileName: "",
    winner: "true",
  };

  function delay(ms) {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }

  async function game() {
    const windowWidth = 800;
    const windowHeight = 500;

    await delay(1000);
    renderer = new THREE.WebGLRenderer();
    renderer.setSize(windowWidth, windowHeight);
    document
      .getElementById("canvas-container")
      .appendChild(renderer.domElement);
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
        if (!winner1.user_name)
        if (score_1 > score_2){
            winner1.user_name = player1.user_name
            winner1.avatar_fileName = player1.avatar_fileName
            winner1.winner = "true";
            player2.winner = "false";
          }
          else
          {
            winner1.user_name = player2.user_name
            winner1.avatar_fileName = player2.avatar_fileName
            winner1.winner = "true";
            player1.winner = "false";
          }
        else if (!winner2.user_name)
          if (score_1 > score_2){
            winner2.user_name = player3.user_name
            winner2.avatar_fileName = player3.avatar_fileName
            winner2.winner = "true";
            player4.winner = "false";
          }
          else
          {
            winner2.user_name = player4.user_name
            winner2.avatar_fileName = player4.avatar_fileName
            winner2.winner = "true";
            player3.winner = "false";
          }
        else
          if (score_1 > score_2){
            finalWinner = winner1
            winner2.winner = "false";
          }
          else {
            finalWinner = winner2
            winner1.winner = "false";
          }
				gameOn = false;
			}
		});
		window.addEventListener('keydown', e => handleKeyDown(e, controller, playerId));
		window.addEventListener('keyup', e => handleKeyUp(e, controller, playerId2));
	}

  async function countdown() {
    counter = 6;
    countermodal.showModal();
    foundtext = true;
    await delay(1000);
    foundtext = false;
    while (counter > 0) {
      counter--;
      await delay(1000);
    }
    countermodal.close();
  }


  function showNameModal() {
    nameModal.showModal();
  }

  function nameFunction() {
    if (player1.user_name == "") {
      player1.user_name = "Player 1";
    }
    if (player2.user_name == "") {
      player2.user_name = "Player 2";
    }
    if (player3.user_name == "") {
      player3.user_name = "Player 3";
    }
    if (player4.user_name == "") {
      player4.user_name = "Player 4";
    }
    nameModal.close();
  }

  async function startGame() {
    tournamentOn = true;
    await countdown();
    gameOn = true;
    player_1 = player1.user_name;
    player_2 = player2.user_name;
    game();
    while (gameOn) {
      await delay(1000);
    }
    await delay(2000);
    await countdown();
    gameOn = true;
    player_1 = player3.user_name;
    player_2 = player4.user_name;
    game();
    while (gameOn) {
      await delay(1000);
    }
    await delay(2000);
    await countdown();
    gameOn = true;
    player_1 = winner1.user_name;
    player_2 = winner2.user_name;
    game();
    while (gameOn) {
      await delay(1000);
    }
    await delay(2000);
  }

  onMount(async () => {
    gameOn = false;
    finalOn = false;
    delay(1000);
  });
</script>

<dialog id="nameModal" class="modal">
  <div class="flex flex-col items-center">
    <p class="font-bold text-5xl text-center mt-6">
      {localize("change_names", language)}
    </p>
    <div class="flex flex-col items-center mt-10">
      <input
        bind:value={player1.user_name}
        type="text"
        class="input w-60 h-12 text-center"
        placeholder={player1.user_name}
      />
      <input
        bind:value={player2.user_name}
        type="text"
        class="input w-60 h-12 text-center mt-5"
        placeholder={player2.user_name}
      />
      <input
        bind:value={player3.user_name}
        type="text"
        class="input w-60 h-12 text-center mt-5"
        placeholder={player3.user_name}
      />
      <input
        bind:value={player4.user_name}
        type="text"
        class="input w-60 h-12 text-center mt-5"
        placeholder={player4.user_name}
      />
      <button class="btn btn-primary w-60 h-20 mt-5"
        on:click={nameFunction}
        >{localize("save", language)}</button
      >
    </div>
  </div>
</dialog>

<dialog id="countermodal" class="modal">
  {#if foundtext}
    {#if winner1.user_name && winner2.user_name}
      <p class="font-bold mb-14 font-mono text-8xl text-center mt-16">
        {winner1.user_name} vs {winner2.user_name}
      </p>
    {:else if winner1.user_name}
      <p class="font-bold mb-14 font-mono text-8xl text-center mt-16">
        {player3.user_name} vs {player4.user_name}
      </p>
      {:else}
      <p class="font-bold mb-14 font-mono text-8xl text-center mt-16">
        {player1.user_name} vs {player2.user_name}
      </p>
    {/if}
  {:else}
    <span class="countdown font-mono font-bold text-8xl">
      <span style={`--value:${counter};`} />
    </span>
  {/if}
</dialog>

<dialog id="finalModal" class="modal">
  <img class="absolute top-24 right-50% w-52" src={crownImage} />
  <li
    id="round-2"
    class="flex items-center justify-center w-96 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative"
  >
    <div class="avatar">
      <div class="w-full justify-center flex rounded-full">
        <img src={finalWinner.avatar_fileName} />
      </div>
    </div>
    <div class="flex top-96 mt-10 justify-center absolute">
      <button class="btn w-44 h-20 btn-primary"
        >{localize("back", language)}</button
      >
    </div>
  </li>
</dialog>

{#if gameOn == false && finalOn == false}
  <h1 class="font-bold text-5xl text-center mt-6">
    {localize("tournament", language)}
  </h1>
  {#if tournamentOn == false}
    <div class="flex mt-10 flex-row gap-10 justify-center">
      <button on:click={showNameModal} class="btn btn-primary w-60 h-20 text-xl"
        >{localize("change_names", language)}</button
      >
      <button on:click={startGame} class="btn btn-primary w-60 h-20 text-xl">{localize("start", language)}</button>
    </div>
  {/if}

  <div class="flex mr-3 mt-16">
    <ol class="flex flex-1 flex-col justify-around mr-5 ml-5 round">
      <li
        id="round-2"
        class={player1.winner == "true"
          ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
          : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
      >
        <div class="avatar inline-block">
          <div class="w-24  rounded-full">
            <img src={player1.avatar_fileName} />
          </div>
        </div>
        <p class="font-bold text-2xl ml-3 mr-3">
          {player1.user_name}
        </p>
        <div class="flex-grow" />
      </li>
      <li
        id="round-2"
        class={player2.winner == "true"
          ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
          : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
      >
        <div class="avatar inline-block">
          <div class="w-24  rounded-full">
            <img src={player2.avatar_fileName} alt="Player 2 Avatar" />
          </div>
        </div>
        <p class="font-bold text-2xl ml-3 mr-3">
          {player2.user_name}
        </p>
        <div class="flex-grow" />
      </li>
      <li
        id="round-2"
        class={player3.winner == "true"
          ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
          : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
      >
        <div class="avatar inline-block">
          <div class="w-24  rounded-full">
            <img src={player3.avatar_fileName} alt="Player 2 Avatar" />
          </div>
        </div>
        <p class="font-bold text-2xl ml-3 mr-3">
          {player3.user_name}
        </p>
        <div class="flex-grow" />
      </li>
      <li
        id="round-2"
        class={player4.winner == "true"
          ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
          : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
      >
        <div class="avatar inline-block">
          <div class="w-24  rounded-full">
            <img src={player4.avatar_fileName} alt="Player 4 Avatar" />
          </div>
        </div>
        <p class="font-bold text-2xl ml-3 mr-3">
          {player4.user_name}
        </p>
        <div class="flex-grow" />
      </li>
    </ol>
    <ol class="flex flex-1 flex-col justify-around mr-5 ml-5 round">
      {#if winner1.user_name}
        <li
          id="round-2"
          class={winner1.winner == "true"
            ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
            : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
        >
          <div class="avatar inline-block">
            <div class="w-24  rounded-full">
              <img src={winner1.avatar_fileName} />
            </div>
          </div>
          <p class="font-bold text-2xl ml-3 mr-3">{winner1.user_name}</p>
          <div class="flex-grow" />
        </li>
      {:else}
        <li
          id="round-2"
          class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
        >
          <div class="avatar inline-block">
            <div class="w-24  rounded-full">
              <img
                src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
              />
            </div>
          </div>
          <span class="loading loading-dots loading-lg" />
          <div class="flex-grow" />
        </li>
      {/if}
      {#if winner2.user_name}
        <li
          id="round-2"
          class={winner2.winner == "true"
            ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
            : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
        >
          <div class="avatar inline-block">
            <div class="w-24  rounded-full">
              <img src={winner2.avatar_fileName} />
            </div>
          </div>
          <p class="font-bold text-2xl ml-3 mr-3">{winner2.user_name}</p>
          <div class="flex-grow" />
        </li>
      {:else}
        <li
          id="round-2"
          class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
        >
          <div class="avatar inline-block">
            <div class="w-24  rounded-full">
              <img
                src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
              />
            </div>
          </div>
          <span class="loading loading-dots loading-lg" />
          <div class="flex-grow" />
        </li>
      {/if}
    </ol>
    {#if finalWinner.user_name}
      <ol
        class="flex flex-1 flex-col justify-around mr-5 ml-5 round round-winner"
      >
        <li
          id="round-2"
          class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
        >
          <div class="avatar inline-block">
            <div class="w-24  rounded-full">
              <img src={finalWinner.avatar_fileName} />
            </div>
          </div>
          <p class="font-bold text-2xl ml-3 mr-3">{finalWinner.user_name}</p>
          <div class="flex-grow" />
        </li>
      </ol>
    {:else}
      <ol
        class="flex flex-1 flex-col justify-around mr-5 ml-5 round round-winner"
      >
        <li
          id="round-2"
          class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
        >
          <div class="avatar inline-block">
            <div class="w-24  rounded-full">
              <img
                src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
              />
            </div>
          </div>
          <span class="loading loading-dots loading-lg" />
          <div class="flex-grow" />
        </li>
      </ol>
    {/if}
  </div>
{:else if gameOn == true}
  <div class="flex justify-center flex-col items-center">
    <div id="canvas-container" style="width: 800px; height: 600px;">
      <!-- {#if renderer}
        <canvas />
      {/if} -->
    </div>
  </div>
  <div class="flex justify-center flex-col items-center">
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
{/if}
{#if finalOn == true}
  <div class="flex justify-center flex-col items-center">
    <div id="final-container" style="width: 800px; height: 600px;" />
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
{/if}

<style>
  .ingame {
    /* filter: grayscale(80%); */
    --tw-bg-opacity: 1;
    background-color: rgb(75 85 99 / var(--tw-bg-opacity));
  }
  .loose {
    filter: grayscale(100%);
    --tw-bg-opacity: 1;
    background-color: rgb(17 24 39 / var(--tw-bg-opacity));
    color: rgb(209 213 219 / 0.2);
  }

  .win {
    --tw-bg-opacity: 1;
    background-color: rgb(75 85 99 / var(--tw-bg-opacity));
  }
  .with-connector:after {
    content: " ";
    position: absolute;
    left: calc(100% + 0.5rem); /* participant size (includes margin) */
    width: 1.25rem; /* round margin-right */
    border: 2px solid #e2e8f0;
    border-left: none;
  }

  .with-connector:nth-child(odd):after {
    top: 50%;
    border-bottom: none;
  }

  .with-connector:nth-child(even):after {
    bottom: 50%;
    border-top: none;
  }

  /*
  height formula for a given round connector:
  connectorHeight(roundNumber) = (margin + (lineHeight + padding)/2) * r^(n-1)

  where:
  - margin = 8px (.m-2)
  - line-height = 24px (.leading-relaxed)
  - padding = 4px (.p-1)
*/
  .round:nth-child(1) .with-connector:after {
    height: 60px;
  }

  .round:nth-child(2) .with-connector:after {
    height: 120px;
  }

  .round:nth-child(3) .with-connector:after {
    height: 0px;
  }

  .round:nth-child(4) .with-connector:after {
    height: 200px;
  }

  .round.round-winner .with-connector:after {
    width: 0;
  }

  /*
  Incoming connector
 */
  .round + .round .with-connector:before {
    content: " ";
    position: absolute;
    left: -1.75rem; /* competitor margin + current width */
    top: 50%;
    width: 1.25rem; /* round margin-left */
    border-top: 2px solid #e2e8f0;
  }
  /*
  Byes
*/

  .with-connector.with-bye {
    margin-top: 33px;
    margin-bottom: 33px;
  }

  .round .with-connector.with-bye:after {
    height: 0;
  }

  .with-connector.with-bye + .with-connector {
    display: none;
  }

  /* second option for byes */
  /*
.with-bye + .with-connector {
  visibility: hidden
}
*/

  /* third option for byes */
  /*
.with-bye,
.with-bye + .with-connector {
  visibility: hidden
}

.round .with-connector.from-bye:before {
  width: 0
}
*/
</style>
