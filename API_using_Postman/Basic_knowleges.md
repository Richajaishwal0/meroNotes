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
