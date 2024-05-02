<script lang="ts">
	import type { ActionData } from "./$types";
	import { onMount } from "svelte";
    import {localizationDict, localize} from '../../localization/localize.js'

	let isLoading = false;
	export let form: ActionData;

	export let data;
	let language = data.mainUserData ? data.mainUserData.lang : 'en';


	onMount(() => {
		if (form?.error == "2FA") twofamodal.showModal();
		if (form?.type == "tfacode") twofamodal.showModal();
	});
	function ftlogin() {
		isLoading = true;
		window.location.href = "http://0.0.0.0:61001/auth/login42/";
	}
</script>

<div class="flex flex-col h-screen items-center justify-center -mt-16">
	<div class="p-7 backdrop-blur-sm bg-white/10 rounded-xl w-72">
		<h1 class="text-2xl font-bold mb-6">{localize('login', language)}</h1>
		<form class="flex flex-col gap-4" method="POST">
			<label class="flex flex-col" for="user_name">
				{localize('username', language)}:
				<input
					class="p-2 text-gray-400 border rounded-xl"
					required
					type="text"
					name="user_name"
					id="user_name"
				/>
				{#if form?.type == "username"}
					<p class="text-red-500 w-fit">{form.error}</p>
				{/if}
			</label>

			<label class="flex flex-col" for="password">
				{localize('password', language)}:
				<input
					class="p-2 text-gray-400 border rounded-xl"
					required
					type="password"
					name="password"
					id="password"
				/>
				{#if form?.type == "password"}
					<p class="text-red-500 w-fit">{form.error}</p>
				{/if}
			</label>

			<button
				type="submit"
				class="p-2.5 btn btn-primary border-none text-white cursor-pointer rounded-xl"
				formaction="?/default_login">{localize('login', language)}</button
		>
		</form>
		{#if !isLoading}
			<form method="POST">
				<button
					formaction="?/login_42"
					type="submit"
					class="w-full p-2.5 btn mt-5 btn-primary border-none text-white cursor-pointer rounded-xl"
				>{localize('login_with', language)}
					<svg
						class="w-6 h-6 inline-block"
						version="1.1"
						id="Calque_1"
						sodipodi:docname="42_logo.svg"
						inkscape:version="0.48.2 r9819"
						xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
						xmlns:svg="http://www.w3.org/2000/svg"
						xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd"
						xmlns:dc="http://purl.org/dc/elements/1.1/"
						xmlns:cc="http://creativecommons.org/ns#"
						xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape"
						xmlns="http://www.w3.org/2000/svg"
						xmlns:xlink="http://www.w3.org/1999/xlink"
						x="0px"
						y="0px"
						viewBox="0 -200 960 960"
						enable-background="new 0 -200 960 960"
						xml:space="preserve"
					>
						<polygon
							id="polygon5"
							points="32,412.6 362.1,412.6 362.1,578 526.8,578 526.8,279.1 197.3,279.1 526.8,-51.1 362.1,-51.1
							32,279.1 "
						/>
						<polygon
							id="polygon7"
							points="597.9,114.2 762.7,-51.1 597.9,-51.1 "
						/>
						<polygon
							id="polygon9"
							points="762.7,114.2 597.9,279.1 597.9,443.9 762.7,443.9 762.7,279.1 928,114.2 928,-51.1 762.7,-51.1 "
						/>
						<polygon id="polygon11" points="928,279.1 762.7,443.9 928,443.9 " />
					</svg>
				</button>
			</form>
		{:else}
			<button
				disabled="disabled"
				class="w-full p-2.5 btn mt-5 btn-primary border-none text-white cursor-pointer rounded-xl"
			>
				<span class="loading loading-spinner" />
				{localize('loading', language)}
			</button>
		{/if}
	</div>
	<div class="mt-3 text-center">
		<p>
			{localize('forgot', language)}<a class="text-primary" href="/pswrd-reset"
			>{localize('here', language)}</a
		>{localize('reset', language)}
		</p>
	</div>
	<dialog id="twofamodal" class="modal">
		<div class="modal-box">
			<h3 class="font-bold text-lg">{localize('twofactor', language)}</h3>
			<form class="mt-6 flex flex-col gap-4" method="POST" action="?/twofa_login">
				<label class="input input-bordered flex items-center gap-2">
					<svg
						xmlns="http://www.w3.org/2000/svg"
						viewBox="0 0 16 16"
						fill="currentColor"
						class="w-4 h-4 opacity-70"
					><path
							d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z"
						/></svg
				>
					<input
						type="text"
						class="grow"
						placeholder="2FA Code"
						name="code"
						id="code"
					/>
				</label>
				<button class="btn btn-success">{localize('submit', language)}</button>
				{#if form?.type == "tfacode"}
					<p class="text-red-500 text-wrap w-fit">{form?.error}</p>
				{/if}
				<div class="modal-action">
					<form method="dialog">
						<button class="btn"
						>{localize('cancel', language)}</button
					>
					</form>
				</div>
			</form>
		</div>
	</dialog>
</div>
