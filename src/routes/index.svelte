<svelte:head>
  <title>Design Blog</title>
</svelte:head>


<script>
  export let posts;
</script>


<h1>Welcome to my DESN2010 Blog</h1>
<p>
  This is still a work in progress (content and site)! 
  I've used this blog as an opportunity to learn a new way of creating websites.
</p>

<ul>
{#each posts as post}
  <li><a href="/posts/{post.slice(0,-3)}">{post}</a></li>
{/each}
</ul>