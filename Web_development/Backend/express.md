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
