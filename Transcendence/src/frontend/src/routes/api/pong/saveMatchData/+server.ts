import { json } from '@sveltejs/kit'
import type { RequestHandler } from './$types'

let avatar = ''

export const POST: RequestHandler = async ({ cookies, request }) => {
  const data = await request.json()
  const response = await fetch('http://backend:61001/pong/save-match-data/', {
    method: 'POST',
    headers: {
      Accept: '*/*',
      'Content-Type': '*/*',
    },
    body: JSON.stringify({
      player1: data.player1,
      player2: data.player2,
      player1_result: data.player1_result,
      player2_result: data.player2_result,
      mode: data.mode,
      uuid: data.uuid,
    }),
  })
  const responseBody = await response.json()
  responseBody.avatar = 'https://localhost/media/' + responseBody.avatar
  return json(responseBody)
}
