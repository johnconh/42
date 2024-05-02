// See https://kit.svelte.dev/docs/types#app
// for information about these interfaces
declare global {
	namespace App {
		// interface Error {}
		// interface Locals {}
		// interface PageData {}
		// interface PageState {}
		// interface Platform {}
		interface Usr {
			id: string;
			username: string;
			email: string;
			password: string;
			access_token: string;
			refresh_token: string;
			birthdate: string;
		}
	}
}

export {};
