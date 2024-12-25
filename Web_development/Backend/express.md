## This is the framework of node that help use optimize our code and manage the responses effectively. 
Here is the sample code of using express  :
```js
const express=require('express');
const app=express();
const port=80;

//for serving the static files
app.use('/static',express.static('static'));
app.get("/",(req,res)=>{
    res.status(200).send("This is home page")
})
app.get("/about",(req,res)=>{
    res.send("This is about page")
})
app.get("/contact",(req,res)=>{
    res.send("This is contact page")
})
app.post("/about",(req,res)=>{
    res.send("This is post req for first express app with harry")
})
app.listen(port,()=>{
    console.log(`This application is running on port ${port}`);
})
```
** Static folder is used to render the file as (it is).** it can be added to app.js (the file for express)
as given below:
```js
//for serving the static files
app.use('/static',express.static('static'));
```
Next interesting thing is 
**pug**: Pug is a template engine for Express.js used to generate dynamic HTML with a clean, indentation-based syntax. It integrates easily with Express, supports dynamic data injection, and allows for reusable components and basic logic in templates.
Here views folder is created and demo.pug is made in the folder. The given code is used to connect the  pug with express

express/app.js
```js
app.set("view engine",'pug');

//set the views directory as pug"
app.set("views",path.join(__dirname,'views'));

// Our pug demo endpoint
app.get("/demo",(req,res)=>{
    res.status(200).render('demo',{title:'Hey richa',message:"how are you?"})
})
```
views/demo.pug
```pug
html 
 head 
    title=title 
 body 
    h1=message
```
