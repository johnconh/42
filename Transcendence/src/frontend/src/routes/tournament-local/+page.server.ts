import type { PageServerLoad } from './$types'
import type { Actions } from './$types'
import { redirect } from '@sveltejs/kit'

let avatar = ''

export const load: PageServerLoad = async ({ cookies }) => {
  if (!cookies.get('token')) {
    redirect(302, '/login')
  } else {
    const tokenVerify = await fetch('http://backend:61001/accounts/session/', {
      method: 'GET',
      headers: {
        Accept: '*/*',
        'Content-Type': '*/*',
        Authorization: `Bearer ${cookies.get('token')}`,
      },
    })
    const tokenRes = await tokenVerify.json()
    if (!tokenRes.isAuthenticated === true) {
      const tokenRefresh = await fetch('http://backend:61001/accounts/token-refresh/', {
        method: 'POST',
        headers: {
          Accept: '*/*',
          'Content-Type': '*/*',
        },
        body: JSON.stringify({
          refresh: cookies.get('refresh'),
        }),
      })
      console.log('tokenRefresh')
      console.log(tokenRefresh)
      const tokenRefreshRes = await tokenRefresh.json()
      console.log('tokenRefreshRes')
      console.log(tokenRefreshRes)
      if (tokenRefreshRes.code === 'token_not_valid') {
        console.log('tokenRefreshRes.isAuthenticated === false')
        redirect(302, '/logout')
      } else {
        cookies.set('token', tokenRefreshRes.access, {
          path: '/',
          httpOnly: true,
          sameSite: 'strict',
          maxAge: 60 * 60 * 24 * 1000,
          secure: false,
        })
        cookies.set('refresh', tokenRefreshRes.refresh, {
          path: '/',
          httpOnly: true,
          sameSite: 'strict',
          maxAge: 60 * 60 * 24 * 1000,
          secure: false,
        })
      }
    }
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
  // json.avatar_fileName = "https://0.0.0.0:443/media/" + json.avatar_fileName;
  json.avatar_fileName = 'https://localhost/media/' + json.avatar_fileName
  return {
    mainUserData: json,
  }
}
