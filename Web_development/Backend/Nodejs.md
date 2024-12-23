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
More modules are on [Node modules](https://www.w3schools.com/nodejs/ref_modules.asp)
### Running the html file on node server

```js
const http=require('http')
const fs=require('fs')
const filecontent=fs.readFileSync("render.html")

const server=http.createServer((req,res)=>{
    res.writeHead(200,{'Content-type':'text/html'})
    res.end(filecontent)
})
server.listen(80,'127.0.0.1',()=>{
    console.log("listening at port 80");
})
```
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .child{
            background: red;
            height:200px;
            width:200px;
            border:2px solid black ;
        }
        .dad{
            display: flex;
            justify-content: space-between;
            flex-direction: row;
        }
    </style>

</head>
<body>
<div class="dad">
<div class="child"></div>
<div class="child"></div>
<div class="child"></div>
<div class="child"></div>
    </div>


</body>
</html>
```
Output:
![image](https://github.com/user-attachments/assets/829ae884-6747-44dc-806d-6b7c53b244af)
