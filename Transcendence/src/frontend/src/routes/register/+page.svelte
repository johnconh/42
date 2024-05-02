<script lang="ts">
	import type { ActionData } from "./$types";
    import {localizationDict, localize} from '../../localization/localize.js'
	export let form: ActionData;
	export let data;
	let language = data.mainUserData ? data.mainUserData.lang : 'en';	
	let emailErr = form?.error.email;
	let usernameErr = form?.error.user_name;
	let passwordErr = form?.error.password;
	let password2Err = form?.error.password2;
	let birthdateErr = form?.error.birthdate;
	let isLoading = false;
	function ftlogin() {
		isLoading = true;
		window.location.href = "http://0.0.0.0:61001/auth/login42/";
	}
</script>

<div class="flex flex-col h-screen items-center justify-center -mt-16">
	<div class="p-7 backdrop-blur-sm bg-white/10 rounded-xl mt-7">
		<h1 class="text-2xl font-bold mb-6">{localize('register', language)}</h1>
		<form class="flex flex-col gap-4" method="POST">
			<div class="flex flex-row gap-5">
				<label class="flex flex-col" for="first_name">
					{localize('first_name', language)}
					<input
						class="p-2 text-gray-400 border rounded-xl"
						required
						type="text"
						name="first_name"
					/>
				</label>
				<label class="flex flex-col" for="last_name">
					{localize('last_name', language)}
					<input
						class="p-2 text-gray-400 border rounded-xl"
						required
						type="text"
						name="last_name"
					/>
				</label>
			</div>
			<label class="flex flex-col" for="user_name">
				{localize('username', language)}
				<input
					class="p-2 text-gray-400 border rounded-xl"
					required
					type="text"
					name="user_name"
				/>
				{#if usernameErr}
					<p class="text-red-500">{usernameErr}</p>
				{/if}
			</label>
			<label class="flex flex-col" for="email">
				Email:
				<input
					class="p-2 text-gray-400 border rounded-xl"
					required
					type="email"
					name="email"
				/>
				{#if emailErr}
					<p class="text-red-500">{emailErr}</p>
				{/if}
			</label>
			<label class="flex flex-col" for="birthdate">
				{localize('birthdate', language)}
				<input
					class="p-2 text-gray-400 border rounded-xl"
					required
					type="date"
					name="birthdate"
				/>
				{#if birthdateErr}
					<p class="text-red-500">{birthdateErr}</p>
				{/if}
			</label>
			<div class="flex flex-row gap-5">
				<label class="flex flex-col" for="password">
					{localize('password', language)}
					<input
						class="p-2 text-gray-400 border rounded-xl"
						required
						type="password"
						name="password"
					/>
					{#if passwordErr}
						<p class="text-red-500 text-wrap max-w-44">{passwordErr}</p>
					{/if}
				</label>
				<label class="flex flex-col" for="password2">
					{localize('repeat_password', language)}
					<input
						class="p-2 text-gray-400 border rounded-xl"
						required
						type="password"
						name="password2"
					/>
					{#if password2Err}
						<p class="text-red-500 text-wrap max-w-44">{password2Err}</p>
					{/if}
				</label>
			</div>
			<button
					formaction="?/default_register"
				class="p-2.5 btn btn-primary border-none text-white cursor-pointer rounded-xl"
				type="submit"
			>
				{localize('register', language)}
			</button>
		</form>
		{#if !isLoading}
			<form method="POST">
				<button
					formaction="?/login_42"
					type="submit"
					class="w-full p-2.5 btn mt-5 btn-primary border-none text-white cursor-pointer rounded-xl"
				>{localize('register_with', language)}
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
			{localize('already_registered', language)} <a class="text-primary" href="/login">{localize('login', language)}</a>
		</p>
	</div>
</div>
