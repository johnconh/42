import { writable } from "svelte/store";

export const user = writable({});
export const isLoggedIn = writable(false);
export const access_token = writable("");
export const refresh_token = writable("");