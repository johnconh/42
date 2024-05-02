<script>
    import {localizationDict, localize} from '../../../localization/localize.js'
	/* export let games_lenght; */
	export let numBlocks;
	export let index;
	export let language;
	const selected = "px-2 py-1 text-sm text-blue-500 rounded-md dark:bg-gray-800 bg-blue-100/60"
	const normal = "px-2 py-1 text-sm text-gray-500 rounded-md dark:hover:bg-gray-800 dark:text-gray-300 hover:bg-gray-100"
	const numbers = Array.from({ length: numBlocks }, (_, index) => index);
	console.log(numbers)

	function manageIndexButton(e) {
		index = e.target.text - 1
	}

	function pressNext(e)
	{
		if (index + 1 <= numBlocks - 1)
			index += 1
	}

	function pressPrevious(e)
	{
		if (index - 1 >= 0)
			index -= 1;
	}

</script>

<div class="flex items-center justify-between mt-6">
	<a
		href="#"
		class="flex items-center px-5 py-2 text-sm text-gray-700 capitalize transition-colors duration-200 bg-white border rounded-md gap-x-2 hover:bg-gray-100 dark:bg-gray-900 dark:text-gray-200 dark:border-gray-700 dark:hover:bg-gray-800"
		on:click|preventDefault={pressPrevious}
	>
		<svg
			xmlns="http://www.w3.org/2000/svg"
			fill="none"
			viewBox="0 0 24 24"
			stroke-width="1.5"
			stroke="currentColor"
			class="w-5 h-5 rtl:-scale-x-100"
		>
			<path
				stroke-linecap="round"
				stroke-linejoin="round"
				d="M6.75 15.75L3 12m0 0l3.75-3.75M3 12h18"
			/>
		</svg>

		<span> {localize('previous', language)} </span>
	</a>

	<div class="items-center hidden md:flex gap-x-3">
		{#each numbers as number}
			{#if number == index}
			<a
				href="#"
				class="px-2 py-1 text-sm text-blue-500 rounded-md dark:bg-gray-800 bg-blue-100/60"
				on:click|preventDefault={manageIndexButton}
			>{number + 1}</a
			>
			{:else}
			<a
				href="#"
				class="px-2 py-1 text-sm text-gray-500 rounded-md dark:hover:bg-gray-800 dark:text-gray-300 hover:bg-gray-100"
				on:click|preventDefault={manageIndexButton}
			>{number + 1}</a
			>
			{/if}
		{/each}
	</div>

	<a
		href="#"
		class="flex items-center px-5 py-2 text-sm text-gray-700 capitalize transition-colors duration-200 bg-white border rounded-md gap-x-2 hover:bg-gray-100 dark:bg-gray-900 dark:text-gray-200 dark:border-gray-700 dark:hover:bg-gray-800"
		on:click|preventDefault={pressNext}
	>
		<span> {localize('next', language)} </span>

		<svg
			xmlns="http://www.w3.org/2000/svg"
			fill="none"
			viewBox="0 0 24 24"
			stroke-width="1.5"
			stroke="currentColor"
			class="w-5 h-5 rtl:-scale-x-100"
		>
			<path
				stroke-linecap="round"
				stroke-linejoin="round"
				d="M17.25 8.25L21 12m0 0l-3.75 3.75M21 12H3"
			/>
		</svg>
	</a>
</div>
