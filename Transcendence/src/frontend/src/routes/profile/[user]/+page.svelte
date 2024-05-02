<script lang="ts">
	import Game from './game.svelte'
	import GamesFooter from './gamesFooter.svelte'
  import {localizationDict, localize} from '../../../localization/localize.js'
	export let data;
  let language = data.mainUserData ? data.mainUserData.lang : 'en';
	const blockSize = 5;
	let numBlocks;
	let index = 0;
	let games = []
	if (data.games)
		numBlocks = Math.ceil(data.games.length / blockSize);
	console.log(data.games)
	$: {
		if (data.games)
			games = data.games.slice(index * 5, (index + 1) * 5)
	}
</script>


<div class="mt-10 flex flex-col items-center">
  <div class="avatar">
    <div
      class="w-48 rounded-full ring ring-primary ring-offset-base-100 ring-offset-2"
    >
      <img
        alt="avatar"
        src={data.userData.avatar_fileName}
      />
    </div>
  </div>
  <h1
    class="text-7xl font-bold text-transparent bg-clip-text bg-gradient-to-r from-indigo-500 to-cyan-700 text-center mt-8"
  >
    {data.userData.user_name}
  </h1>
</div>

<h2 class="text-2xl text-primary font-bold mt-8 ml-24">
  {localize('last_played', language)}
</h2>

<section class="container px-4 mt-4 mx-auto">
  <div class="flex flex-col">
    <div class="-mx-4 -my-2 overflow-x-auto sm:-mx-6 lg:-mx-8">
      <div class="inline-block min-w-full py-2 align-middle md:px-6 lg:px-8">
        <div
          class="overflow-hidden border border-gray-200 dark:border-gray-700 md:rounded-lg"
        >
          <table
            class="min-w-full divide-y divide-gray-200 dark:divide-gray-700"
          >
            <thead class="bg-gray-50 dark:bg-gray-800">
              <tr>
                <th
                  scope="col"
                  class="px-4 py-3.5 text-sm font-normal text-left rtl:text-right text-gray-500 dark:text-gray-400"
                >
                  {localize('date', language)}
                </th>

                <th
                  scope="col"
                  class="px-4 py-3.5 text-sm font-normal text-left rtl:text-right text-gray-500 dark:text-gray-400"
                >
                  {localize('status', language)}
                </th>

                <th
                  scope="col"
                  class="px-4 py-3.5 text-sm font-normal text-left rtl:text-right text-gray-500 dark:text-gray-400"
                >
                  {localize('oponent', language)}
                </th>
              </tr>
            </thead>
            <tbody
              class="bg-white divide-y divide-gray-200 dark:divide-gray-700 dark:bg-gray-900"
            >
				{#if games.length != 0}
					{#each games as game}
						<Game
							game_date={game.game_date}
							game_status={game.game_status}
							username={game.rival_username}
							email={game.rival_email}
							photo={game.rival_photo}
						/>
					{/each}
				{:else}
					<tr class="whitespace-nowrap">
						<td colspan="3" class="px-4 py-3.5 text-sm font-normal text-left rtl:text-right text-gray-500 dark:text-gray-400 text-center">
							<strong>{data.userData.user_name}</strong> {localize('not_played', language)}
						</td>
					</tr>
				{/if}
            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>

  <GamesFooter language={language} numBlocks={numBlocks} bind:index={index} />

</section>
