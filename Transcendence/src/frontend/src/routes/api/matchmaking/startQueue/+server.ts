import { json } from '@sveltejs/kit'
import type { RequestHandler } from './$types'

export const POST: RequestHandler = async ({ cookies, request }) => {
  const data = await request.json()
  const user_name = data.user_name
  const ratio = data.ratio
  const response = await fetch('http://backend:61001/matchmaking/matchmake/', {
    method: 'POST',
    headers: {
      Accept: '*/*',
      'Content-Type': '*/*',
      Authorization: `Bearer ${cookies.get('token')}`,
    },
    body: JSON.stringify({
      user_name: user_name,
      ratio: ratio,
    }),
  })
  const responseBody = await response.json()
  console.log(response.status)
  if (response.status === 200) {
    return json(responseBody)
  } else {
    return json({ error: 'Matchmaking failed' })
  }
}
