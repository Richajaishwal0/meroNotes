# NEGCES Lab Tracking System — System Design Interview Q&A

---

## 1. Draw and explain the high-level architecture of your project.

### Answer you can say:

> “The project follows a client-server architecture. The frontend is built with React and TypeScript and handles the user interface. It communicates with our Node.js and Express backend through APIs. The backend contains the main business logic and communicates with MongoDB for storing users, computers, bookings and notifications. Firebase is used for authentication. In production, the frontend is served through Apache, while the backend runs separately.”

### If they ask: **“Can you draw it?”**

```text
                User
                  │
                  ▼
        React + TypeScript
             Frontend
                  │
              REST APIs
                  │
                  ▼
        Node.js + Express
             Backend
             /      \
            /        \
           ▼          ▼
      MongoDB      Firebase
      Database    Authentication
```

### Don't voluntarily mention:

Podman, systemd, Apache ProxyPass, ports, containers, etc.

Only explain those if they ask about deployment.

---

# 2. How does a request flow through your system?

### Answer:

> “For example, when a user submits a booking, the React frontend collects the data and sends it to the Express backend through an API request. The backend first verifies the user's authentication, then validates the booking details and checks whether the computer is available. If everything is valid, the booking is saved in MongoDB and the backend sends a response back to the frontend.”

### Follow-up: **“Where does Firebase come in?”**

> “Firebase is mainly involved in authentication. The frontend gets an authentication token from Firebase, and the backend verifies that token before processing the protected API request.”

---

# 3. What are the main components of your system?

### Answer:

> “The main components are the React frontend, Express backend, MongoDB database, and Firebase authentication. We also have supporting services for notifications, emails and automatically completing expired bookings.”

| Component           | Responsibility             |
| ------------------- | -------------------------- |
| React               | User interface             |
| Express             | APIs and business logic    |
| MongoDB             | Application data           |
| Firebase            | Authentication             |
| Notification system | In-app notifications       |
| Email service       | Email notifications        |
| Expiration service  | Completes expired bookings |

---

# 4. How does the booking process work end-to-end?

### Answer:

> “The user selects a computer and provides the booking dates and times. The frontend performs basic validation and sends the request to the backend. The backend verifies the user, checks that the computer exists, validates the booking rules and checks for conflicting bookings. If there is no conflict, the booking is stored in MongoDB. The frontend then receives the response and updates the user's dashboard.”

### Important:

Don't say all the internal function names unless asked.

---

# 5. How do you prevent two users from booking the same computer?

### Answer:

> “Before creating a booking, the backend checks MongoDB for existing pending or approved bookings for the same computer whose date range overlaps with the requested period. If a conflict is found, the new request is rejected. This prevents normal cases of double booking.”

### Follow-up: **“How do you check date overlap?”**

> “We check whether the existing booking starts before or on the requested end date and ends after or on the requested start date.”

```text
existing.startDate <= new.endDate
AND
existing.endDate >= new.startDate
```

### If they push: **“Does this completely solve concurrency?”**

Use this:

> “It handles the normal conflict-checking case, but for very high concurrent requests, I would add stronger database-level protection or transactions so that checking and creating the booking are handled more safely as one operation.”

**This is much safer than claiming your current query is completely race-condition proof.**

---

# 6. What happens if the requested booking partially overlaps another booking?

### Answer:

> “The backend identifies the overlapping booking and then checks whether the conflicting dates have been temporarily released. If the required dates were released, the user may still be able to book those dates. If some required dates are still occupied, the booking is rejected.”

---

# 7. Explain the temporary release feature.

### Answer:

> “Temporary release allows a user to release only certain days from an existing booking. For example, if I book a computer for 10 days but don't need it for two days, I can release those two days. Another user can then use the computer on those days, while my original booking remains active for the remaining days.”

### Follow-up: **“Why is this more difficult than cancellation?”**

> “Cancellation makes the entire booking unavailable to the original user. Temporary release is different because only part of the booking becomes available, so the conflict logic has to check individual dates.”

---

# 8. Why did you store temporary release information with the booking?

### Answer:

> “The booking and its released dates are closely related, especially when we check whether a new booking conflicts with an existing booking. Keeping the relevant release information with the booking makes it easier for the backend to check the availability of those dates.”

### If they ask: **“Why not keep everything in a separate collection?”**

> “A separate collection could also work, but then conflict checking would require another lookup. We chose to keep the frequently needed information with the booking, while maintaining separate release details for tracking and administration.”

That's enough.

Don't start explaining denormalization unless they ask.

---

# 9. Why MongoDB for this system?

### Answer:

> “MongoDB suited the project because the data is naturally document-oriented. For example, computer information can contain different specifications, and temporary release information can be associated with a booking. MongoDB allowed us to keep related information together and develop the system quickly.”

### Follow-up: **“What would PostgreSQL give you?”**

> “PostgreSQL would provide stronger relational constraints and structured relationships. For this project, we felt MongoDB was simpler for our data model and development requirements.”

---

# 10. What are your main MongoDB collections?

### Answer:

> “The main collections include users, computers, bookings and notifications. There are also collections related to temporary releases.”

If they ask about relationships:

> “For example, a booking is associated with a user and a computer, so the booking stores references or identifiers that allow us to connect those records.”

---

# 11. Why don't you store the user's role in Firebase?

### Answer:

> “Firebase tells us who the user is, but our application has its own roles and application-specific information. We store the role in MongoDB so our backend can decide whether that user has admin permissions.”

### Follow-up: **“Can the frontend change its role?”**

> “Changing the frontend value doesn't give the user permission because the backend checks the role from our database.”

🔥 Learn this very well.

---

# 12. Explain your authentication architecture.

### Answer:

> “Firebase handles the user's login and authentication. After authentication, the frontend gets an ID token and sends it with protected API requests. The backend verifies that token using Firebase Admin SDK. After verifying the user, the backend uses the Firebase UID to find the corresponding user in MongoDB and get application information such as their role.”

```text
Login
  ↓
Firebase
  ↓
ID Token
  ↓
Frontend
  ↓
Authorization Header
  ↓
Express
  ↓
Firebase Token Verification
  ↓
MongoDB User
  ↓
Role
```

---

# 13. Why do you need both Firebase and MongoDB?

### Answer:

> “They solve different problems. Firebase handles authentication and identity, while MongoDB stores our application's user information, including roles and other project-specific data.”

That's the cleanest explanation.

---

# 14. What happens if someone tries to access an admin API as a normal user?

### Answer:

> “The backend first verifies their authentication. Then it checks their role. If the user is authenticated but doesn't have the admin role, the backend returns a 403 Forbidden response and doesn't perform the operation.”

---

# 15. How does the frontend protect pages?

### Answer:

> “We have a protected route mechanism on the frontend. It checks whether the user is authenticated and, where required, whether they have the correct role. If the user isn't logged in, they're redirected to the login page. But this is only for user experience—the actual security check is still performed on the backend.”

🔥 This is a very good answer.

---

# 16. Why can't you rely only on frontend authorization?

### Answer:

> “Because frontend code runs on the user's device and can be modified or bypassed. A user could directly call our API without using the frontend. Therefore, authorization must also be enforced on the backend.”

---

# 17. How does your notification system work?

### Answer:

> “When an important event happens, such as a booking being approved or rejected, the backend creates a notification record in MongoDB. The frontend retrieves the user's notifications and displays them in the notification area. Users can also mark notifications as read.”

### If asked: **“Is it real-time?”**

> “No. Currently it's not real-time. Notifications are fetched when the application requests them. A future improvement would be WebSockets or Server-Sent Events.”

Perfect. Don't pretend it's real-time.

---

# 18. Why didn't you use WebSockets?

### Answer:

> “The current requirements didn't require real-time communication, so we kept the implementation simpler. Since the system is relatively small, fetching notifications was sufficient. If real-time updates became important, I would consider WebSockets or SSE.”

---

# 19. How does your booking expiration system work?

### Answer:

> “We have a background service that periodically checks approved bookings whose end date and time have passed. Those bookings are marked as completed, and an email notification can be sent to the user.”

### Follow-up: **“How often does it run?”**

> “Currently, it runs approximately every hour using `setInterval`.”

### Follow-up: **“Is that production-grade?”**

> “It's acceptable for the current scale, but for a larger system I would use a proper job scheduler or queue because it would be more reliable across server restarts.”

---

# 20. What happens if the server restarts?

### Answer:

> “The application services can be restarted, but the in-memory timer for the expiration service would start again from the beginning. So an expiration check could be delayed by up to roughly an hour. A proper scheduled job would be a better solution for production.”

That's honest and technically defensible.

---

# 21. How do you handle email failures?

### Answer:

> “Email isn't part of the critical booking operation. If sending an email fails, the booking operation should still succeed. The email error is handled separately and logged.”

### Follow-up: **“Why?”**

> “Because a temporary email service failure shouldn't prevent a user from booking or an admin from approving a booking.”

---

# 22. How is validation handled?

### Answer:

> “We validate on both the frontend and backend. The frontend gives users immediate feedback, while the backend performs its own validation because API requests can bypass the frontend.”

Examples:

> “We validate booking dates, lab hours, booking duration, required fields and other project-specific rules.”

---

# 23. What booking rules does your system enforce?

### Answer:

> “The system prevents bookings in the past, bookings outside lab hours, bookings on closed days such as Sunday, and bookings beyond the allowed advance period. It also limits the maximum booking duration and checks for conflicts with existing bookings.”

Don't list every constant unless asked.

---

# 24. Why do you have validation in both frontend and backend?

### Answer:

> “Frontend validation improves user experience, but it isn't a security boundary. Backend validation is necessary because someone can directly send an API request without using our frontend.”

---

# 25. What HTTP status codes are important in your system?

### Answer:

> “We use 2xx responses for successful operations, 4xx responses for client-related problems, and 5xx for unexpected server errors. For example, 201 can be used when a booking is successfully created, 401 for authentication problems, 403 when the user doesn't have permission, 404 when a resource doesn't exist, and 409 when a booking conflicts with another booking.”

### Follow-up: **“401 vs 403?”**

> “401 means the request isn't properly authenticated. 403 means the user is authenticated but doesn't have permission.”

---

# 26. What indexes are important in your system?

Keep this answer simple.

> “The most important indexes are related to bookings because we frequently search for bookings by computer, status and date range. We also have indexes that help retrieve a user's bookings and notifications efficiently.”

### Follow-up: **“Why are indexes useful?”**

> “They allow the database to find relevant records more efficiently instead of scanning the entire collection.”

Don't start naming four compound indexes unless they specifically ask.

---

# 27. What would happen if you had 10 times more users?

### Answer:

> “The first things I'd look at are database query performance, pagination and indexing. The admin pages shouldn't load every booking at once. I'd also consider improving the notification system and moving the expiration task to a proper job scheduler. If traffic became much larger, we could run multiple backend instances behind a load balancer.”

That's a strong answer without pretending you're designing Amazon.

---

# 28. What is the biggest scalability issue in your current project?

### Answer:

> “One issue is that some admin data is fetched without pagination, so the amount of data returned could become large as bookings increase. Another limitation is that the expiration service currently runs inside the backend process.”

Pick **one** if they ask for one.

---

# 29. What happens if MongoDB goes down?

### Answer:

> “The backend won't be able to perform database operations, so requests that depend on MongoDB will fail. The application should return an appropriate server error rather than pretending the operation succeeded. Once MongoDB becomes available again, normal operations can resume.”

---

# 30. What happens if Firebase authentication is unavailable?

### Answer:

> “New authentication or verification of protected requests would be affected because our backend relies on Firebase to verify the user's token. However, the application data itself remains stored in MongoDB.”

Don't over-explain.

---

# 31. How is your frontend deployed?

### Answer:

> “The React application is built into static files, and in our deployment environment those files are served by Apache. The backend runs separately as a Node.js service, and Apache routes API requests to it.”

If asked **“Why Apache?”**

> “The university server already used Apache, so using it avoided introducing another web server just for this project.”

That's a perfectly reasonable answer.

---

# 32. Why did you use containers?

### Answer:

> “Containers make it easier to keep the backend and database environments consistent and isolated. It also makes deployment and restarting the services easier.”

If asked **“Docker or Podman?”**

> “We used Podman for the deployment environment.”

Then stop unless you know more.

---

# 33. What is the difference between frontend and backend validation?

### Answer:

> “Frontend validation is mainly for user experience—it tells the user immediately if something is wrong. Backend validation is for correctness and security because requests can be sent directly to the API.”

---

# 34. What happens if a user directly calls your booking API without using your React frontend?

### Answer:

> “The request still has to pass through the backend. The backend verifies authentication, validates the request and checks booking conflicts before creating anything. So the frontend isn't trusted as the security layer.”

🔥 Very good system-design answer.

---

# 35. What is one thing you would redesign?

### Answer:

> “I would replace the current hourly expiration mechanism with a proper job scheduler. I would also add real-time notifications and pagination for large booking lists.”

If they ask **“Why?”**

> “Those changes would make the system more reliable and scalable as the number of users and bookings grows.”

---

# 36. What is the most important design decision in your project?

I'd use this:

> “I think the most important design decision was separating authentication from application authorization. Firebase handles identity, while our backend and MongoDB handle application roles. This allowed us to use Firebase's authentication features without making Firebase responsible for all of our application-specific user data.”

That's a **very interview-friendly answer**.

---

# 37. What would happen if the same user opens two browser tabs and submits bookings?

### Answer:

> “Both requests would be handled independently by the backend. Each request would go through authentication, validation and the booking conflict check. The backend doesn't rely on frontend state to decide whether a booking is allowed.”

If they push on concurrency:

> “For strict guarantees under simultaneous requests, I'd strengthen the database-side transaction or concurrency handling.”

Again, **don't claim something your current implementation doesn't guarantee.**

---

# 38. What is the biggest weakness of your architecture?

### Answer:

> “The current system is designed for a relatively small environment, so some parts aren't optimized for large-scale traffic. For example, notifications aren't real-time, some lists don't have pagination, and the expiration service is tied to the backend process. These would be the first areas I'd improve.”

This answer is excellent because you're **showing awareness instead of pretending the project is perfect.**

---

# 39. If you had to rebuild this project, what would you change?

### Answer:

> “I would keep the overall architecture because it works well for this type of application. I would improve the backend by using TypeScript, add proper scheduled jobs for expiration, add pagination, and introduce real-time notifications. I would also strengthen database transactions around operations that involve multiple updates.”

---

# 40. Explain your architecture in 30 seconds.

This is the one I'd **memorize**.

> **“NEGCES is a full-stack lab booking application. The React and TypeScript frontend provides the user interface and communicates with a Node.js and Express backend through REST APIs. MongoDB stores users, computers, bookings and notifications, while Firebase handles authentication. The backend is responsible for validation, authorization and booking conflict detection. We also have background functionality for booking expiration and email notifications.”**

Then **stop talking**.

Let them ask.

---
