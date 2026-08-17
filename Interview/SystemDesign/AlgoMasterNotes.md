
## HTTP Methods / API Calls

| HTTP Method | Purpose             | Example API Call    | Meaning              |
| ----------- | ------------------- | ------------------- | -------------------- |
| **GET**     | Fetch data          | `GET /users/123`    | Get user with ID 123 |
| **POST**    | Create data         | `POST /users`       | Create a new user    |
| **PUT**     | Update/replace data | `PUT /users/123`    | Update user 123      |
| **DELETE**  | Delete data         | `DELETE /users/123` | Delete user 123      |

### Easy to Remember

```text
GET     → Read
POST    → Create
PUT     → Update
DELETE  → Delete
```

---

## HTTP Status Codes

| Status Code                   | Meaning                       | When it is used                                   |
| ----------------------------- | ----------------------------- | ------------------------------------------------- |
| **200 OK**                    | Success                       | Request completed successfully                    |
| **201 Created**               | Resource created              | New user/order/etc. was created                   |
| **400 Bad Request**           | Invalid request               | Client sent incorrect/missing data                |
| **401 Unauthorized**          | Authentication failed/missing | Login/token is required or invalid                |
| **403 Forbidden**             | Access denied                 | User is authenticated but doesn't have permission |
| **404 Not Found**             | Resource not found            | Requested user/order/page doesn't exist           |
| **500 Internal Server Error** | Server error                  | Something went wrong on the server                |

### Easy Pattern

```text
2xx → Success
4xx → Client-side problem
5xx → Server-side problem
```

---

# HTTP Headers

**Headers = additional information sent along with an HTTP request or response.**

Think of them as **metadata about the request/response**.

| Header             | Purpose                                              | Example                          |
| ------------------ | ---------------------------------------------------- | -------------------------------- |
| **Authorization**  | Sends authentication credentials/token               | `Authorization: Bearer <token>`  |
| **Content-Type**   | Tells the type/format of data                        | `Content-Type: application/json` |
| **Cache-Control**  | Controls caching behavior                            | `Cache-Control: max-age=3600`    |
| **Accept**         | Tells server what response format the client accepts | `Accept: application/json`       |
| **Content-Length** | Tells size of request/response body                  | `Content-Length: 1024`           |

### Example API Request

```http
POST /users
Authorization: Bearer abc123
Content-Type: application/json
Accept: application/json

{
  "name": "John",
  "age": 20
}
```

Here:

* **POST** → We want to create a user.
* **Authorization** → Proves who the user is.
* **Content-Type** → Request body is JSON.
* **Accept** → Client wants the response in JSON.
* **Body** → Contains the actual user data.

** 
Bearer is an authentication scheme where the client sends an access token in the Authorization header. The server validates the token and, if valid, allows access to the protected resource.
**

### Interview Definition

> **HTTP headers carry metadata about a request or response, such as authentication information, data format, caching rules, and the type of response the client expects.**
