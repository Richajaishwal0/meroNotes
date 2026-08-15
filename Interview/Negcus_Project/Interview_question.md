Negses Lab Tracking System — Interview Q&A
Q1. What is this project about and what problem does it solve?

Answer: It's a full-stack web application called "Negses Lab Tracking System" that manages computer lab slot bookings. The problem it solves is the manual/unorganized process of reserving lab computers — students/users can request a booking for a specific computer at a specific time, and admins can approve or reject those requests. It eliminates double-booking and brings transparency to lab resource management.

Q2. Walk me through the tech stack and why you chose it.

Answer:

React + TypeScript (Vite) for the frontend — TypeScript adds type safety, Vite gives faster dev builds than CRA

Node.js + Express for the backend — lightweight, JavaScript throughout the stack (MERN), easy REST API setup

MongoDB + Mongoose — flexible schema for storing bookings and computer configs as JSON objects, no rigid relational structure needed

Firebase Authentication — offloads the complexity of password hashing, token management, and session handling; we get secure JWT tokens for free

MUI (Material UI) — pre-built accessible components, faster UI development

Formik + Yup — clean form state management and validation without boilerplate

Q3. How does authentication work in this system?

Answer: It's a hybrid approach. Firebase handles the actual auth (signup/login) on the client side and issues a JWT token. That token is sent in the Authorization: Bearer <token> header with every API request. On the backend, the verifyToken middleware calls firebase-admin.auth().verifyIdToken() to validate it. Once verified, we look up the user in MongoDB using the firebaseUid to get their role, and attach the full user document to req.user. This way Firebase handles security, and MongoDB handles our app-specific data like roles.

Q4. How is Role-Based Access Control (RBAC) implemented?

Answer: There are two roles — user and admin — stored in MongoDB's User model. The middleware has three functions: verifyToken (validates Firebase JWT), isAdmin (checks req.userRole === 'admin'), and isUser (checks role is either user or admin). Routes are protected by chaining these middlewares. On the frontend, ProtectedRoute component checks userRole from AuthContext and redirects unauthorized users. Admins can also access user-level routes since the check is requiredRole === 'user' && userRole === 'admin'.

Q5. How did you handle the double-booking / overlapping slots problem?

Answer: Before creating a booking, we query MongoDB for any existing booking on the same computer with status pending or approved that overlaps the requested time window. The overlap check uses three $or conditions:

An existing booking starts within the new time range

An existing booking ends within the new time range

An existing booking completely wraps around the new time range

If any overlap is found, we return a 409 Conflict response. This prevents race conditions at the database query level.

Q6. What were the main challenges you faced and how did you handle them?

Answer:

Token synchronization: Firebase token had to be fetched fresh before every API call since tokens expire. Solved by calling user.getIdToken() in the Axios interceptor.

Role not available immediately after registration: After Firebase signup, the user didn't exist in MongoDB yet, so getProfile would fail. Handled by registering the user in our backend right after Firebase signup in the register function of AuthContext.

Overlapping booking logic: Writing the correct MongoDB query for all three overlap scenarios was tricky. Tested manually with edge cases like exact boundary times.

File naming confusion: slot.js model was actually the Computer model — caused confusion during team collaboration. Resolved by adding comments and eventually renaming references.

Q7. What test cases would you write for the booking system?

Answer:

Happy path: User books a free computer for a valid time range → 201 created

Overlapping booking: Two users try to book the same computer at the same time → second gets 409

Invalid time: endTime before startTime → validation error

Non-existent computer ID → 404

Unauthenticated request → 401

User trying to access admin routes → 403

Admin approving an already-rejected booking → should handle gracefully

Empty reason field or reason less than 10 chars → Yup validation error on frontend

Q8. What are the edge cases in the booking overlap logic?

Answer:

Exact boundary match: booking from 10:00–11:00 and new booking from 11:00–12:00 — should NOT conflict (boundary is exclusive)

Same start and end time as existing booking — should conflict

New booking completely inside an existing one — should conflict

Existing booking completely inside new booking — should conflict (the third $or condition handles this)

Rejected bookings should not block new bookings — handled by filtering only pending and approved statuses

Q9. How did you divide work between the two teams?

Answer: The project was split into frontend and backend teams.

Backend team handled: Express server setup, MongoDB models (User, Booking, Computer), all API routes, Firebase Admin integration, auth middleware, and the makeAdmin.js utility script

Frontend team handled: React component structure, Firebase client-side auth, AuthContext, ProtectedRoute, all pages (Login, Register, Dashboard, BookingForm, AdminDashboard), API service layer using Axios, and MUI-based UI

Both teams collaborated on defining the API contract (request/response shapes) before implementation so frontend and backend could work in parallel.

Q10. Why MongoDB over a relational database like PostgreSQL for this project?

Answer: The computer config field stores varying hardware specs as a JSON object (CPU, RAM, storage, OS) — this is a natural fit for MongoDB's flexible document model. With a relational DB, you'd need a separate computer_specs table with joins. Also, the booking and user data don't have complex relational queries that would benefit from SQL joins. MongoDB's populate() handles the references we need. For a project of this scale, MongoDB reduces schema rigidity and speeds up development.

Q11. How does the frontend protect routes from unauthorized access?

Answer: The ProtectedRoute component wraps sensitive pages. It reads currentUser and userRole from AuthContext. If the user isn't logged in, it redirects to /login while preserving the intended destination in location.state. If a role is required (e.g., admin) and the user doesn't have it, they're redirected to /. The loading state prevents a flash of redirect before Firebase resolves the auth state on page refresh.

Q12. How is form validation handled on the frontend?

Answer: Formik manages form state and submission, and Yup handles the validation schema. For the booking form, reason must be at least 10 characters, and both startTime and endTime are required. Errors are shown inline using MUI's helperText and error props on TextField. The submit button is also disabled if no computer is selected — this is a UI-level guard separate from Yup validation.

Q13. If you had to scale this system, what improvements would you make?

Answer:

Add real-time notifications (WebSockets or Firebase Realtime DB) so users get instant updates when their booking is approved/rejected

Add pagination to the admin bookings table — currently fetches all bookings at once

Implement booking cancellation from the user side

Add time zone handling — currently stores UTC but doesn't account for user's local timezone explicitly

Rate limiting on the API to prevent abuse

Add indexes on MongoDB for computer + startTime + endTime fields to speed up the overlap query

Move the isAvailable flag update to be automatic based on approved bookings rather than manual admin toggle
