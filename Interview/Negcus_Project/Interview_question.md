## NEGCES Lab Tracking System — Interview-Safe Q&A

### 1. Tell me about your project.

**Answer:**

> “My project is called the NEGCES Lab Tracking System. It is a web application for managing computer lab bookings. Users can check available computers and request a booking for specific dates and times, while admins can manage computers and approve or reject booking requests. The main goal is to replace the manual booking process and prevent conflicts or double bookings.”

**If they ask:** *What technologies did you use?*

> “The frontend uses React with TypeScript, the backend uses Node.js and Express, MongoDB is used for storing application data, and Firebase is used for authentication.”

---

### 2. Can you explain the architecture of your project?

**Answer:**

> “It follows a client-server architecture. The React frontend handles the user interface, and it communicates with the Node.js and Express backend through REST APIs. The backend handles the business logic and communicates with MongoDB for storing and retrieving data. Firebase is used separately for user authentication.”

Simple flow:

```text
User
 ↓
React Frontend
 ↓
REST API
 ↓
Express Backend
 ↓
MongoDB
```

Firebase handles authentication alongside this flow.

---

### 3. Why did you choose React?

**Answer:**

> “We chose React because the application has multiple pages and reusable UI components, such as booking forms, dashboards and admin views. React's component-based structure makes it easier to organize and reuse these parts. It also works well with APIs, which we needed for communicating with our backend.”

---

### 4. Why TypeScript?

**Answer:**

> “We used TypeScript on the frontend mainly for type safety. The booking form has quite a few fields and data is passed between different components, so defining types helps catch mistakes during development.”

If they ask **“Why not JavaScript?”**

> “JavaScript would also work, but TypeScript gives better error checking and makes the code easier to maintain as the project grows.”

---

### 5. Why did you use Node.js and Express?

**Answer:**

> “We used Node.js with Express because we needed a lightweight backend for handling REST APIs and business logic. Express makes it simple to define routes and middleware. Also, using JavaScript-based technologies across the application made development easier for the team.”

---

### 6. Why MongoDB instead of MySQL or PostgreSQL?

**Answer:**

> “We chose MongoDB because our data is document-oriented and some information, such as computer specifications, can be stored naturally as part of a document. It also allowed us to develop quickly without having to create many relational tables and joins.”

If they ask **“Does MongoDB have relationships?”**

> “Yes. MongoDB can store references between documents, and with Mongoose we can use `populate()` when we need related data.”

---

### 7. How does authentication work?

**Answer:**

> “We use Firebase Authentication. When a user logs in, Firebase authenticates the user and provides an ID token. The frontend sends that token with requests to our backend. The backend verifies the token using Firebase Admin SDK. After verification, we use the Firebase UID to find the user's record in MongoDB.”

That's enough.

---

### 8. What is the difference between authentication and authorization?

**Answer:**

> “Authentication is about identifying who the user is. Authorization is about checking what that user is allowed to do. In our project, Firebase handles authentication, while our backend checks the user's role from MongoDB to handle authorization.”

This is a **very likely question**, so learn this properly.

---

### 9. How did you implement role-based access control?

**Answer:**

> “We have different roles, mainly user and admin. The user's role is stored in MongoDB. After the Firebase token is verified, the backend gets the user's MongoDB record and checks the role. Admin-only APIs use middleware to make sure the user has the admin role.”

If they ask:

**“Why check the role on the backend?”**

> “Because frontend checks can be bypassed. The backend must make the final authorization decision.”

🔥 **Remember this sentence.**

---

### 10. What happens when a user books a computer?

**Answer:**

> “First, the user selects a computer and provides the required booking details. The frontend validates the input and sends a request to the backend. The backend verifies the user's authentication, checks whether the computer is available for that period, and then creates the booking in MongoDB if there is no conflict. The response is then sent back to the frontend.”

---

### 11. How do you prevent double booking?

**Answer:**

> “Before creating a booking, the backend checks MongoDB for an existing pending or approved booking for the same computer whose date range overlaps with the requested booking. If a conflict is found, the backend rejects the request instead of creating another booking.”

If they ask:

**“How do you determine whether two date ranges overlap?”**

Say:

> “We check whether the existing booking starts before the new booking ends and whether it ends after the new booking starts.”

Conceptually:

```text
existing.start <= new.end
AND
existing.end >= new.start
```

---

### 12. What happens if the booking overlaps?

**Answer:**

> “The backend returns a conflict response instead of creating the booking. The frontend can then show the user that the selected period is unavailable.”

If they ask **“Why 409?”**

> “409 Conflict is appropriate because the request itself may be valid, but it conflicts with the current state of the resource.”

---

### 13. What is the temporary release feature?

**Answer:**

> “Suppose someone books a computer for 10 days but doesn't need it for 2 of those days. They can temporarily release those days. Another user can then book the computer during those released dates, while the original booking still remains active for the other dates.”

This is a great project-specific feature to talk about.

---

### 14. Why was temporary release difficult?

**Answer:**

> “The difficult part was that the original booking wasn't completely cancelled. Only some dates became available. So our conflict checking had to consider both the original booking dates and the dates that had been released. If the requested dates were released, another booking could be allowed.”

That's much safer than saying “three-layer architecture” etc.

---

### 15. What happens when a user books a temporarily released slot?

**Answer:**

> “The backend first finds the existing booking that overlaps with the requested dates. It then checks whether the requested dates were released from that booking. If the required dates were released, the new booking can be accepted; otherwise, it is treated as a conflict.”

---

### 16. How did you validate the booking form?

**Answer:**

> “We perform validation on the frontend for a better user experience, such as checking required fields, valid dates, lab hours and booking duration. But we also validate on the backend because frontend validation cannot be trusted for security.”

🔥 This is another very good sentence to remember.

---

### 17. What edge cases did you consider?

**Answer:**

> “We considered several cases such as booking in the past, booking on Sunday when the lab is closed, booking outside lab hours, booking more than 30 days in advance, exceeding the maximum booking duration, and overlapping with an existing booking.”

If they ask for more:

> “We also considered partially released bookings, where some dates are available but other dates are still occupied.”

---

### 18. How does your admin functionality work?

**Answer:**

> “Admins have additional access compared to normal users. They can manage booking requests and perform administrative operations such as managing computers. The backend checks the user's role before allowing admin-only operations.”

Don't say **“admins can do everything”** unless you've verified that.

---

### 19. How did you handle expired bookings?

**Answer:**

> “We have a backend service that periodically checks approved bookings whose end date and time have passed. Those bookings are marked as completed. We also send an email notification when a booking expires.”

If asked **“How often?”**

> “Currently, the service runs periodically using `setInterval`, approximately every hour.”

Then if they ask **“Is that ideal?”**

> “Not for a large production system. A proper job scheduler or queue would be more reliable because `setInterval` depends on the server process staying alive.”

That's a **great improvement answer**.

---

### 20. What happens if email sending fails?

**Answer:**

> “Email is not treated as part of the critical booking operation. The email sending is handled separately, so if the email service fails, the booking operation can still succeed. The error is logged so it can be investigated.”

---

### 21. What was the biggest challenge in your project?

Use the temporary release feature.

**Answer:**

> “The biggest challenge was handling temporary releases because a booking could be partially available. We couldn't simply mark the whole booking as cancelled. We had to check the individual released dates when determining whether another user could book the computer. Understanding and implementing that conflict logic was probably the most challenging part.”

Then if they ask:

**“How did you solve it?”**

> “We stored the released dates with the booking and checked those dates when processing a new booking request.”

---

### 22. What was your contribution to the project?

⚠️ **This one must match what you actually did.**

If the backend/booking work really was your contribution, you can say:

> “My main contribution was working on the booking-related backend logic. I worked on the booking conflict handling and temporary release functionality. I also worked on some frontend booking components and helped with deployment-related work.”

Don't claim deployment, migration, Apache, Podman, etc. unless **you personally understand and worked on them**.

---

### 23. What was one limitation of your project?

Pick **one or two**, not six.

**Answer:**

> “One limitation is that we don't currently have real-time notifications. For example, if an admin approves a booking, the user may need to refresh or reload the data to see the update. In the future, we could use WebSockets or another real-time mechanism to push these updates.”

That's a clean answer.

---

### 24. How would you improve the project?

**Answer:**

> “I would first add real-time notifications and pagination for the admin booking list. I would also replace the current periodic expiration check with a proper job scheduler. If the number of users increased significantly, I would look at database indexing, caching and running multiple backend instances.”

Don't start talking about sharding and distributed locks unless they ask.

---

### 25. What happens if two users try to book the same computer?

**Answer:**

> “Both requests reach the backend, and each booking request checks for an existing conflicting booking. Once a conflict exists, the request is rejected. So the normal case of a second user trying to book an already-booked slot is prevented.”

If they push:

> **“But what about both requests arriving at exactly the same time?”**

Don't bluff.

Say:

> “Our current implementation relies on the conflict check before insertion, but I would consider stronger database-level concurrency protection if we needed to guarantee correctness under high concurrent traffic.”

**This answer is much safer than claiming your query completely prevents race conditions.**

---

### 26. Why do you validate on both frontend and backend?

**Answer:**

> “Frontend validation gives immediate feedback to the user and improves the user experience. Backend validation is necessary because users can bypass the frontend and directly call the API. So the backend has to validate the request independently.”

---

### 27. What HTTP status codes do you use?

Know these:

| Code  | Meaning      | Example                        |
| ----- | ------------ | ------------------------------ |
| `200` | Success      | Booking retrieved/updated      |
| `201` | Created      | New booking                    |
| `400` | Bad Request  | Invalid input                  |
| `401` | Unauthorized | Missing/invalid authentication |
| `403` | Forbidden    | User isn't allowed             |
| `404` | Not Found    | Computer doesn't exist         |
| `409` | Conflict     | Booking overlaps               |
| `500` | Server Error | Unexpected backend error       |

If asked:

**“401 vs 403?”**

> “401 means the user isn't properly authenticated. 403 means the user is authenticated but doesn't have permission to perform that action.”

---

# Your safest project introduction

If the interviewer starts with:

> **“Tell me about your project.”**

I would use this:

> **“My project is the NEGCES Lab Tracking System, a full-stack web application for managing computer lab bookings. The main problem we wanted to solve was the manual process of reserving lab computers and handling booking conflicts. We built the frontend using React and TypeScript, the backend using Node.js and Express, and used MongoDB for storing the application data. Firebase is used for authentication. Users can request computers for specific dates and times, while admins can manage and approve bookings. One of the more challenging parts was handling temporary release, where a user can release only certain dates from an existing booking so that another user can use the computer during those dates.”**

**Then stop.**
