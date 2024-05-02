// @ts-nocheck
import { error, fail, redirect } from '@sveltejs/kit';
import type { Actions } from './$types';
import type { PageServerLoad } from './$types';

let loginDataServ = {
    user_name: "",
    secret: "",
    token: "",
    refresh: "",
};

export const load = async ({ cookies }: Parameters<PageServerLoad>[0]) => {
    if (cookies.get('token')) {
        redirect(302, "/");
    }
}

export const actions = {
    default_login: async ({ cookies, request, fetch }) => {
        const data = await request.formData();

        const user_name = data.get('user_name');
        const password = data.get('password');

        const response = await fetch("http://backend:61001/accounts/login/", {
            method: "POST",
            headers: {
                Accept: "*/*",
                "Content-Type": "*/*",
            },
            body: JSON.stringify({
                user_name: user_name,
                password: password,
            }),
        });
        const json = await response.json();
        if (response.status === 200) {
            if (json.secret != null) {
                loginDataServ.user_name = user_name;
                loginDataServ.secret = json.secret;
                loginDataServ.token = json.access_token;
                loginDataServ.refresh = json.refresh_token;
                return fail(response.status, {
                    error: "2FA",
                });
            }
            else {
                cookies.set('token', json.access_token, {
                    path: '/',
                    httpOnly: true,
                    sameSite: 'strict',
                    maxAge: 60 * 60 * 24 * 1000,
                    secure: false,
                });
                cookies.set('refresh', json.refresh_token, {
                    path: '/',
                    httpOnly: true,
                    sameSite: 'strict',
                    maxAge: 60 * 60 * 24 * 1000,
                    secure: false,
                });
            }
            redirect(302, "/");
        } else {
            console.log("response query: ");
            console.log(json.detail);
            if (json.detail === "Account is not verified yet") {
                redirect(302, "/user-checker");
            }
            if (json.password) {
                return fail(response.status, {
                    type: "password",
                    error: json.password.join(" "),
                });
            }
            return fail(response.status, {
                type: "username",
                error: json.detail,
            });
        }
    },
    twofa_login: async ({ cookies, request, fetch }) => {
        const data = await request.formData();
        // const code = data.get('code');
        console.log("ayiyiyiyi.qr_secret");
        console.log(data);

        const tfaresponse = await fetch("http://backend:61001/2fa/login_2fa/", {
            method: "POST",
            headers: {
                Accept: "*/*",
                "Content-Type": "*/*",
            },
            body: JSON.stringify({
                secret: loginDataServ.secret,
                code: data.get('code'),
                user_name: loginDataServ.user_name,
            }),
        });
        const tfajson = await tfaresponse.json();
        console.log("tfaresponse query: ");
        console.log(tfajson);
        if (tfaresponse.status === 200) {
            cookies.set('token', loginDataServ.token, {
                path: '/',
                httpOnly: true,
                sameSite: 'strict',
                maxAge: 60 * 60 * 24 * 1000,
                secure: false,
            });
            cookies.set('refresh', loginDataServ.refresh, {
                path: '/',
                httpOnly: true,
                sameSite: 'strict',
                maxAge: 60 * 60 * 24 * 1000,
                secure: false,
            });
            redirect(302, "/");
        } else {
            if (tfajson.detail === "Account is not verified yet") {
                redirect(302, "/user-checker");
            }
            return fail(tfaresponse.status, {
                type: "tfacode",
                error: tfajson.message,
            });
        }
    },
	login_42: async ({ cookies, request, fetch }) => {
		/* redirect(302, "") */
        const response = await fetch("http://backend:61001/auth/login42/", {
            method: "GET",
            headers: {
                Accept: "*/*",
                "Content-Type": "*/*",
            },
        });
        const json = await response.json();
		redirect(302, json.url)
	}
} satisfies Actions;
