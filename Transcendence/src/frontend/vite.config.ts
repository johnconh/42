/* import { sveltekit } from '@sveltejs/kit/vite'; */
/* import { defineConfig } from 'vite'; */
/* import fs from 'fs'; */

/* export default defineConfig({ */
/*     plugins: [sveltekit()], */
/*     server: { */
/*         https: { */
/*             key: fs.readFileSync('/tmp/selfsigned.key'),  // Ruta a la clave privada */
/*             cert: fs.readFileSync('/tmp/selfsigned.crt')  // Ruta al certificado */
/*         }, */
/*         proxy: {}, */
/*         port: 5173 */
/*     } */
/* }); */

import { sveltekit } from '@sveltejs/kit/vite';
import { defineConfig } from 'vite';

export default defineConfig({
	plugins: [sveltekit()],
	server: {
		port: 5173,
	}
});
