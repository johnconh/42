// @ts-nocheck
import type { PageServerLoad } from './$types'
import type { Actions } from './$types'
import { redirect } from '@sveltejs/kit'

let avatar = ''

export const load = async ({ cookies }: Parameters<PageServerLoad>[0]) => {
  if (!cookies.get('token')) {
    redirect(302, '/login')
  }
  const mainUserData = await fetch('http://backend:61001/accounts/profile-data/', {
    method: 'POST',
    headers: {
      Accept: '*/*',
      'Content-Type': '*/*',
      Authorization: `Bearer ${cookies.get('token')}`,
    },
  })
  const json = await mainUserData.json()
  json.avatar_fileName = 'https://localhost/media/' + json.avatar_fileName
  return {
    mainUserData: json,
  }
}
