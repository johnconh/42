<script lang="ts">
  import "../App.css";
  import { onMount } from "svelte";
  import pong from "../lib/images/ping.svg";
  import {localizationDict, localize} from '../localization/localize.js'

  export let data;
  let language = data.mainUserData ? data.mainUserData.lang : 'en';
</script>

<nav data-sveltekit-reload>
  {#if !data.mainUserData}
    <div class="navbar bg-base-200">
      <div class="flex-1">
        <a href="/" class="btn btn-ghost text-xl">Ultimate PONG</a>
      </div>
      <div class="flex gap-3 items-center">
        <a
          href="/login"
          class="text-white
      btn btn-secondary px-4 py-2 rounded-lg">{localize('login', language)}</a
        >
        <a
          href="/register"
          class="text-white
      btn btn-secondary px-4 py-2 rounded-lg">{localize('register', language)}</a
        >
      </div>
    </div>
  {:else}
    <div class="navbar bg-base-200">
      <div class="flex-1">
        <a href="/" class="btn btn-ghost text-xl">Ultimate PONG</a>
      </div>
      <div class="flex-none gap-2">
        <p class="text-white">{localize('welcome', language)}, {data.mainUserData.user_name}</p>
        <div class="dropdown dropdown-end" />
        <div class="dropdown dropdown-end">
          <div
            tabindex="0"
            role="button"
            class="btn btn-ghost btn-circle avatar"
          >
            <div class="w-10 rounded-full">
              <img alt="avatar" src={data.mainUserData.avatar_fileName} />
            </div>
          </div>
          <ul
            tabindex="0"
            class="menu menu-sm dropdown-content mt-3 z-[1] p-2 shadow bg-base-100 rounded-box w-52"
          >
            <li>
              <a class="justify-between" href="/profile/{data.mainUserData.user_name}">
                {localize('profile', language)}
              </a>
            </li>
            <li><a href="/user-settings">{localize('settings', language)}</a></li>
            <li><a href="/logout">{localize('logout', language)}</a></li>
          </ul>
        </div>
      </div>
    </div>
  {/if}
</nav>

<div class="w-screen h-full">
  <slot />
  <img src={pong} alt="background" class="fixed left-0 top-10 w-full h-auto -z-10"/>
</div>
