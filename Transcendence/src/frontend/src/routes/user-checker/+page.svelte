<script lang="ts">
  import type { PageData } from "./$types";
  import {localizationDict, localize} from '../../localization/localize.js'

  export let data: PageData;
  let language = data.mainUserData ? data.mainUserData.lang : 'en';
</script>

<div class="flex flex-col items-center justify-center h-screen -mt-16">
  <h2 class="text-2xl font-bold text-center mb-10">
    {localize('email_sent', language)}
  </h2>
  <div class="p-7 backdrop-blur-sm bg-white/10 rounded-xl w-72">
    <form class="flex flex-col gap-4" method="POST">
      <label for="otp" class="font-bold">{localize('code', language)}:</label>
      <input
        required
        type="text"
        name="otp"
        id="otp"
        class="p-2 rounded border border-gray-300 text-gray-500"
      />
      <button
        type="submit"
        class="p-2 btn btn-primary text-white border-none cursor-pointer"
        >{localize('check', language)}</button
      >
    </form>
  </div>
</div>
