<script>
    import { browser } from '$app/environment'; 
    import { onMount } from 'svelte';

    let renderer;
	let playerId;
	let container;
	let player_1, player_2;
	let score_1 = 0, score_2 = 0;
	let game_ended = false;
	let modal;
	let gameID;

    onMount(() => {
		const web1 = 'wss://localhost:443/ws/game/123/'
        const socket = new WebSocket(web1);

		socket.addEventListener('message', function (event) {
			const response = JSON.parse(event.data);
			console.log(response)
			/* if (response.type == "stateUpdate") */
			/* { */
			/* } */
			if (response.type == "playerId")
				console.log(response);
		});
	});



</script>

<h1>hola</h1>
