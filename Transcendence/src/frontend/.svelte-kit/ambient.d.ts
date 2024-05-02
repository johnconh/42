
// this file is generated — do not edit it


/// <reference types="@sveltejs/kit" />

/**
 * Environment variables [loaded by Vite](https://vitejs.dev/guide/env-and-mode.html#env-files) from `.env` files and `process.env`. Like [`$env/dynamic/private`](https://kit.svelte.dev/docs/modules#$env-dynamic-private), this module cannot be imported into client-side code. This module only includes variables that _do not_ begin with [`config.kit.env.publicPrefix`](https://kit.svelte.dev/docs/configuration#env) _and do_ start with [`config.kit.env.privatePrefix`](https://kit.svelte.dev/docs/configuration#env) (if configured).
 * 
 * _Unlike_ [`$env/dynamic/private`](https://kit.svelte.dev/docs/modules#$env-dynamic-private), the values exported from this module are statically injected into your bundle at build time, enabling optimisations like dead code elimination.
 * 
 * ```ts
 * import { API_KEY } from '$env/static/private';
 * ```
 * 
 * Note that all environment variables referenced in your code should be declared (for example in an `.env` file), even if they don't have a value until the app is deployed:
 * 
 * ```
 * MY_FEATURE_FLAG=""
 * ```
 * 
 * You can override `.env` values from the command line like so:
 * 
 * ```bash
 * MY_FEATURE_FLAG="enabled" npm run dev
 * ```
 */
declare module '$env/static/private' {
	export const npm_config_user_agent: string;
	export const NODE_VERSION: string;
	export const HOSTNAME: string;
	export const ORIGIN: string;
	export const SECRET_KEY: string;
	export const DEBUG: string;
	export const YARN_VERSION: string;
	export const npm_node_execpath: string;
	export const EMAIL_HOST: string;
	export const SHLVL: string;
	export const npm_config_noproxy: string;
	export const PGADMIN_DEFAULT_PASSWORD: string;
	export const HOME: string;
	export const npm_package_json: string;
	export const npm_config_userconfig: string;
	export const npm_config_local_prefix: string;
	export const npm_config_engine_strict: string;
	export const SECRET42: string;
	export const PGADMIN_DEFAULT_EMAIL: string;
	export const EMAIL_PORT: string;
	export const COLOR: string;
	export const DATA_SOURCE_NAME: string;
	export const npm_config_prefix: string;
	export const npm_config_npm_version: string;
	export const npm_config_cache: string;
	export const EMAIL_BACKEND: string;
	export const POSTGRES_PASSWORD: string;
	export const npm_config_node_gyp: string;
	export const PATH: string;
	export const NODE: string;
	export const npm_package_name: string;
	export const CLIENT42: string;
	export const POSTGRES_HOST: string;
	export const GF_SECURITY_ADMIN_PASSWORD: string;
	export const POSTGRES_USER: string;
	export const EMAIL_HOST_PASSWORD: string;
	export const URI42: string;
	export const npm_lifecycle_script: string;
	export const GF_SECURITY_ADMIN_USER: string;
	export const SUPER_PASS: string;
	export const npm_package_version: string;
	export const npm_lifecycle_event: string;
	export const EMAIL_USE_TLS: string;
	export const EMAIL_HOST_USER: string;
	export const POSTGRES_PORT: string;
	export const npm_config_globalconfig: string;
	export const npm_config_init_module: string;
	export const PWD: string;
	export const npm_execpath: string;
	export const POSTGRES_DB: string;
	export const npm_config_global_prefix: string;
	export const SUPER_USER: string;
	export const npm_command: string;
	export const NODE_ENV: string;
	export const SUPER_EMAIL: string;
	export const INIT_CWD: string;
	export const EDITOR: string;
}

/**
 * Similar to [`$env/static/private`](https://kit.svelte.dev/docs/modules#$env-static-private), except that it only includes environment variables that begin with [`config.kit.env.publicPrefix`](https://kit.svelte.dev/docs/configuration#env) (which defaults to `PUBLIC_`), and can therefore safely be exposed to client-side code.
 * 
 * Values are replaced statically at build time.
 * 
 * ```ts
 * import { PUBLIC_BASE_URL } from '$env/static/public';
 * ```
 */
declare module '$env/static/public' {
	
}

/**
 * This module provides access to runtime environment variables, as defined by the platform you're running on. For example if you're using [`adapter-node`](https://github.com/sveltejs/kit/tree/main/packages/adapter-node) (or running [`vite preview`](https://kit.svelte.dev/docs/cli)), this is equivalent to `process.env`. This module only includes variables that _do not_ begin with [`config.kit.env.publicPrefix`](https://kit.svelte.dev/docs/configuration#env) _and do_ start with [`config.kit.env.privatePrefix`](https://kit.svelte.dev/docs/configuration#env) (if configured).
 * 
 * This module cannot be imported into client-side code.
 * 
 * Dynamic environment variables cannot be used during prerendering.
 * 
 * ```ts
 * import { env } from '$env/dynamic/private';
 * console.log(env.DEPLOYMENT_SPECIFIC_VARIABLE);
 * ```
 * 
 * > In `dev`, `$env/dynamic` always includes environment variables from `.env`. In `prod`, this behavior will depend on your adapter.
 */
declare module '$env/dynamic/private' {
	export const env: {
		npm_config_user_agent: string;
		NODE_VERSION: string;
		HOSTNAME: string;
		ORIGIN: string;
		SECRET_KEY: string;
		DEBUG: string;
		YARN_VERSION: string;
		npm_node_execpath: string;
		EMAIL_HOST: string;
		SHLVL: string;
		npm_config_noproxy: string;
		PGADMIN_DEFAULT_PASSWORD: string;
		HOME: string;
		npm_package_json: string;
		npm_config_userconfig: string;
		npm_config_local_prefix: string;
		npm_config_engine_strict: string;
		SECRET42: string;
		PGADMIN_DEFAULT_EMAIL: string;
		EMAIL_PORT: string;
		COLOR: string;
		DATA_SOURCE_NAME: string;
		npm_config_prefix: string;
		npm_config_npm_version: string;
		npm_config_cache: string;
		EMAIL_BACKEND: string;
		POSTGRES_PASSWORD: string;
		npm_config_node_gyp: string;
		PATH: string;
		NODE: string;
		npm_package_name: string;
		CLIENT42: string;
		POSTGRES_HOST: string;
		GF_SECURITY_ADMIN_PASSWORD: string;
		POSTGRES_USER: string;
		EMAIL_HOST_PASSWORD: string;
		URI42: string;
		npm_lifecycle_script: string;
		GF_SECURITY_ADMIN_USER: string;
		SUPER_PASS: string;
		npm_package_version: string;
		npm_lifecycle_event: string;
		EMAIL_USE_TLS: string;
		EMAIL_HOST_USER: string;
		POSTGRES_PORT: string;
		npm_config_globalconfig: string;
		npm_config_init_module: string;
		PWD: string;
		npm_execpath: string;
		POSTGRES_DB: string;
		npm_config_global_prefix: string;
		SUPER_USER: string;
		npm_command: string;
		NODE_ENV: string;
		SUPER_EMAIL: string;
		INIT_CWD: string;
		EDITOR: string;
		[key: `PUBLIC_${string}`]: undefined;
		[key: `${string}`]: string | undefined;
	}
}

/**
 * Similar to [`$env/dynamic/private`](https://kit.svelte.dev/docs/modules#$env-dynamic-private), but only includes variables that begin with [`config.kit.env.publicPrefix`](https://kit.svelte.dev/docs/configuration#env) (which defaults to `PUBLIC_`), and can therefore safely be exposed to client-side code.
 * 
 * Note that public dynamic environment variables must all be sent from the server to the client, causing larger network requests — when possible, use `$env/static/public` instead.
 * 
 * Dynamic environment variables cannot be used during prerendering.
 * 
 * ```ts
 * import { env } from '$env/dynamic/public';
 * console.log(env.PUBLIC_DEPLOYMENT_SPECIFIC_VARIABLE);
 * ```
 */
declare module '$env/dynamic/public' {
	export const env: {
		[key: `PUBLIC_${string}`]: string | undefined;
	}
}
