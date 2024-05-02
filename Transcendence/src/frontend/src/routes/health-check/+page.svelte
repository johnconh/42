<script lang="ts">
    import type { PageData } from './$types';
    import "../../../node_modules/bootstrap/dist/css/bootstrap.min.css"
    
    export let data: PageData;
</script>

<div>
    <h1 class="">Service is up ✅</h1>
    <button class="btn btn-primary" on:click={() => {window.location.href = '/'}}>Redirect</button>
</div>