/** @type {import('tailwindcss').Config} */
export default {
  content: ["./src/**/*.{html,js,svelte,ts}"],
  daisyui: {
    themes: [
      {
        pongtheme: {
          primary: "#4f5fd8",
          "primary-focus": "#2d2ba1",
          "primary-content": "#ffffff",

          secondary: "#6d38ff",
          "secondary-focus": "#4c2bc5",
          "secondary-content": "#ffffff",

          accent: "#37cdbe",
          "accent-focus": "#2ba69a",
          "accent-content": "#ffffff",

          neutral: "#2a2e37",
          "neutral-focus": "#16181d",
          "neutral-content": "#ffffff",

          "base-100": "#3b424e",
          "base-200": "#2a2e37",
          "base-300": "#16181d",
          "base-content": "#ebecf0",

          info: "#66c7ff",
          success: "#87cf3a",
          warning: "#e1d460",
          error: "#ff6b6b",

          "--rounded-box": "1rem",
          "--rounded-btn": ".5rem",
          "--rounded-badge": "1.9rem",

          "--animation-btn": ".25s",
          "--animation-input": ".2s",

          "--btn-text-case": "uppercase",
          "--navbar-padding": ".5rem",
          "--border-btn": "1px",
        },
      },
      "cupcake",
      "dark",
    ],
  },
  plugins: [require("daisyui")],
};
