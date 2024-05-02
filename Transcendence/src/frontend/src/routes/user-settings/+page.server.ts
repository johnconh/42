import { redirect } from '@sveltejs/kit'
import type { PageServerLoad } from './$types'
import { fail } from '@sveltejs/kit'

let userSettingsDataServ = {
	user_name: '',
	first_name: '',
	last_name: '',
	email: '',
	qrLink: '',
	qr_secret: '',
	secret: '',
}

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
		const userSettingsData = await fetch('http://backend:61001/accounts/profile-data/', {
			method: 'POST',
			headers: {
				Accept: '*/*',
				'Content-Type': '*/*',
				Authorization: `Bearer ${cookies.get('token')}`,
			},
		})
		const json = await userSettingsData.json()
		/* json.avatar_fileName = "http://0.0.0.0:61001/media/" + json.avatar_fileName; */
		json.avatar_fileName = 'https://localhost/media/' + json.avatar_fileName
		if (json.secret === null) {
			try {
				const response = await fetch('http://backend:61001/2fa/generate_qr/', {
					method: 'GET',
					headers: {
						Accept: '*/*',
						'Content-Type': '*/*',
						Authorization: 'Bearer ' + cookies.get('token'),
					},
				})
				const qrLink = await response.json()
				json.qrLink = qrLink.outpath_url
				json.qr_secret = qrLink.qr_secret
			} catch (error) {
				console.log(error)
			}
		}
		userSettingsDataServ = json
		return {
			userSettingsData: json,
		}
	}
}

export const actions = {
	profile_data: async ({ cookies, request }) => {
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
		const data = await request.formData()
		const new_first_name = data.get('new_first_name')
		const new_last_name = data.get('new_last_name')
		try {
			const response = await fetch('http://backend:61001/accounts/update-user/', {
				method: 'POST',
				headers: {
					Accept: '*/*',
					'Content-Type': '*/*',
					Authorization: `Bearer ${cookies.get('token')}`,
				},
				body: JSON.stringify({
					new_first_name: new_first_name,
					new_last_name: new_last_name,
				}),
			})
			const json = await response.json()
			console.log(json)
		} catch (error) {
			console.log(error)
		}
	},

	avatar: async ({ request, cookies }) => {
		try {
			const data = await request.formData()
			const new_avatar = data.get('new_avatar')

			const formData = new FormData()
			formData.append('new_avatar', new_avatar)
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
			const response = await fetch('http://backend:61001/accounts/update-avatar/', {
				method: 'POST',
				headers: {
					Authorization: `Bearer ${cookies.get('token')}`,
				},
				body: formData, // No uses JSON.stringify aquí
			})

			const json = await response.json()
			console.log('Respuesta del servidor:')
			console.log(json)
		} catch (error) {
			console.error('Error:', error)
		}
	},
	twofa: async ({ request, cookies }) => {
		const data = await request.formData()
		const code = data.get('code')
		console.log('userSettingsDataServ.qr_secret')
		console.log(code)
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
		try {
			const response = await fetch('http://backend:61001/2fa/verify_totp/', {
				method: 'POST',
				headers: {
					Accept: '*/*',
					'Content-Type': '*/*',
					Authorization: `Bearer ${cookies.get('token')}`,
				},
				body: JSON.stringify({
					secret: userSettingsDataServ.qr_secret,
					code: code,
					user_name: userSettingsDataServ.user_name,
				}),
			})
			console.log('response')
			console.log(response)
			const twfa_json = await response.json()
			console.log('twfa_json')
			console.log(twfa_json)
			if (response.status === 200) {
			} else {
				return fail(response.status, {
					error: twfa_json,
				})
			}
		} catch (error) {
			console.log(error)
		}
	},
	twofa_disable: async ({ cookies }) => {
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
		try {
			const response = await fetch('http://backend:61001/2fa/remove_totp/', {
				method: 'POST',
				headers: {
					Accept: '*/*',
					'Content-Type': '*/*',
					Authorization: `Bearer ${cookies.get('token')}`,
				},
				body: JSON.stringify({
					user_name: userSettingsDataServ.user_name,
				}),
			})
			const twfa_dis_json = await response.json()
			if (response.status === 200) {
			} else {
				return fail(response.status, {
					error: twfa_dis_json,
				})
			}
		} catch (error) {
			console.log(error)
		}
	},
	language: async ({ request, cookies }) => {
		try {
        	const data = await request.formData();
			const lang = data.get('lang');
			const response = await fetch('http://backend:61001/accounts/change-lang/', {
				method: 'POST',
				headers: {
					Accept: '*/*',
					'Content-Type': '*/*',
					Authorization: `Bearer ${cookies.get('token')}`,
				},
				body: JSON.stringify({
					lang: lang
				}),
			})
		}

		catch (error) {
			console.log(error);
		}
	}
}
