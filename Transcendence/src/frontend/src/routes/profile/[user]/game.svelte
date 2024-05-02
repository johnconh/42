<script>
	import GameStatus from './status.svelte'

	export let game_date;
	export let game_status;
	export let username;
	export let email;
	export let photo;
</script>

<tr>
	<td class="px-4 py-4 text-sm text-gray-500 dark:text-gray-300 whitespace-nowrap">{game_date}</td>
	<td class="px-4 py-4 text-sm font-medium text-gray-700 whitespace-nowrap">
		<GameStatus game_status={game_status} />
	</td>
	<td class="px-4 py-4 text-sm text-gray-500 dark:text-gray-300 whitespace-nowrap">
		<div class="flex items-center gap-x-2">
			<img
				class="object-cover w-8 h-8 rounded-full"
				src={photo}
				alt=""
			/>
			<div>
				<h2 class="text-sm font-medium text-gray-800 dark:text-white ">
					{username}
				</h2>
				<p class="text-xs font-normal text-gray-600 dark:text-gray-400">
					{email}
				</p>
			</div>
		</div>
	</td>
</tr>
