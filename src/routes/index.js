import fs from 'fs'

export async function get() {
  let posts = fs.readdirSync('blog').map(fileName => String(fileName))

  return { body: { posts } }
}