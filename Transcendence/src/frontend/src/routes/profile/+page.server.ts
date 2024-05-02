import { redirect, fail } from '@sveltejs/kit';
import type { PageServerLoad } from './$types';
import { goto } from '$app/navigation';

export const actions = {
	async default({ request }) {
		const data = await request.formData();

		const user_name = data.get('user_name');

		const response = await fetch("http://backend:61001/accounts/username/", {
			method: "POST",
			headers: { "Content-Type": "application/json" },
			body: JSON.stringify({
				user_name: user_name,
			}),
		});
		const statusCode = response.status;
		if (statusCode == 200)
			redirect(302, `/profile/${user_name}`);
		else
		{
			return fail(response.status, {
				error: "user_name",
			});
		}
	}
};
