import { redirect } from '@sveltejs/kit';
import type { PageServerLoad } from './$types';
import { goto, invalidate } from '$app/navigation';

export const load: PageServerLoad = async ({ fetch, cookies }) => {
    cookies.delete('token', {
        path: '/',
        secure: false,
    }),
    cookies.delete('refresh', {
        path: '/',
        secure: false,
    }),
    redirect(302, '/');
    // invalidate((url) => url.pathname === '/');
};