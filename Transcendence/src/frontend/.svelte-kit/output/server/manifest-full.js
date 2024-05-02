export const manifest = (() => {
function __memo(fn) {
	let value;
	return () => value ??= (value = fn());
}

return {
	appDir: "_app",
	appPath: "_app",
	assets: new Set(["apple-touch-icon.png","favicon.png"]),
	mimeTypes: {".png":"image/png"},
	_: {
		client: {"start":"_app/immutable/entry/start.Byhq2YOz.js","app":"_app/immutable/entry/app.yQHBE3AM.js","imports":["_app/immutable/entry/start.Byhq2YOz.js","_app/immutable/chunks/entry.gWejR8ZX.js","_app/immutable/chunks/scheduler.BvLojk_z.js","_app/immutable/entry/app.yQHBE3AM.js","_app/immutable/chunks/scheduler.BvLojk_z.js","_app/immutable/chunks/index.fi1e1Nz5.js"],"stylesheets":[],"fonts":[],"uses_env_dynamic_public":false},
		nodes: [
			__memo(() => import('./nodes/0.js')),
			__memo(() => import('./nodes/1.js')),
			__memo(() => import('./nodes/2.js'))
		],
		routes: [
			{
				id: "/",
				pattern: /^\/$/,
				params: [],
				page: { layouts: [0,], errors: [1,], leaf: 2 },
				endpoint: null
			}
		],
		matchers: async () => {
			
			return {  };
		},
		server_assets: {}
	}
}
})();
