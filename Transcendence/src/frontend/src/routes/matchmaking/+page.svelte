<script lang="ts">
  import { onMount } from "svelte";
  import { bind } from "svelte/internal";
  import { get } from "svelte/store";
  import {localizationDict, localize} from '../../localization/localize.js'

  export let data;
  let socket;
  let language = data.mainUserData ? data.mainUserData.lang : 'en';
  let isLoading = false;
  let mfound = false;
  let foundtext = false;
  let position = 0; // posición inicial de la foto
  let position2 = 0; // posición inicial de la foto
  let counter = 6;
  let ratio = 0;
  let RivalData = {};
  let rivalUserName = "";
  let gameid = "";

  function matchmake() {
    const user_name = data.mainUserData.user_name;
    const type = "findMatch";
    const sendData = JSON.stringify({ user_name, ratio, type });
    socket.send(sendData);
  }

  onMount(() => {
    socket = new WebSocket("ws://localhost:61001/ws/matchmaking_skt/");
    socket.onopen = () => {
    };
    socket.onmessage = (event) => {
      const resdata = JSON.parse(event.data);
      rivalUserName = resdata.opponent;
      gameid = resdata.gameId;
      matchfound();
    };
  });

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

  async function ratioFunc() {
    const response = await fetch("/api/matchmaking/getRatio", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        user_name: data.mainUserData.user_name,
      }),
    });
    const responseBody = await response.json();
    ratio = responseBody.ratio;
  }

  function delay(ms: number) {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }

  async function cancelSearch() {
    isLoading = false;
    position += window.innerWidth * 0.3;
    position2 -= window.innerWidth * 0.3;
    const user_name = data.mainUserData.user_name;
    const type = "leaveQueue";
    const sendData = JSON.stringify({ user_name, ratio, type });
    socket.send(sendData);
  }

  async function getRatio() {
    isLoading = true;
    await delay(200);
    position -= window.innerWidth * 0.3;
    position2 += window.innerWidth * 0.3;
    await ratioFunc();
    matchmake();
  }

  async function countdown() {
    countermodal.showModal();
    foundtext = true;
    await delay(1000);
    foundtext = false;
    while (counter > 0) {
      counter--;
      await delay(1000);
    }
  }

  async function matchfound() {
    mfound = true;
    await getRivalData(rivalUserName);
    await delay(700);
    await countdown();
    window.location.href = "/pong/" + gameid;
  }
</script>

<h1 class="font-bold text-5xl text-center mt-16">Ultimate Pong Online</h1>

<dialog id="countermodal" class="modal">
  {#if foundtext}
    <p class="font-bold mb-14 font-mono text-8xl text-center mt-16">
      {localize('match_found', language)}
    </p>
  {:else}
    <span class="countdown font-mono font-bold text-8xl">
      <span style={`--value:${counter};`} />
    </span>
  {/if}
</dialog>

<div class="flex flex-col justify-center items-center h-screen -mt-52">
  <div
    class="z-10 transition-transform transform duration-1000  absolute avatar flex flex-col"
    style="transform: translateX({position}px);"
  >
    <div
      class="w-64 rounded-full ring ring-primary ring-offset-base-100 ring-offset-2"
    >
      <img alt="avatar" src={data.mainUserData.avatar_fileName} />
    </div>
    <p
      class="text-white text-center mt-5 font-bold text-2xl bg-black/15 rounded-xl"
    >
      {data.mainUserData.user_name}
    </p>
  </div>
  <div
    class="z-10 transition-transform transform duration-1000  absolute avatar flex flex-col"
    style="transform: translateX({position2}px);"
    class:hidden={!isLoading}
  >
    <div
      class="w-64 rounded-full ring ring-primary ring-offset-base-100 ring-offset-2"
    >
      <div
        class="absolute border-transparent h-64 w-64 animate-spin rounded-full border-4 border-t-primary"
        class:hidden={mfound}
      />
      {#if !mfound}
        <img
          alt="avatar"
          src="https://i.pinimg.com/550x/57/70/f0/5770f01a32c3c53e90ecda61483ccb08.jpg"
        />
      {:else}
        <img alt="avatar" src={RivalData.avatar_fileName} />
      {/if}
    </div>
    {#if !mfound}
      <p
        class="text-white text-center mt-5 font-bold text-2xl bg-black/15 rounded-xl"
      >
        {"??"}
      </p>
    {:else}
      <p
        class="text-white text-center mt-5 font-bold text-2xl bg-black/15 rounded-xl"
      >
        {RivalData.user_name}
      </p>
    {/if}
  </div>
  <div class="flex flex-col gap-5 justify-center pt-96 mt-20">
    <button
      class="p-7 btn btn-primary border-none text-white font-bold text-xl cursor-pointer rounded-xl items-center h-auto"
      class:hidden={isLoading}
      on:click={getRatio}
      >{localize('find_match', language)}
    </button>
    <span class="h-[84px]" class:hidden={!isLoading} />

    <button
      disabled={true}
      class="p-7 btn btn-primary border-none text-white font-bold text-xl cursor-pointer rounded-xl items-center h-auto"
      class:hidden={!isLoading}
    >
      <span class="loading loading-spinner" />
      {localize('looking_for_game', language)}
    </button>
    <button
      disabled={mfound}
      class="p-7 w-full btn btn-error border-none text-white font-bold text-xl cursor-pointer rounded-xl items-center h-auto"
      class:hidden={!isLoading}
      on:click={cancelSearch}>{localize('cancel', language)}</button
    >
  </div>
</div>
