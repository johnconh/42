<script lang="ts">
  import logo from "../lib/images/logo.png";
  import { localizationDict, localize } from "../localization/localize.js";
  //   import 'bootstrap/dist/css/bootstrap.min.css';

  export let data;
  let language = data.mainUserData ? data.mainUserData.lang : "en";

  function showTournamentModal() {
    tournamentModal.showModal();
  }
</script>

<dialog id="tournamentModal" class="modal">
    <div class="modal-action">
      <div class="flex flex-col bg-gray-700 p-20 rounded-xl">
        <h1 class="text-4xl text-accent text-center font-bold mb-12">{localize("tournament_option", language)}</h1>
        <div class="flex flex-row gap-10 justify-center">
          <a href="/tournament" class="btn btn-accent w-60 h-20 text-xl"
            >{localize("online_game", language)}</a
          >
          <a href="/tournament-local" class="btn btn-accent w-60 h-20 text-xl"
            >{localize("local_game", language)}</a
          >
        </div>
        <form class="flex items-center justify-center" method="dialog">
          <button class="btn mt-10 justify-center">{localize("close", language)}</button>
        </form>
      </div>
    </div>
</dialog>

<img src={logo} alt="Logo" class="mx-auto top-0 mt-6 size-4/12" />

<div class="flex flex-col gap-10 mt-10">
  <div class="flex flex-row gap-10 justify-center">
    <a href="/matchmaking" class="btn btn-primary w-60 h-20 text-xl"
      >{localize("online_game", language)}</a
    >
    <a href="/local" class="btn btn-primary w-60 h-20 text-xl"
      >{localize("local_game", language)}</a
    >
  </div>
  <div class="flex flex-row gap-10 justify-center">
    <a on:click={showTournamentModal} class="btn btn-primary w-60 h-20 text-xl"
      >{localize("tournament_option", language)}</a
    >
    <a href="/profile" class="btn btn-primary w-60 h-20 text-xl"
      >{localize("find_profile", language)}</a
    >
  </div>
  <div class="flex flex-row gap-10 justify-center">
    <a href="/manual" class="btn btn-primary w-60 h-20 text-xl">{localize('manual', language)}</a>
  </div>
</div>
