<script>
	import './app.css';
</script>

<header>
	<div>
		<h1><a href="/">DESN2010 Blog</a></h1>
	</div>
</header>

<main>
  <div>
	<slot />
  </div>
</main>

<footer>
  <div>
    <p>Obi Symons © 2022 - <a href="https://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International Public License</a> <em>Made with Svelte</em></p>
  </div>
</footer>

<style>
  main {
    flex: 1;
  }

	header {
    border-bottom: 1px solid #aaa;
    padding: 4px 0 8px 0;
	}

  footer {
    border-top: 1px solid #aaa;
    padding: 10px 0;
  }

  header > div, main > div, footer > div {
    margin-left: auto;
		margin-right: auto;
		max-width: 800px;
  }

  a, a:visited {
    color: #333;
  }
</style>
