<script lang="ts">
	import {localizationDict, localize} from '../../localization/localize.js'
	export let data;
	let language = data.mainUserData ? data.mainUserData.lang : 'en';
</script>

<div class="flex justify-center w-full">
	<h1 class="text-6xl font-bold p-10">{localize('game_manual', language)}</h1>
</div>
<div role="tablist" class="tabs tabs-lifted tabs-lg p-10">
	<input type="radio" name="my_tabs_2" role="tab" class="tab text-3xl" aria-label="{localize('local_game', language)}" checked />
	<div role="tabpanel" class="text-2xl tab-content border-base-300 rounded-box p-6">
		<div class="mb-3">{localize('press', language)} <kbd class="text-xl kbd kbd-sm">▲</kbd> {localize('to_move_paddle', language)} {localize('up', language)} <div class="badge badge-outline">P2</div></div>
		<div class="mb-3">{localize('press', language)} <kbd class="text-xl kbd kbd-sm">▼</kbd> {localize('to_move_paddle', language)} {localize('down', language)} <div class="badge badge-outline">P2</div></div>
		<div class="mb-3">{localize('press', language)} <kbd class="text-xl kbd kbd-sm">W</kbd> {localize('to_move_paddle', language)} {localize('up', language)} <div class="badge badge-outline">P1</div></div>
		<div class="mb-3">{localize('press', language)} <kbd class="text-xl kbd kbd-sm">S</kbd> {localize('to_move_paddle', language)} {localize('down', language)} <div class="badge badge-outline">P1</div></div>
	</div>
	<input type="radio" name="my_tabs_2" role="tab" class="tab text-3xl" aria-label="{localize('online_game', language)}"/>
	<div role="tabpanel" class="text-2xl tab-content border-base-300 rounded-box p-6">
		<div class="mb-3">{localize('press', language)} <kbd class="text-xl kbd kbd-sm">▲</kbd> {localize('to_move_paddle', language)} {localize('up', language)}</div>
		<div class="mb-3">{localize('press', language)} <kbd class="text-xl kbd kbd-sm">▼</kbd> {localize('to_move_paddle', language)} {localize('down', language)}</div>
	</div>
</div>