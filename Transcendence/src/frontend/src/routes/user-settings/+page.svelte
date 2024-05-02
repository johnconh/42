<script lang="ts">
  import type { PageData } from "./$types";
  import type { ActionData } from "./$types";
  import { onMount } from "svelte";
  import { qr } from "@svelte-put/qr/svg";
  import catLogo from "../../lib/images/fatAssCatInTuxeado.svg";
  import {localizationDict, localize} from '../../localization/localize.js'

  export let form: ActionData;

  let twoFAError = form?.error?.message;

  export let data: PageData;
  let language = data.mainUserData ? data.mainUserData.lang : 'en';
  let isChecked = false;
  let dialog: HTMLDialogElement | null = null;
  let fileInput;

  async function twoFAFunction() {
    if (isChecked) {
      isChecked = false;
      dialog.showModal();
    } else {
      isChecked = true;
      twofa_modal.showModal();
    }
  }

  async function checkerFunction() {
    if (isChecked) {
      isChecked = false;
    } else {
      isChecked = true;
    }
  }

  async function checkerFunctionCancel() {
    if (isChecked) {
      isChecked = false;
    } else {
      isChecked = true;
    }
  }

  onMount(() => {
    if (data.userSettingsData.secret != null) {
      isChecked = true;
    } else {
      if (twoFAError) twofa_modal.showModal();
      isChecked = false;
    }
    if (twoFAError && !isChecked) {
      isChecked = true;
    }
  });

  const handleFileChange = () => {
    // Mostrar una ventana emergente (puedes personalizar esto)
    const isConfirmed = window.confirm(
      localize('change_avatar', language)
    );

    if (isConfirmed) {
      // Enviar el formulario
      document.getElementById("uploadForm").submit();
    } else {
      fileInput.value = "";
    }
  };

  let langInput;
  let lang = "en";
  const changeLanguage = (e) => {
	  langInput.value=lang;
  }
</script>

<div class="flex flex-col items-center justify-center h-screen -mt-16">
	<div class="flex flex-col items-center justify-center mb-6 gap-9 p-7 backdrop-blur-sm bg-white/10 rounded-xl w-auto">
		<form method="POST" action="?/language" on:submit={changeLanguage}>
			<span>
				<input type="text" name="lang" value="en" hidden bind:this={langInput}>
				<button type="submit" class='px-8 text-2xl' on:click={()=>{lang="en"}}>🇬🇧 (en)</button>
				<button type="submit" class='px-8 text-2xl' on:click={()=>{lang="eus"}}>🏴 (eus)</button>
				<button type="submit" class='px-8 text-2xl' on:click={()=>{lang="es"}}>🇪🇸 (es)</button>
			</span>
		</form>
	</div>
  <div
    class="flex flex-col gap-9 p-7 backdrop-blur-sm bg-white/10 rounded-xl w-auto"
  >
    <div class="flex flex-row gap-10">
      <div class="mx-auto w-64 text-center">
        <form
          id="uploadForm"
          enctype="multipart/form-data"
          method="POST"
          action="?/avatar"
        >
          <div class="relative w-64">
            <label for="fileInput" class="group">
              <img
                class="w-64 h-64 rounded-full absolute"
                src={data.userSettingsData.avatar_fileName}
                alt="user avatar"
              />
              <div
                class="w-64 h-64 group hover:bg-gray-200 opacity-60 rounded-full flex justify-center items-center cursor-pointer transition duration-500"
              >
                <img
                  class="hidden group-hover:block w-12"
                  src="https://www.svgrepo.com/show/33565/upload.svg"
                  alt=""
                />
              </div>
            </label>
            <input
              bind:this={fileInput}
              type="file"
              id="fileInput"
              class="hidden"
              name="new_avatar"
              on:change={handleFileChange}
            />
          </div>
        </form>
      </div>
      <div class="flex flex-col m-auto items-start top-0.5">
        <h1 class="text-center text-4xl mb-3 font-bold">
          {data.userSettingsData.user_name}
        </h1>
        <p class="text-xl">{data.userSettingsData.email}</p>
      </div>
    </div>
    <div class="flex flex-row gap-7 items-end">
      <div class="flex flex-col gap-3">
        <p class="text-3xl font-semibold">{data.userSettingsData.first_name}</p>
        <p class="text-3xl font-semibold">{data.userSettingsData.last_name}</p>
      </div>
      <button class="btn btn-circle max-w-20" onclick="edit_modal.showModal()">
        <svg
          xmlns="http://www.w3.org/2000/svg"
          width="24"
          height="24"
          fill="currentColor"
          class="bi bi-pencil"
          viewBox="0 0 16 16"
        >
          <path
            d="M12.146.146a.5.5 0 0 1 .708 0l3 3a.5.5 0 0 1 0 .708l-10 10a.5.5 0 0 1-.168.11l-5 2a.5.5 0 0 1-.65-.65l2-5a.5.5 0 0 1 .11-.168zM11.207 2.5 13.5 4.793 14.793 3.5 12.5 1.207zm1.586 3L10.5 3.207 4 9.707V10h.5a.5.5 0 0 1 .5.5v.5h.5a.5.5 0 0 1 .5.5v.5h.293zm-9.761 5.175-.106.106-1.528 3.821 3.821-1.528.106-.106A.5.5 0 0 1 5 12.5V12h-.5a.5.5 0 0 1-.5-.5V11h-.5a.5.5 0 0 1-.468-.325"
          />
        </svg>
      </button>
      <dialog id="edit_modal" class="modal">
        <div class="modal-box">
          <h3 class="font-bold text-lg">{localize('edit_name', language)}</h3>
          <form
            class="mt-6 flex flex-col gap-4"
            method="POST"
            action="?/profile_data"
          >
            <label class="input input-bordered flex items-center gap-2">
              <svg
                xmlns="http://www.w3.org/2000/svg"
                viewBox="0 0 16 16"
                fill="currentColor"
                class="w-4 h-4 opacity-70"
                ><path
                  d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z"
                /></svg
              >
              <input
                type="text"
                class="grow"
                placeholder="First Name"
                name="new_first_name"
              />
            </label>

            <label class="input input-bordered flex items-center gap-2">
              <svg
                xmlns="http://www.w3.org/2000/svg"
                viewBox="0 0 16 16"
                fill="currentColor"
                class="w-4 h-4 opacity-70"
                ><path
                  d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z"
                /></svg
              >
              <input
                type="text"
                class="grow"
                placeholder="Last Name"
                name="new_last_name"
              />
            </label>

            <button class="btn btn-success">{localize('submit', language)}</button>
          </form>
          <div class="modal-action">
            <form method="dialog">
              <button class="btn">{localize('cancel', language)}</button>
            </form>
          </div>
        </div>
      </dialog>
    </div>
    {#if data.userSettingsData.is42 == false}
      <div class="flex flex-row gap-4">
        <p>{localize('twofactor', language)}</p>
        <input
          type="checkbox"
          value="2factor"
          class="toggle"
          on:click={twoFAFunction}
          checked={isChecked}
          method="POST"
          action="?/avatar"
        />
        <dialog id={isChecked == false ? "twofa_modal" : ""} class="modal">
          <div class="modal-box">
            <h3 class="font-bold text-lg">{localize('twofactor', language)}</h3>
            <svg
              use:qr={{
                data: data.userSettingsData.qrLink,
                logo: catLogo,
                shape: "circle",
              }}
            />
            <form class="mt-6 flex flex-col gap-4" method="POST" action="?/twofa">
              <label class="input input-bordered flex items-center gap-2">
                <svg
                  xmlns="http://www.w3.org/2000/svg"
                  viewBox="0 0 16 16"
                  fill="currentColor"
                  class="w-4 h-4 opacity-70"
                  ><path
                    d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z"
                  /></svg
                >
                <input
                  type="text"
                  class="grow"
                  placeholder="2FA Code"
                  name="code"
                  id="code"
                />
              </label>
              <button class="btn btn-success">{localize('submit', language)}</button>
              {#if twoFAError}
                <p class="text-red-500 text-wrap w-fit">{twoFAError}</p>
              {/if}
              <div class="modal-action">
                <form method="dialog">
                  <button class="btn" on:click={checkerFunctionCancel}
                    >{localize('cancel', language)}</button
                  >
                </form>
              </div>
            </form>
          </div>
        </dialog>
        <dialog bind:this={dialog} class="modal">
          <div class="modal-box">
            <h3 class="font-bold text-lg">{localize('twofactor', language)}</h3>
            <h1 class="mt-4 mb-6">{localize('sure_to_remove_2fa', language)}</h1>
            <form method="POST" action="?/twofa_disable">
              <button class="mr-5 btn btn-error">{localize('remove_2fa', language)}</button>
            </form>
            <form method="dialog">
              <button class="btn mt-5" on:click={checkerFunction}>{localize('cancel', language)}</button
              >
            </form>
          </div>
        </dialog>
      </div>
    {/if}
  </div>
</div>
