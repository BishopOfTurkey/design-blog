<script>
  export let html
  export let title

  import 'highlight.js/styles/arduino-light.css'
</script>

<svelte:head>
  <title>{title} | DESN2010 Blog</title>
</svelte:head>

<article>
  {@html html}
</article>


<style>
  article :global(img) {
     max-width: 800px;
     max-height: 400px;
     display: block;
  }

  article :global(p:not(:last-child)) {
    margin-bottom: 7px;
  }

  article :global(p) {
    line-height: normal;
    text-align: justify;
  }
  article {
    margin-bottom: 25px;
  }
</style>