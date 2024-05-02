import { json } from '@sveltejs/kit'
import type { RequestHandler } from './$types'

let avatar = ''

export const POST: RequestHandler = async ({ cookies, request }) => {
  const data = await request.json()
  const user_name = data.user_name
  const response = await fetch('http://backend:61001/accounts/username/', {
    method: 'POST',
    headers: {
      Accept: '*/*',
      'Content-Type': '*/*',
    },
    body: JSON.stringify({
      user_name: user_name,
    }),
  })
  const responseBody = await response.json()
  avatar = responseBody.avatar
  const slice = avatar.split('/')
  const avatarName = slice[slice.length - 1]
  responseBody.avatar_fileName = 'https://localhost:443/media/' + avatarName
  return json(responseBody)
}
