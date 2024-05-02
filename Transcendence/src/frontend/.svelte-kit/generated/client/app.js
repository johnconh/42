export { matchers } from './matchers.js';

export const nodes = [
	() => import('./nodes/0'),
	() => import('./nodes/1'),
	() => import('./nodes/2'),
	() => import('./nodes/3'),
	() => import('./nodes/4'),
	() => import('./nodes/5'),
	() => import('./nodes/6'),
	() => import('./nodes/7'),
	() => import('./nodes/8'),
	() => import('./nodes/9'),
	() => import('./nodes/10'),
	() => import('./nodes/11'),
	() => import('./nodes/12'),
	() => import('./nodes/13'),
	() => import('./nodes/14'),
	() => import('./nodes/15'),
	() => import('./nodes/16'),
	() => import('./nodes/17'),
	() => import('./nodes/18'),
	() => import('./nodes/19'),
	() => import('./nodes/20')
];

export const server_loads = [0];

export const dictionary = {
		"/": [2],
		"/ftVerify": [~3],
		"/health-check": [4],
		"/local": [~5],
		"/login": [~6],
		"/logout": [~7],
		"/manual": [8],
		"/matchmaking": [~9],
		"/pong2": [12],
		"/pong": [10],
		"/pong/[gameid]": [~11],
		"/profile": [~13],
		"/profile/[user]": [~14],
		"/pswrd-reset": [~15],
		"/register": [~16],
		"/tournament-local": [~18],
		"/tournament": [~17],
		"/user-checker": [~19],
		"/user-settings": [~20]
	};

export const hooks = {
	handleError: (({ error }) => { console.error(error) }),

	reroute: (() => {})
};

export { default as root } from '../root.svelte';