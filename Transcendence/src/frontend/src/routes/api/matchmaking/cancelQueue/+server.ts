import { json } from '@sveltejs/kit';
import type { RequestHandler } from './$types';

export const POST: RequestHandler = async ({ cookies, request }) => {
    const data = await request.json();
    const user_name = data.user_name;
    const response = await fetch("http://backend:61001/matchmaking/leave_queue/",
        {
            method: "POST",
            headers: {
                Accept: "*/*",
                "Content-Type": "*/*",
                Authorization: `Bearer ${cookies.get('token')}`,
            },
            body: JSON.stringify({
                user_name: user_name,
            }),
        }
    )
    const responseBody = await response.json();
    return json(responseBody);
};