Here we will discuss about the application of API using Postman. 
We will build a text summarizer app that used the uses the hugging face API to summarize the text instead of building the model from the scratch.
Its includes the frontend and backend folder . [Here]() you will find the detailed structure of the folders.
Since this is the tutorial on how to implement we will focus on the steps we followed to make the project listed
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
 this file acts uses the server of express.js to render our html page and also handles the error if response is not received .
 NExt is summarize.js
 THis file used axios and act as the communication between the server that sends the request and accept the respond.
 
