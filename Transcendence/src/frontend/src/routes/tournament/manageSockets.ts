export function handleKeyDown(event, socket, playerId, up, down) {
    if (event.key === down) {
        const message = {
            playerId: playerId,
            type: 'up',
        };
        socket.send(JSON.stringify(message));
    } else if (event.key === up) {
        const message = {
            playerId: playerId,
            type: 'down',
        };
        socket.send(JSON.stringify(message));
    } else if (event.key === ' ') { // código de tecla para el espacio
        const message = {
            playerId: sessionStorage.getItem('playerId'),
            type: 'pause',
        };
        socket.send(JSON.stringify(message));
    }
}

export function newSocket(uuid)
{
    return new WebSocket(
        'ws://'
        + 'localhost:61001' // cambiar si aplica para porduccion
        + '/ws/game/'
        + uuid + '/'
    )
}

export async function saveGame(uuid, player1, player2, player1_result, player2_result, mode) {
	const response = await fetch("/api/pong/saveMatchData/", {
		method: "POST",
		headers: { "Content-Type": "application/json" },
		body: JSON.stringify({
			player1: player1,
			player2: player2,
			player1_result: player1_result,
			player2_result: player2_result,
			mode: mode,
			uuid: uuid
		}),
	});
	const responseBody = await response.json();
	if (responseBody.error) {
		return false;
	}
	return true;
}
