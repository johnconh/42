import type { PageServerLoad } from './$types'
import { fail, redirect } from '@sveltejs/kit'

export const load = (async () => {
  return {}
}) satisfies PageServerLoad

export const actions = {
  async default({ request }) {
    const data = await request.formData()
    const otp = data.get('otp')
    const response = await fetch('http://backend:61001/accounts/verify-email/', {
      method: 'POST',
      headers: {
        Accept: '*/*',
        'Content-Type': '*/*',
      },
      body: JSON.stringify({
        otp: otp,
      }),
    })
    const json = await response.json()
    console.log(json)
    if (response.status === 200) {
      console.log('json')
      redirect(302, '/')
    } else {
      return fail(response.status, {
        error: json,
      })
    }
  },
}
