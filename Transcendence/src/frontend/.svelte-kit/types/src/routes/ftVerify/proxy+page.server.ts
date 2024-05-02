// @ts-nocheck
import { env } from '$env/dynamic/private'
import { redirect } from '@sveltejs/kit'
import type { PageServerLoad } from './$types'

export const load = async ({ cookies, url }: Parameters<PageServerLoad>[0]) => {
  const code = url.searchParams.get('code')
  const state = url.searchParams.get('state')

  const response = await fetch('http://backend:61001/auth/complete42/', {
    method: 'POST',
    headers: {
      Accept: '*/*',
      'Content-Type': '*/*',
    },
    body: JSON.stringify({
      code: code,
      state: state,
    }),
  })
  const json = await response.json()
  if (response.status === 200) {
    console.log(json.access_token)
    cookies.set('token', json.access_token, {
      path: '/',
      httpOnly: true,
      sameSite: 'strict',
      maxAge: 60 * 60 * 24 * 1000,
      secure: false,
    })
    cookies.set('refresh', json.refresh_token, {
      path: '/',
      httpOnly: true,
      sameSite: 'strict',
      maxAge: 60 * 60 * 24 * 1000,
      secure: false,
    })
    console.log('redirecting to: ')
    redirect(302, 'https://localhost/')
  } else {
    redirect(301, 'https://localhost/login')
  }
}
