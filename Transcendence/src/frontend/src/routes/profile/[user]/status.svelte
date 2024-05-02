<script>
	export let game_status;

	let color = "";
	let path_d = "";
	let text = ""
	$: {
		if (game_status == true)
		{
			color = "text-emerald-500 bg-emerald-100/60";
			path_d = "M10 3L4.5 8.5L2 6"
			text = "Won"
		}
		else
		{
			color = "text-red-500 bg-red-100/60";
			path_d = "M9 3L3 9M3 3L9 9"
			text = "Lost"
		}
	}
</script>

<div class="inline-flex items-center px-3 py-1 rounded-full gap-x-2 {color} dark:bg-gray-800">
	<svg
		width="12"
		height="12"
		viewBox="0 0 12 12"
		fill="none"
		xmlns="http://www.w3.org/2000/svg"
	>
		<path
			d={path_d}
			stroke="currentColor"
			stroke-width="1.5"
			stroke-linecap="round"
			stroke-linejoin="round"
		/>
	</svg>

	<h2 class="text-sm font-normal">{text}</h2>
</div>

