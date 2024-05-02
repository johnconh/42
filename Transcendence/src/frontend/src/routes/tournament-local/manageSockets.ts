export function handleKeyDown(e, controller, socket, playerId) {
    if (controller[e.key]) {
      controller[e.key].pressed = true
    }
    movePaddle(controller, socket, playerId)
  }
  
  export function handleKeyUp(e, controller, socket, playerId) {
    if (controller[e.key]) {
      controller[e.key].pressed = false
    }
    movePaddle(controller, socket, playerId)
  }
  
  export function sendMessege(socket, playerId, direction) {
    const message = {
      playerId: playerId,
      type: direction,
    }
    socket.send(JSON.stringify(message))
  }
  
  export function movePaddle(controller, playerId) {
    Object.keys(controller).forEach(key => {
      if (controller[key].pressed)
        sendMessege(controller[key].socket, controller[key].playerId, controller[key].direction)
    })
  }
  
  export function newSocket(uuid) {
    return new WebSocket(
      'wss://' +
        'localhost' + // cambiar si aplica para porduccion
        '/ws/game/' +
        uuid +
        '&' + // cambiar con uuid para cada partida */
        'pepe' +
        '/', // cambiar con uuid para cada partida */
    )
  }
  
  export async function saveGame(uuid) {
    const response = await fetch('/api/pong/saveMatchData/', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({
        player1: 'jose1',
        player2: 'jose2',
        player1_result: 0,
        player2_result: 2,
        uuid: uuid,
      }),
    })
    const responseBody = await response.json()
    if (responseBody.error) {
      return false
    }
    return true
  }
  