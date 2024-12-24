## Here  is the basic things  to be considered while getting started with the nodejs in a backend.
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

file index.js
## Running the different html pages on the node server
```js
const http=require('http');
const fs=require('fs');

const hostname='127.0.0.1';
const port=3000;
const home=fs.readFileSync('./index.html'); //file index.html
const about=fs.readFileSync('./about.html'); //file about.html
const contact=fs.readFileSync('./contact.html'); // file contact.html
const services=fs.readFileSync('./services.html'); //file services.html
const server=http.createServer((req,res)=>{
    console.log(req.url);
    url=req.url;

    res.statusCode=200;
    res.setHeader('Content-Type','text/html');
    if (url=='/')
    {
        res.end(home);  
    }
    else if (url=='/about')
    {
        res.end(about);
    }
    else if (url=='/services')
    {
        res.end(services);
    }
    else if (url=='/contact')
    {
        res.end(contact);
    }
    else{
        res.statusCode=404;
        res.end("<h1>404 not found</h1>")
    }
})

server.listen(port,hostname,()=>
{
    console.log(`Listening to the port http://${hostname}:${port} `);
})
```
file index.html
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>This is home page</title>
    <style>
        li{
            list-style: none;

        }
        ul{
            display: flex;
            flex-direction:row;
            justify-content:space-between;

        }
        a{
            text-decoration:none;
            color:black;
            font-size: 20px;

        }
    </style>
</head>
<body>
    <nav>
        <ul>
            <li><a href="/">Home</a></li>
            <li><a href="/about">About</a></li>
            <li><a href="/contact">Contact</a></li>
            <li><a href="/services">Services</a></li>
        </ul>
    </nav>
    
</body>
</html>
```
All the other files like contact, services and about has same nav bar code as of now. 
Output:
![image](https://github.com/user-attachments/assets/628f125f-059d-4412-b3a9-6a119645b935)
