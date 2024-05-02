<script lang="ts">
  import type { PageData } from "./$types";
  import { onMount } from "svelte";
  import { goto } from "$app/navigation";
  import { get } from "svelte/store";
  import { user } from "../../stores";
  import crownImage from "../../lib/images/crown.webp";
  import { browser } from "$app/environment";
  import * as THREE from "three";
  import { cube, cube2, esfera, camera, scene } from "./gameComponents.ts";
  import { saveGame } from "./manageSockets.ts";
  import { gameOne, finalGame } from "./games.ts";
  import { localizationDict, localize } from "../../localization/localize.js";

  let gameOn = false;
  let finalOn = false;

  let renderer;
  let playerId;
  let container;
  let player_1, player_2;
  let score_1 = 0,
    score_2 = 0;
  let game_ended = false;
  let modal;
  let gameID;
  let playername, opponentname;
  let url;
  let winner;
  let counter;

  export let data: PageData;
  let language = data.mainUserData ? data.mainUserData.lang : "en";

  let foundtext = false;
  let mfound = false;

  let socket;
  let game1socket;
  let finalsocket;

  let RivalData = {
    user_name: "",
    avatar: "",
    avatar_fileName: "",
  };

  let tournamentCode = "";

  let tempPlayers = [];
  let thisPlayers = {};

  let winner1 = {
    user_name: "",
    avatar: "",
    avatar_fileName: "",
    winner: "true",
  };
  let winner2 = {
    user_name: "",
    avatar: "",
    avatar_fileName: "",
    winner: "true",
  };

  let finalWinner = {
    user_name: "",
    avatar: "",
    avatar_fileName: "true",
  };

  function delay(ms) {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }

  class player {
    name: string;
    avatar: string;
  }

  async function endTournament() {
    console.log("endTournament");
    const user_name = data.mainUserData.user_name;
    const type = "endTournament";
    const sendData = JSON.stringify({ user_name, type, tournamentCode });
    await socket.send(sendData);
    window.location.href = "/";
  }

  async function getRivalData(userName: string) {
    const response = await fetch("/api/userData/getRivalData", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        user_name: userName,
      }),
    });
    const responseBody = await response.json();
    RivalData = responseBody;
  }

  async function createTournament(event) {
    const user_name = data.mainUserData.user_name;
    const type = "createTournament";
    const sendData = JSON.stringify({ user_name, type, tournamentCode });
    await socket.send(sendData);
  }

  async function joinTournament(event) {
    const user_name = data.mainUserData.user_name;
    const type = "joinTournament";
    const sendData = JSON.stringify({ user_name, type, tournamentCode });
    await socket.send(sendData);
  }

  async function getTournamentPlayers(resdata) {
    tempPlayers = resdata.players;
    thisPlayers = {};
    for (let i = 0; i < tempPlayers.length; i++) {
      thisPlayers[i] = new player();
      await getRivalData(tempPlayers[i]);
      thisPlayers[i].user_name = RivalData.user_name;
      thisPlayers[i].avatar = RivalData.avatar;
      thisPlayers[i].avatar_fileName = RivalData.avatar_fileName;
      thisPlayers[i].winner = "true";
    }
  }

  async function roundTwo(resdata) {
    tournamentCode = resdata.code;
    tempPlayers = resdata.players;
    thisPlayers = {};
    for (let i = 0; i < tempPlayers.length; i++) {
      thisPlayers[i] = new player();
      await getRivalData(tempPlayers[i]);
      thisPlayers[i].user_name = RivalData.user_name;
      thisPlayers[i].avatar = RivalData.avatar;
      thisPlayers[i].avatar_fileName = RivalData.avatar_fileName;
      if (
        thisPlayers[i].user_name == resdata.winner1 ||
        thisPlayers[i].user_name == resdata.winner2
      ) {
        thisPlayers[i].winner = "true";
      }
    }
    if (resdata.winner1) {
      await getRivalData(resdata.winner1);
      winner1.user_name = resdata.winner1;
      winner1.user_name = RivalData.user_name;
      winner1.avatar = RivalData.avatar;
      winner1.avatar_fileName = RivalData.avatar_fileName;
    }

    if (resdata.winner2) {
      await getRivalData(resdata.winner2);
      winner2.user_name = resdata.winner2;
      winner2.user_name = RivalData.user_name;
      winner2.avatar = RivalData.avatar;
      winner2.avatar_fileName = RivalData.avatar_fileName;
    }
  }

  async function roundThree(resdata) {
    if (resdata.winner == data.mainUserData.user_name) {
      finalModal.showModal();
    }
    tournamentCode = resdata.code;
    tempPlayers = resdata.players;
    thisPlayers = {};
    for (let i = 0; i < tempPlayers.length; i++) {
      thisPlayers[i] = new player();
      await getRivalData(tempPlayers[i]);
      thisPlayers[i].user_name = RivalData.user_name;
      thisPlayers[i].avatar = RivalData.avatar;
      thisPlayers[i].avatar_fileName = RivalData.avatar_fileName;
      if (
        thisPlayers[i].user_name == resdata.winner1 ||
        thisPlayers[i].user_name == resdata.winner2
      ) {
        thisPlayers[i].winner = "true";
      }
    }

    if (resdata.winner1) {
      await getRivalData(resdata.winner1);
      winner1.user_name = resdata.winner1;
      winner1.user_name = RivalData.user_name;
      winner1.avatar = RivalData.avatar;
      winner1.avatar_fileName = RivalData.avatar_fileName;
      if (winner1.user_name != resdata.winner) {
        winner1.winner = "false";
      } else {
        winner1.winner = "true";
      }
    }

    if (resdata.winner2) {
      await getRivalData(resdata.winner2);
      winner2.user_name = resdata.winner2;
      winner2.user_name = RivalData.user_name;
      winner2.avatar = RivalData.avatar;
      winner2.avatar_fileName = RivalData.avatar_fileName;
      if (winner2.user_name != resdata.winner) {
        winner2.winner = "false";
      } else {
        winner2.winner = "true";
      }
    }

    if (resdata.winner) {
      await getRivalData(resdata.winner);
      finalWinner.user_name = resdata.winner;
      finalWinner.user_name = RivalData.user_name;
      finalWinner.avatar = RivalData.avatar;
      finalWinner.avatar_fileName = RivalData.avatar_fileName;
    }
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

  async function finalGameFunc(gameid) {
    let mfound: boolean;
    mfound = true;
    // await getRivalData(rivalUserName);
    await delay(700);
    await countdown();
    finalOn = true;
    const windowWidth = 800;
    const windowHeight = 500;

    await delay(1000);
    renderer = new THREE.WebGLRenderer();
    renderer.setClearColor(0x000000, 0); // Fondo transparente
    renderer.setSize(windowWidth, windowHeight);
    document.getElementById("final-container").appendChild(renderer.domElement);
    renderer.render(scene, camera);

    const finalsocket = new WebSocket(
      "ws://" +
        "localhost:61001" + // cambiar si aplica para porduccion */
        "/ws/tournament_pong/" +
        gameid +
        "&" + // cambiar con uuid para cada partida */
        data.mainUserData.user_name +
        "/" // cambiar con uuid para cada partida */
    );

    finalsocket.addEventListener("message", function (event) {
      const response = JSON.parse(event.data);
      console.log(finalsocket);
      console.log(response);
      if (response.type == "playerNames") {
        console.log("response: ", response);
        player_1 = response.player1;
        player_2 = response.player2;
      } else if (response.type == "stateUpdate") {
        console.log("response: ", response);
        esfera.position.z = response.objects.ball_y;
        esfera.position.x = response.objects.ball_x;
        cube.position.z = response.objects.p1_y;
        cube2.position.z = response.objects.p2_y;
        renderer.render(scene, camera);
        score_1 = response.objects.score_1;
        score_2 = response.objects.score_2;
        player_1 = response.objects.player1;
        player_2 = response.objects.player2;
      } else if (response.type == "playerId") {
        playerId = response.playerId;
      } else if ((response.type = "finish_game")) {
        finalsocket.close();
        finalOn = false;
        if (score_1 > score_2) {
          winner = player_1;
        } else if (score_1 < score_2) {
          winner = player_2;
        }
        socket.send(
          JSON.stringify({
            user_name: data.mainUserData.user_name,
            type: "finalResult",
            game_id: gameID,
            tournamentCode: tournamentCode,
            winner: winner,
          })
        );
      }
    });

    window.addEventListener("keydown", function (event) {
      if (event.key === "ArrowDown") {
        // key code for the arrow down key
        const message = {
          playerId: playerId,
          type: "up",
        };
        finalsocket.send(JSON.stringify(message));
        console.log("up");
      } else if (event.key === "ArrowUp") {
        // key code for the arrow down key
        const message = {
          playerId: playerId,
          type: "down",
        };
        finalsocket.send(JSON.stringify(message));
      } else if (event.key === 32) {
        // key code for the space
        const message = {
          playerId: sessionStorage.getItem("playerId"),
          type: "puase",
        };
        finalsocket.send(JSON.stringify(message));
      }
    });
  }

  async function matchfound(gameid) {
    let mfound: boolean;
    mfound = true;
    // await getRivalData(rivalUserName);
    await delay(700);
    await countdown();
    gameOn = true;
    const windowWidth = 800;
    const windowHeight = 500;

    await delay(1000);
    renderer = new THREE.WebGLRenderer();
    renderer.setClearColor(0x000000, 0); // Fondo transparente
    renderer.setSize(windowWidth, windowHeight);
    document
      .getElementById("canvas-container")
      .appendChild(renderer.domElement);
    renderer.render(scene, camera);

    const game1socket = new WebSocket(
      "ws://" +
        "localhost:61001" + // cambiar si aplica para porduccion */
        "/ws/tournament_pong/" +
        gameid +
        "&" + // cambiar con uuid para cada partida */
        data.mainUserData.user_name +
        "/" // cambiar con uuid para cada partida */
    );

    game1socket.addEventListener("message", function (event) {
      const response = JSON.parse(event.data);
      console.log(game1socket);
      console.log(response);
      if (response.type == "playerNames") {
        console.log("response: ", response);
        player_1 = response.player1;
        player_2 = response.player2;
      } else if (response.type == "stateUpdate") {
        console.log("response: ", response);
        esfera.position.z = response.objects.ball_y;
        esfera.position.x = response.objects.ball_x;
        cube.position.z = response.objects.p1_y;
        cube2.position.z = response.objects.p2_y;
        renderer.render(scene, camera);
        score_1 = response.objects.score_1;
        score_2 = response.objects.score_2;
        player_1 = response.objects.player1;
        player_2 = response.objects.player2;
      } else if (response.type == "playerId") {
        playerId = response.playerId;
      } else if ((response.type = "finish_game")) {
        game1socket.close();
        gameOn = false;
        // if (score_1 > score_2) {
        //   winner = player_1;
        // } else if (score_1 < score_2) {
        //   winner = player_2;
        // }
        winner = response.winner;
        socket.send(
          JSON.stringify({
            user_name: data.mainUserData.user_name,
            type: "gameResult",
            game_id: gameID,
            tournamentCode: tournamentCode,
            winner: winner,
          })
        );
      }
    });

    window.addEventListener("keydown", async function (event) {
      if (event.key === "ArrowDown") {
        // key code for the arrow down key
        const message = {
          playerId: playerId,
          type: "up",
        };
        await game1socket.send(JSON.stringify(message));
        console.log("up");
      } else if (event.key === "ArrowUp") {
        // key code for the arrow down key
        const message = {
          playerId: playerId,
          type: "down",
        };
        await game1socket.send(JSON.stringify(message));
      } else if (event.key === 32) {
        // key code for the space
        const message = {
          playerId: sessionStorage.getItem("playerId"),
          type: "puase",
        };
        await game1socket.send(JSON.stringify(message));
      }
    });
  }

  onMount(async () => {
    gameOn = false;
    finalOn = false;
    delay(1000);
    socket = new WebSocket(
      "ws://" +
        "localhost:61001" + // cambiar si aplica para porduccion
        "/ws/tournament/" +
        data.mainUserData.user_name +
        "/" // cambiar con uuid para cada partida
    );
    socket.onopen = () => {};
    socket.onmessage = (event) => {
      console.log("event.data: ");
      console.log(event.data);
      const resdata = JSON.parse(event.data);
      if (resdata.type === "tournamentPlayers") {
        getTournamentPlayers(resdata);
      }
      if (resdata.type === "gameStart") {
        console.log("resdata.gameid: ");
        console.log(resdata.gameid);
        matchfound(resdata.gameid);
        gameOn = false;
      }
      if (resdata.type === "phaseTwo") {
        roundTwo(resdata);
      }
      if (resdata.type === "finalStart") {
        finalGameFunc(resdata.gameid);
      }
      if (resdata.type === "phaseThree") {
        roundThree(resdata);
      }
      if (resdata.type === "tournamentExit") {
        window.location.href = "/tournament";
      }
    };
  });
</script>

<dialog id="countermodal" class="modal">
  {#if foundtext}
    {#if winner1.user_name}
      <p class="font-bold mb-14 font-mono text-8xl text-center mt-16">
        {localize("second_round", language)}
      </p>
    {:else}
      <p class="font-bold mb-14 font-mono text-8xl text-center mt-16">
        {localize("starting_tournament", language)}
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
      <button on:click={endTournament} class="btn w-44 h-20 btn-primary"
        >{localize("back", language)}</button
      >
    </div>
  </li>
</dialog>

{#if gameOn == false && finalOn == false}
  <h1 class="font-bold text-5xl text-center mt-16">
    {localize("tournament", language)}
  </h1>

  {#if tempPlayers.length == 0}
    <div class="flex h-screen items-center justify-center -mt-36">
      <div
        class="flex flex-col gap-4 p-7 backdrop-blur-sm bg-white/10 rounded-xl w-72"
      >
        <button class="btn btn-primary" onclick="createModal.showModal()"
          >{localize("create_tournament", language)}</button
        >
        <dialog id="createModal" class="modal">
          <div class="modal-box">
            <h3 class="font-bold text-lg">
              {localize("create_tournament", language)}
            </h3>
            <form
              class=""
              method="POST"
              on:submit|preventDefault={createTournament}
            >
              <label class="input mt-6 input-bordered flex items-center gap-2">
                <input
                  type="text"
                  class="grow"
                  placeholder="Tournament Code"
                  name="code"
                  id="code"
                  bind:value={tournamentCode}
                />
              </label>
              <button class="mt-5 btn btn-success"
                >{localize("submit", language)}</button
              >
            </form>
            <div class="modal-action">
              <form method="dialog">
                <button class="btn">{localize("cancel", language)}</button>
              </form>
            </div>
          </div>
        </dialog>

        <button class="btn btn-primary" onclick="joinModal.showModal()"
          >{localize("join_tournament", language)}</button
        >
        <dialog id="joinModal" class="modal">
          <div class="modal-box">
            <h3 class="font-bold text-lg">
              {localize("join_tournament", language)}
            </h3>
            <form
              class=""
              method="POST"
              on:submit|preventDefault={joinTournament}
            >
              <label class="input mt-6 input-bordered flex items-center gap-2">
                <input
                  type="text"
                  class="grow"
                  placeholder="Tournament Code"
                  name="code"
                  id="code"
                  bind:value={tournamentCode}
                />
              </label>
              <button class="mt-5 btn btn-success"
                >{localize("submit", language)}</button
              >
            </form>
            <div class="modal-action">
              <form method="dialog">
                <button class="btn">{localize("cancel", language)}</button>
              </form>
            </div>
          </div>
        </dialog>
      </div>
    </div>
  {:else}
    <div class="flex mr-3 mt-16">
      <ol class="flex flex-1 flex-col justify-around mr-5 ml-5 round">
        {#if thisPlayers[0]}
          <li
            id="round-2"
            class={thisPlayers[0].winner == "true"
              ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
              : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
          >
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img src={thisPlayers[0].avatar_fileName} />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {thisPlayers[0].user_name}
            </p>
            <div class="flex-grow" />
          </li>
        {:else}
          <li
            id="round-2"
            class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
          >
            <div
              class="absolute border-transparent h-24 w-24 z-50 animate-spin rounded-full border-4 border-t-primary"
            />
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img
                  src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
                />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {localize("awaiting_player", language)}
            </p>
            <div class="flex-grow" />
          </li>
        {/if}
        {#if thisPlayers[1]}
          <li
            id="round-2"
            class={thisPlayers[1].winner == "true"
              ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
              : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
          >
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img src={thisPlayers[1].avatar_fileName} />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {thisPlayers[1].user_name}
            </p>
            <div class="flex-grow" />
          </li>
        {:else}
          <li
            id="round-2"
            class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
          >
            <div
              class="absolute border-transparent h-24 w-24 z-50 animate-spin rounded-full border-4 border-t-primary"
            />
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img
                  src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
                />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {localize("awaiting_player", language)}
            </p>
            <div class="flex-grow" />
          </li>
        {/if}
        {#if thisPlayers[2]}
          <li
            id="round-2"
            class={thisPlayers[2].winner == "true"
              ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
              : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
          >
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img src={thisPlayers[2].avatar_fileName} />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {thisPlayers[2].user_name}
            </p>
            <div class="flex-grow" />
          </li>
        {:else}
          <li
            id="round-2"
            class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
          >
            <div
              class="absolute border-transparent h-24 w-24 z-50 animate-spin rounded-full border-4 border-t-primary"
            />
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img
                  src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
                />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {localize("awaiting_player", language)}
            </p>
            <div class="flex-grow" />
          </li>
        {/if}
        {#if thisPlayers[3]}
          <li
            id="round-2"
            class={thisPlayers[3].winner == "true"
              ? "flex gap-4 items-center m-2 p-1 leading-relaxed win rounded-full relative with-connector"
              : "flex gap-4 items-center m-2 p-1 leading-relaxed loose rounded-full relative with-connector"}
          >
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img src={thisPlayers[3].avatar_fileName} />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {thisPlayers[3].user_name}
            </p>
            <div class="flex-grow" />
          </li>
        {:else}
          <li
            id="round-2"
            class="flex gap-4 items-center m-2 p-1 leading-relaxed bg-slate-950 text-gray-300 rounded-full relative with-connector"
          >
            <div
              class="absolute border-transparent h-24 w-24 z-50 animate-spin rounded-full border-4 border-t-primary"
            />
            <div class="avatar inline-block">
              <div class="w-24  rounded-full">
                <img
                  src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
                />
              </div>
            </div>
            <p class="font-bold text-2xl ml-3 mr-3">
              {localize("awaiting_player", language)}
            </p>
            <div class="flex-grow" />
          </li>
        {/if}
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
    <h1 class="mt-10 text-center">
      <span class="text-3xl font-bold"
        >{localize("code", language)}: "{tournamentCode}"
      </span>
    </h1>
  {/if}
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
