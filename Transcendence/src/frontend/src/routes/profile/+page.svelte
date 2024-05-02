<script lang="ts">
  import "../../app.css";
  import { onMount } from "svelte";
  export let form: ActionData;
  import {localizationDict, localize} from '../../localization/localize.js'

  export let data;
	let language = data.mainUserData ? data.mainUserData.lang : 'en';
</script>

<main class="flex flex-col h-screen items-center justify-center -mt-16">
  <div class="p-7 backdrop-blur-sm bg-white/10 rounded-xl">
    <h1 class="text-2xl font-bold mb-5 text-center">{localize('find_player', language)}</h1>
    <form class="flex flex-col gap-4" method="POST">
      <label class="" for="user_name" />
      <input
        required
        type="text"
        name="user_name"
        id="user_name"
        class="p-2 rounded border border-gray-300 text-gray-500"
      />
      {#if form?.error == "user_name"}
        <p class="text-red-500 text-wrap w-fit">{localize('invalid_username', language)}</p>
      {/if}
      <button
        type="submit"
        class="p-2.5 btn btn-primary border-none text-white cursor-pointer rounded-xl"
        >{localize('find', language)}</button
      >
    </form>
  </div>
</main>
