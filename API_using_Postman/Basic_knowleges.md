
# Understanding HTTP Request Methods and API Responses

When making an HTTP call to a server, we specify a request method that indicates the type of operation we intend to perform. These request methods, often referred to as HTTP verbs, correspond to standard CRUD operations. Below is a table outlining some common HTTP request methods

| Method Name | Operation                             |
|-------------|---------------------------------------|
| **GET**     | Retrieve data (Read)                 |
| **POST**    | Send data (Create)                   |
| **PUT/PATCH** | Update data (Update)                |
|             | * **PUT** typically replaces an entire resource, while **PATCH** is used for partial updates. |
| **DELETE**  | Remove data (Delete)                 |

## Response Status Codes

When using APIs, the server responds with a status code that indicates whether a request was successful or encountered an error. For instance, the Postman Library API v2 returns a status code of "200 OK" for successful requests. Understanding these status codes is crucial, as they follow a specific convention:

| Code Range | Meaning        | Example                                  |
|------------|----------------|------------------------------------------|
| **2xx**    | Success        | `200` - OK  <br> `201` - Created  <br> `204` - No Content (silent OK) |
| **3xx**    | Redirection    | `301` - Moved Permanently (path changed) |
| **4xx**    | Client Error   | `400` - Bad Request  <br> `401` - Unauthorized  <br> `403` - Forbidden  <br> `404` - Not Found |
| **5xx**    | Server Error   | `500` - Internal Server Error  <br> `502` - Bad Gateway  <br> `504` - Gateway Timeout |

## Making GET Requests

GET requests are used to retrieve data from a server. You can customize these requests further by using variables to substitute the address or host of the server, allowing for more flexibility. 

For additional information about using variables, check out this [Postman Variables Guide](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/104556).

### Query Parameters

Many APIs allow you to refine requests with key-value pairs known as query parameters. These parameters enable you to filter or sort the data returned by the API. Understanding how to use them will greatly enhance your API interactions. 

To learn more about query parameters, visit this [Postman Query Parameters Guide](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/929).

## Creating Resources with POST Requests

When creating resources via POST requests, authorization is essential. Without the proper authorization, you may receive an error message. 

For a detailed explanation of how to create APIs in Postman, follow this [Postman API Creation Guide](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/940).

### Using the Postman Auth Helper

Postman provides an Auth helper feature that simplifies the process of authorizing requests. Before utilizing this feature, you may need to remove any hard-coded authorization headers in your requests. 

To do this, hover over the api-key header in the Headers tab and click the "x" icon to delete it. Remember to save your request afterward.

#### Adding Authorization to Collections

You can easily add authorization at the request, folder, or collection level using the Postman Auth helper. For a comprehensive guide on how to do this, refer to the [Postman Auth Helper Guide](https://academy.postman.com/path/postman-api-fundamentals-student-expert/postman-api-fundamentals-student-expert-certification-1/941).

### Conclusion

Understanding HTTP request methods and response status codes is fundamental for interacting with APIs effectively. With the resources and links provided, you should have a solid foundation to begin exploring and utilizing APIs in your projects.
