import { readSync } from 'to-vfile';
import { process } from '$lib/parseMarkdown.js'

export async function get({params}) {
  const slug = params.slug;
  const fileName = "blog/" + slug + ".md"

  const vfile = readSync(fileName);
  const html = process(vfile);
  return {
    body: {  title: slug, html }
  }
}