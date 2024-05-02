// @ts-nocheck
import type { PageServerLoad } from './$types'
import { getWinners } from './lastGames.ts'
import { redirect } from '@sveltejs/kit'

let avatar = ''

export const load = async ({ cookies, url }: Parameters<PageServerLoad>[0]) => {
  const userName = url.href.split('/').pop()
  const response = await fetch('http://backend:61001/accounts/username/', {
    method: 'POST',
    headers: {
      Accept: '*/*',
      'Content-Type': '*/*',
    },
    body: JSON.stringify({
      user_name: userName,
    }),
  })
  const json = await response.json()
  /* console.log('json: ') */
  /* console.log(json) */
  /* json.avatar_fileName = "http://0.0.0.0:61001/media/" + json.avatar_fileName; */
  //   json.avatar_fileName = 'https://0.0.0.0:443/media/' + json.avatar_fileName
  json.avatar_fileName = 'https://localhost/media/' + json.avatar_fileName
  if (json.detail == 'Invalid Username') redirect(302, 'https://localhost/profile')

  const response2 = await fetch('http://backend:61001/pong/get-user-games/', {
    method: 'POST',
    headers: {
      Accept: '*/*',
      'Content-Type': '*/*',
    },
    body: JSON.stringify({
      user_name: userName,
    }),
  })
  let updateData
  const json2 = await response2.json()
  if (json2.error) updateData = null
  else updateData = await getWinners(json2, userName)
  /* console.log(updateData); */

  return {
    userData: json,
    games: updateData,
  }
}
