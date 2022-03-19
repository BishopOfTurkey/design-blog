import {unified} from 'unified'
import remarkParse from 'remark-parse'
import remarkRehype from 'remark-rehype'
import rehypeStringify from 'rehype-stringify'

import rehypeHighlight from 'rehype-highlight'

const processor = unified()
  .use(remarkParse)
  .use(remarkRehype)
  .use(rehypeHighlight)
  .use(rehypeStringify)

export function process(markdown) {
  const result = processor.processSync(markdown);
  return String(result)
}