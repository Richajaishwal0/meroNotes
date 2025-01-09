### Here we will discuss about the application of API using Postman. We will build a text summarizer app that used the uses the hugging face API to summarize the text instead of building the model from the scratch. It includes the frontend and backend folder . [Here]() you will find the detailed structure of the folders.Since this is the tutorial on how to implement we will focus on the steps we followed to make the project listed
[here]().
# First we will focus on the frontend part that is on html and css to make a static  page whose main component,
textarea will accept the paragraphs and the next textarea will give the output as the summarize text.
script.js
THis file is used to make the page interactive dyamically that allows user to enter the text
and click summarize to get the output.
so event listeners are used for that and next we have set the condition for the input text to be between 200 anad 100000 that sets
the limit to enter the text, next is submit data function that is used to add the animations of loading while submitting 
Next we have 
Index.js
 Here’s a summary of your Express server code in a `.md` format, covering the key elements and their meanings for quick reference:
****
# Express Server Setup(index.js)

This document provides an overview of the Express server setup and its components.

### Code Overview
```javascript
const express = require('express');
const app = express();
const port = 3000;

app.use(express.json());
app.use(express.static('public'));

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
```

### Code Breakdown

- **`const express = require('express')`**
  - Imports the Express module to use it for creating and managing the server.

- **`const app = express()`**
  - Creates an instance of an Express application. This instance (`app`) is used to configure middleware and routes.

- **`const port = 3000`**
  - Specifies the port number the server will use to listen for incoming requests. You can replace `3000` with any other available port number.

- **`app.use(express.json())`**
  - Middleware for parsing JSON data in the body of incoming HTTP requests. Useful for handling data in `POST` requests.

- **`app.use(express.static('public'))`**
  - Serves static files (HTML, CSS, JS, images, etc.) from the `public` directory. Files in `public` can be accessed directly via the URL path.

- **`app.listen(port, () => { ... })`**
  - Starts the server and listens on the specified port (in this case, `3000`). Once running, logs a message to the console with the server’s URL.

### Alternative Ports
- Besides `3000`, other common ports you can use for a local development server include:
  - `5000`, `8000`, `8080`, `4000`, or any port between `1024` and `49151` that isn’t in use.

### Summary
This setup defines a simple Express server that:
- Listens on a specified port.
- Parses JSON request bodies.
- Serves static files from a `public` folder.

This basic setup is commonly used for local development and can be expanded to handle additional routes, middleware, and server configurations.

****
Next one is summarize.js
create a function as 
```js
async function summarizeText(text){
let data=JSON.stringify({
"input":text,
"parameters":{
"max_length":100,
"min_length"30
}
});
module.exports=summarizeText;
```
Create the token from the hugging face and paste it in the variables of the collection(only in the current value as it act as a password).

We’ll use Postman's client code generation feature to generate code that makes our API call using axios. axios is a library that makes it easy to make HTTP requests in NodeJS and the browser. We already added axios for you to this project in the package.json file to use in our server.
