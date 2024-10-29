## Request methods

### When we make an HTTP call to a server, we specify a request method that indicates the type of operation we are about to perform. These are also called HTTP verbs.
Some common HTTP request methods correspond to the CRUD operations mentioned earlier. You can see a list of more methods here.

| Method name | Operation                             |
|-------------|---------------------------------------|
| **GET**     | Retrieve data (Read)                 |
| **POST**    | Send data (Create)                   |
| **PUT/PATCH** | Update data (Update)                |
|             | * **PUT** usually replaces an entire resource, whereas **PATCH** is for partial updates |
| **DELETE**  | Delete data (Delete)                 |

## Response status codes
## The Postman Library API v2 has returned a response status code of "200 OK". Status codes are indicators of whether a request failed or succeeded.
Status codes have conventions. For example, any status code starting with a "2xx" (a "200-level response") represents a successful call. Get familiar with other status code categories:

| Code range | Meaning        | Example                                  |
|------------|----------------|------------------------------------------|
| **2xx**    | Success        | `200` - OK  <br> `201` - Created  <br> `204` - No content (silent OK) |
| **3xx**    | Redirection    | `301` - Moved (path changed)            |
| **4xx**    | Client error   | `400` - Bad request  <br> `401` - Unauthorized  <br> `403` - Not Permitted  <br> `404` - Not Found |
| **5xx**    | Server error   | `500` - Internal server error  <br> `502` - Bad gateway  <br> `504` - Gateway timeout |
# First we will talk about the get responses.
## Here are the refereces where you can learn about the variables that can be used to substitude the address/host of the server sp that u can make a request easily.
[Variables](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/104556)
## Some API allow you to refine the request further with the key-value pairs called query parameter.
## It's quite easy to learn these things that is going to be worthful for sure.

Check it out [Here](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/929)
#  Next is the create operation.
## Here authorization is important inorder to create the api else you will get the error.
This [link](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/940) will acknowledge you about the process of creating API in postman
# Postman has an Auth helper that makes authorizing requests even easier!

## Delete the api-key header
Before we use the Postman Auth helper, let's remove the hard-coded header we just added on the "add a book" request.

## Hover over the api-key header in the Headers tab and click the "x" icon at the right to delete the header. Save your request.

## Add Auth to the Collection
The Postman Auth helper can help you add authorization at the request, folder or collection level.
Do check it out in detail [here](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/941)
