
import { fail, redirect } from '@sveltejs/kit';
import type { Actions } from './$types';
import type { PageServerLoad } from './$types';

export const load: PageServerLoad = async ({ cookies }) => {
    if (cookies.get('token')) {
        redirect(302, "/");
    }
}

export const actions = {
    default_register: async ({ request }) => {
        const data = await request.formData();

        const user_name = data.get('user_name');
        const email = data.get('email');
        const first_name = data.get('first_name');
        const last_name = data.get('last_name');
        const birthdate = data.get('birthdate');
        const password = data.get('password');
        const password2 = data.get('password2');

        const response = await fetch("http://backend:61001/accounts/register/",
            {
                method: "POST",
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({
                    user_name: user_name,
                    email: email,
                    first_name: first_name,
                    last_name: last_name,
                    birthdate: birthdate,
                    password: password,
                    password2: password2,
                }),
            }
        )
        const responseBody = await response.json();
        if (response.status === 201) {
            redirect(302, "/user-checker");
        } else {
            console.log("ni de coña chaval");
            console.log(responseBody);
            console.log("dever estar troleando");
            return fail(response.status, {
                error: responseBody,
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
