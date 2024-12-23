## Built in modules in node js
- fs
  - handle the file system
example:
```js
const fs=require("fs");
let text=fs.readFileSync("del.txt","utf-8");
text=text.replace("hello","hey");
console.log(text)

// creating a new file
fs.writeFileSync("random.txt",text);
```
Output:
```

hey welcome to del.txt file // and creates teh filename random.txt and write the text there

```
