
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

# APIs 

## REST API — Short Notes

### What is REST?

**REST (Representational State Transfer)** is an architectural style used to design APIs for communication between clients and servers.

REST treats data as **resources**, and each resource is identified by a **URL**.

> **URL = Resource | HTTP Method = Operation**

### REST + CRUD

| Operation | HTTP Method   | Example             |
| --------- | ------------- | ------------------- |
| Create    | **POST**      | `POST /users`       |
| Read      | **GET**       | `GET /users/123`    |
| Update    | **PUT/PATCH** | `PUT /users/123`    |
| Delete    | **DELETE**    | `DELETE /users/123` |

### Key REST Principles

* **Stateless:** Every request contains the information needed to process it; the server does not depend on previous requests.
* **Cacheable:** Responses can be cached to improve performance and reduce server load.
* **Uniform Interface:** Consistent URL patterns and HTTP methods make the API predictable.

### Advantages

* Simple and easy to understand
* Uses standard HTTP methods
* Easy to scale
* Supports caching
* Works well for most web applications

### Limitation

If data is spread across multiple resources, the client may need **multiple API calls**, increasing network requests and latency.

**Example:**

```text
GET /users/123
GET /users/123/posts
GET /posts/456/comments
```

### Interview Definition

> **REST API is a resource-based API design style that uses URLs to identify resources and HTTP methods to perform operations on them.**

# GraphQL — Short Notes

### What is GraphQL?

**GraphQL** is an API query language developed by **Facebook (Meta)** that allows the client to request **exactly the data it needs**.

> **GraphQL = Client specifies the data → Server returns exactly that data**

---

### Example

Suppose we need a user's **name and post titles**.

With GraphQL:

```graphql
query {
  user(id: 1) {
    name
    posts {
      title
    }
  }
}
```

The server returns only the requested fields:

```json
{
  "name": "John",
  "posts": [
    { "title": "My First Post" },
    { "title": "System Design Notes" }
  ]
}
```

---

### REST vs GraphQL

**REST:**

```text
GET /users/123
GET /users/123/posts
```

→ Multiple API requests may be required.

**GraphQL:**

```text
Client
   ↓
 Single Query
   ↓
GraphQL Server
   ↓
User + Posts
```

→ Related data can be requested in **one query**.

---

### Advantages

* **Exact data fetching** — avoids getting unnecessary fields.
* **Fewer requests** — related data can be fetched together.
* **Flexible** — clients can request different fields based on their needs.
* Useful for applications such as **social media and mobile apps** where data requirements vary.

---

### Disadvantages / Trade-offs

* **More server-side complexity** because resolvers are required.
* **Caching is harder** compared with typical REST GET requests.
* **Deep/nested queries** can cause performance problems.
* Requires careful **query limits and optimization**.

---

### Interview Comparison

| REST                              | GraphQL                              |
| --------------------------------- | ------------------------------------ |
| Multiple resource-based endpoints | Usually a single GraphQL endpoint    |
| Server defines response structure | Client defines required fields       |
| Simple and easier to implement    | More complex                         |
| Easier HTTP caching               | Caching can be harder                |
| Good default for most systems     | Good when clients need flexible data |

### Interview Definition

> **GraphQL allows clients to request exactly the data they need through a single query. It provides flexibility and can reduce multiple API calls, but introduces additional server-side complexity and makes caching and performance management more challenging.**

**Remember:**

> **REST → Server decides the response structure.**
> **GraphQL → Client decides what data it wants.**

