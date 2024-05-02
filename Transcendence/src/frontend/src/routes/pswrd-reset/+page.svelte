<script lang="ts">
    import type { ActionData } from "./$types";
    import {localizationDict, localize} from '../../localization/localize.js'
    export let form: ActionData;


    export let data;
    let language = data.mainUserData ? data.mainUserData.lang : 'en';

    // export let data: PageData;
</script>

<main class="flex flex-col h-screen items-center justify-center -mt-16">
    <div class="p-7 mt-10 backdrop-blur-sm bg-white/10 rounded-xl">
        <h1 class="text-2xl font-bold mb-6">{localize('reset_password', language)}</h1>
        <form class="flex flex-col gap-4" method="POST">
            <label class="flex flex-col" for="email">
                Email:
                <input class="p-2
                -gray-400 border rounded-xl" required type="text" name="email" id="email" />
            <button type="submit" class="mt-5 p-2.5 btn btn-primary border-none text-white cursor-pointer rounded-xl">Reset Password</button>
        </form>
    </div>
</main>
