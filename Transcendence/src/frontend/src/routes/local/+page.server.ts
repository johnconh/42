import { fail, redirect } from '@sveltejs/kit';
import type { PageServerLoad } from './$types';
import type { Actions } from './$types';
import type { ActionData } from "./$types";
import alert from 'svelte';

export const load = (async () => {
    return {};
}) satisfies PageServerLoad;


export const actions = {
    async default({ request, fetch }) {
        try {
            const data = await request.formData();
            const response = await fetch("http://backend:61001/accounts/reset-password/", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify({
                    email: data.get('email'),
                }),
            });
            if (response.ok) {
                console.log("Password reset successful");
                return ("Password reset successful");
            } else {
                console.error("Password reset failed");
            }
        } catch (error) {
            console.error("Error during password reset:", error);
        }
    }
} satisfies Actions;
