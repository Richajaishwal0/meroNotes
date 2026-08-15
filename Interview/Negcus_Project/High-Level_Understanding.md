# NEGCES Lab Management System — Project-Specific Interview Preparation

> **Goal:** Understand the project well enough to explain the **problem, architecture, authentication, booking logic, temporary release system, backend flow, and your contribution** in an interview.

---

# 1. Project in One Minute

## What is NEGCES?

NEGCES Lab Management System is a **full-stack web application for managing university lab computers**.

Imagine a university lab with 10–15 high-performance computers used for:

- AI/ML projects
- Data analysis
- Research
- Heavy computation

Without a centralized system, students may have to physically check computers or contact the lab administrator to reserve one.

### What does NEGCES solve?

It works like a **hotel booking system, but for lab computers**.

Users can:

1. Log in.
2. Browse lab computers.
3. Check hardware/software specifications.
4. Check availability.
5. Submit a booking request.
6. Provide project and dataset details.
7. Wait for admin approval.
8. Receive notifications and emails.
9. Temporarily release unused dates from a long booking.

Admins can:

- View booking requests.
- Approve/reject bookings.
- Manage computers.
- Update computer specifications.
- Mark machines under maintenance.
- Manage temporary releases.

The project therefore combines **resource management + booking + authentication + authorization + notifications**.

---

# 2. The Main Users

## Regular Users

Regular users are **students and faculty**.

They can:

- Register/login.
- Browse computers.
- View hardware specifications.
- View availability.
- Submit booking requests.
- Provide project details.
- Receive booking notifications.
- Temporarily release selected dates from an approved booking.

## Admins

Admins manage the lab.

They can:

- View all booking requests.
- Approve bookings.
- Reject bookings.
- Provide rejection reasons.
- Add/edit/delete computers.
- Update computer specifications.
- Mark computers under maintenance.
- View bookings across computers.
- Create/manage temporary releases.

> **Important consistency point:** The MongoDB role model actually has `user` and `admin`. Students and faculty are both represented as `user`; their distinction is handled through institutional email/domain validation rather than separate MongoDB roles. fileciteturn0file0L278-L281

---

# 3. Complete User Journey

## Step 1 — Registration/Login

The user can register/login using:

- Email/password
- Google
- Microsoft

The system requires an Amrita institutional email for booking-related access.

After registration:

```text
Register
   ↓
Firebase creates/authenticates user
   ↓
Verification email
   ↓
User verifies email
   ↓
Application can be used
```

---

# 4. Step 2 — Browse the Lab

Users do not necessarily need to log in just to view lab information.

They can see:

- Computer availability
- Computer status
- Hardware specifications
- Software installed
- Booking timeline/calendar

Computer statuses include concepts such as:

```text
Available
Reserved
Maintenance
```

For each computer, users can inspect:

```text
Operating System
CPU
RAM
GPU
Installed Software
Location
```

This helps users decide which computer is suitable for their project.

---

# 5. Step 3 — Make a Booking

The booking process is a **4-step wizard**.

## Step 1 — Select Computer

The user chooses a computer.

Computers that are:

- Reserved
- Under maintenance

cannot be selected.

---

## Step 2 — Select Date and Time

The user chooses:

- Start date
- End date
- Start time
- End time

The application validates booking rules.

### Booking Rules

| Rule | Value |
|---|---|
| Lab opening time | 8:30 AM |
| Lab closing time | 5:30 PM |
| Minimum booking | 1 hour |
| Maximum booking | 15 days |
| Maximum advance booking | 30 days |
| Sunday | Not allowed |

There is also a **Full Day** option that automatically selects:

```text
8:30 AM → 5:30 PM
```

---

# 6. Step 3 — Project Details

The user provides information about why the resource is required.

Examples:

### Research Problem

What problem is the user trying to solve?

### Dataset

The user specifies:

- Dataset type
- Dataset size
- Dataset link

Dataset types may include:

```text
Image
Video
Audio
Satellite
Text
```

### GPU Requirements

The user provides information such as:

- Whether they already have a GPU
- GPU memory
- Why their current machine is insufficient

This is essentially a **bottleneck explanation**.

### Mentor

The user provides mentor information.

---

# 7. Step 4 — Review and Submit

Before submitting, the user sees a summary of:

- Computer
- Date
- Time
- Project details
- Dataset
- GPU requirements

The user must accept the Terms and Conditions.

Then the booking is submitted.

---

# 8. What Happens After Booking?

The booking initially becomes:

```text
PENDING
```

Then:

```text
User submits booking
        ↓
Booking = PENDING
        ↓
Admins receive notification
        ↓
Admin reviews request
        ↓
       / \
      /   \
 Approve  Reject
    |       |
    ↓       ↓
APPROVED  REJECTED
```

If approved:

- User gets an in-app notification.
- User gets an email.

If rejected:

- Admin provides a reason.
- User receives the rejection reason through notification/email.

---

# 9. Booking Status Lifecycle

Understand this clearly.

```text
                 ┌──────────────┐
                 │    PENDING   │
                 └──────┬───────┘
                        │
             ┌──────────┴──────────┐
             ↓                     ↓
        ┌──────────┐          ┌──────────┐
        │ APPROVED │          │ REJECTED │
        └────┬─────┘          └──────────┘
             │
       ┌─────┴─────┐
       ↓           ↓
  Expiration    Free System
       │           │
       └─────┬─────┘
             ↓
       ┌───────────┐
       │ COMPLETED │
       └───────────┘
```

There can also be cancellation paths:

```text
PENDING → CANCELLED
APPROVED → CANCELLED
```

The important point is that booking status represents the **lifecycle of a resource reservation**.

---

# 10. During an Approved Booking

The user uses the computer during the approved slot.

If the user finishes early, they can use:

```text
Free System
```

This marks the booking as completed early and notifies admins that the computer is available again.

---

# 11. Automatic Booking Expiration

The system should not depend on admins manually completing every booking.

A background service runs approximately **every hour**.

```text
Background service
       ↓
Find approved bookings
       ↓
Check end date/time
       ↓
Has booking expired?
       ↓
      YES
       ↓
Mark as COMPLETED
       ↓
Send expiry email
```

The service also runs once when the server starts.

Conceptually:

```javascript
setInterval(checkExpiredBookings, 60 * 60 * 1000);
checkExpiredBookings();
```

This makes the system self-maintaining.

---

# 12. The Most Important Technical Feature: Temporary Release

This is the feature you should understand especially well.

## The Problem

Suppose:

```text
Computer A
Booked: August 10 → August 19
```

The user needs it for a research project.

But the user will be away on:

```text
August 13
August 14
```

They do **not** want to cancel their entire 10-day booking.

Instead, they can temporarily release those dates.

---

# 13. Temporary Release Example

Original booking:

```text
Computer A
August 10 → August 19
```

Released dates:

```text
August 13
August 14
```

Now the system treats those dates as available to other users.

Another user can request:

```text
Computer A
August 13
```

The backend detects:

```text
There is an existing booking
        ↓
But the requested date was released
        ↓
Therefore the conflict is resolved
        ↓
Allow temporary booking
```

This is much more interesting than a basic CRUD booking system.

---

# 14. Temporary Release Data Model

Released dates are stored inside the original booking document.

Conceptually:

```javascript
booking.temporaryRelease.releasedDates = [
    {
        date: "2024-08-13",
        isBooked: false,
        tempBookingId: null
    },
    {
        date: "2024-08-14",
        isBooked: false,
        tempBookingId: null
    }
];
```

When another user books a released date:

```text
isBooked = true
tempBookingId = new booking ID
```

---

# 15. Why Store Released Dates Inside the Booking?

Instead of querying a completely separate collection every time, the released dates are embedded inside the original booking.

This makes conflict checking easier because the backend can inspect:

```text
Existing booking
      ↓
temporaryRelease
      ↓
releasedDates
```

during the same conflict-resolution process.

---

# 16. Temporary Release Conflict Logic

This is a very important interview flow.

```text
New booking request
        ↓
Find bookings for same computer
        ↓
Check overlapping dates
        ↓
Is there an existing conflict?
        ↓
      YES
        ↓
Check temporary released dates
        ↓
Are ALL requested conflicting dates released?
       / \
     YES  NO
      |    |
      ↓    ↓
  Allow   Reject
 booking  conflict
```

The key idea:

> An overlapping booking is not automatically a conflict. The backend must check whether the requested dates were temporarily released.

---

# 17. Why This Is Harder Than Normal Booking

A simple booking application might do:

```text
Is computer already booked?
    ↓
Yes → Reject
```

But NEGCES has to consider:

```text
Same computer?
       ↓
Overlapping dates?
       ↓
Overlapping times?
       ↓
Are conflicting dates temporarily released?
       ↓
Is the release already occupied?
       ↓
Final decision
```

Therefore, the booking system needs **date/time conflict resolution**, not just a simple availability flag.

---

# 18. Tech Stack

| Technology | Purpose |
|---|---|
| React | Frontend UI |
| Vite | Frontend build/development tool |
| TypeScript | Type safety |
| Material UI | UI components |
| Axios | Frontend → backend HTTP requests |
| Firebase Auth | Authentication |
| Node.js | Backend runtime |
| Express | REST API/backend framework |
| MongoDB | Database |
| Mongoose | MongoDB object modeling |
| Nodemailer | Email sending |
| Gmail SMTP | Email delivery |
| Docker | Containerization |
| Docker Compose | Run multiple services |
| Nginx | Production reverse proxy |

The original project notes describe these technologies and their purposes. fileciteturn0file0L113-L124

---

# 19. Architecture

The simplest architecture to remember is:

```text
                    USER
                     |
                     ↓
              React Frontend
              React + Vite
                     |
              Axios + JWT
                     |
                     ↓
             Node + Express
                     |
          ┌──────────┴──────────┐
          ↓                     ↓
      MongoDB              Firebase Auth
   Application Data          Identity
          |
          ↓
   Background Services
          |
     Email / Expiration
```

---

# 20. Frontend Responsibilities

The frontend handles:

- User interface
- Forms
- Booking wizard
- Computer grid
- Availability display
- Dashboard
- Admin dashboard
- Protected navigation
- Authentication state
- Notifications
- API integration

Important frontend structure:

```text
client/src/

main.tsx
App.tsx

config/
    firebase.ts

services/
    api.ts

contexts/
    AuthContext.tsx
    NotificationContext.tsx
    ThemeContext.tsx

components/
    ProtectedRoute.tsx
    MainLayout.tsx
    Layout.tsx

pages/
    Login.tsx
    Register.tsx
    Dashboard.tsx
    BookingForm.tsx
    ComputerGrid.tsx
    AdminDashboard.tsx
    AdminComputerManagement.tsx
    AdminTemporaryReleases.tsx
    SystemDetails.tsx
```

---

# 21. Backend Responsibilities

The backend is responsible for:

- Authentication verification
- Authorization
- Business rules
- Booking logic
- Conflict detection
- Database operations
- Notifications
- Emails
- Booking expiration
- Admin operations

Important backend structure:

```text
server/

index.js

middleware/
    auth.js

models/
    user.js
    booking.js
    computer.js
    notification.js
    temporaryRelease.js

routes/
    auth.js
    bookings.js
    computers.js
    notifications.js
    temporaryReleases.js
    feedback.js
    systemDetails.js

services/
    bookingExpirationService.js
    emailService.js

shared/
    policy.js
```

---

# 22. Authentication — The Most Important Interview Topic

NEGCES uses a **dual-system authentication/authorization design**.

The two systems are:

```text
Firebase
   +
MongoDB
```

They have different responsibilities.

---

# 23. What Firebase Does

Firebase handles:

- Login
- Registration
- Email/password authentication
- Google login
- Microsoft login
- Email verification
- Identity verification
- ID token generation

The reason for using Firebase is that implementing secure authentication and OAuth from scratch would be unnecessary and risky.

---

# 24. What MongoDB Does

MongoDB stores application-specific information.

For example:

```text
firebaseUid
email
name
role
```

Firebase tells us:

> "This user is authenticated and their UID is X."

MongoDB tells us:

> "User X has this application account and role."

---

# 25. Complete Authentication Flow

Memorize this:

```text
1. User logs in
        ↓
2. Firebase authenticates user
        ↓
3. Firebase issues ID token
        ↓
4. Frontend gets token
        ↓
5. Axios attaches token to API request
        ↓
6. Backend receives:
   Authorization: Bearer <token>
        ↓
7. Express auth middleware extracts token
        ↓
8. Firebase Admin verifies token
        ↓
9. Backend gets Firebase UID
        ↓
10. MongoDB finds user using firebaseUid
        ↓
11. Backend gets role
        ↓
12. req.user and req.userRole are set
        ↓
13. Route continues if authorized
```

This is the single most important flow to understand.

The source describes the same dual-system flow: Firebase verifies identity and provides the token, while MongoDB is queried using `firebaseUid` to determine the role. fileciteturn0file0L125-L151

---

# 26. Authentication vs Authorization

This is a common interview question.

## Authentication

Answers:

> **Who are you?**

Example:

```text
Firebase verifies the user's identity.
```

## Authorization

Answers:

> **What are you allowed to do?**

Example:

```text
Is this user an admin?
Can this user approve bookings?
Can this user modify computers?
```

### In NEGCES

```text
Firebase
   ↓
Authentication

MongoDB + Backend Middleware
   ↓
Authorization
```

---

# 27. Why Can't We Trust the Frontend?

Suppose the frontend says:

```javascript
if (userRole === "admin") {
    showAdminPage();
}
```

That does **not** secure the system.

Why?

Because the frontend runs inside the user's browser.

A malicious user can:

- Modify JavaScript
- Open DevTools
- Change variables
- Directly call the API using Postman/curl

Therefore:

```text
Frontend security checks
        ≠
Actual API security
```

The backend must independently:

1. Verify the Firebase token.
2. Identify the user.
3. Check the role.
4. Allow/deny the operation.

The source explicitly emphasizes that `ProtectedRoute` is primarily for navigation/user experience, while the backend is the real security boundary. fileciteturn0file0L262-L264

---

# 28. Axios Interceptor

Instead of manually attaching the Firebase token to every request, the project uses a central Axios instance.

Conceptually:

```text
React component
      ↓
Axios request
      ↓
Axios interceptor
      ↓
Get current Firebase user
      ↓
Get fresh ID token
      ↓
Add Authorization header
      ↓
Backend
```

The header looks like:

```text
Authorization: Bearer <Firebase-ID-Token>
```

This means components don't need to repeat authentication logic.

The project notes describe the interceptor as getting a fresh Firebase token and automatically adding it to requests. fileciteturn0file0L270-L272

---

# 29. ProtectedRoute

The frontend has:

```text
ProtectedRoute.tsx
```

Its purpose is to control navigation.

Conceptually:

```text
User opens protected page
        ↓
Authenticated?
    /       \
  NO         YES
  ↓           ↓
Login     Email verified?
              /    \
            NO      YES
            ↓        ↓
       Verify page   Check role
                       |
                  Authorized?
                    /    \
                  NO      YES
                  ↓        ↓
                Home      Page
```

Again:

> `ProtectedRoute` improves frontend behavior. Backend middleware provides actual API security.

---

# 30. Booking API Flow

Suppose a user clicks **Submit Booking**.

```text
BookingForm.tsx
      ↓
Axios
      ↓
Firebase JWT attached
      ↓
POST /api/bookings
      ↓
Authentication middleware
      ↓
Verify Firebase token
      ↓
Find MongoDB user
      ↓
Check authorization
      ↓
Validate booking policy
      ↓
Check booking conflicts
      ↓
Check temporary releases
      ↓
Create/update MongoDB booking
      ↓
Create notifications
      ↓
Send email if required
      ↓
Return response
      ↓
React updates UI
```

---

# 31. Booking Conflict Detection

When a booking request arrives, the backend:

### Step 1

Finds existing:

```text
PENDING
APPROVED
```

bookings for the same computer.

### Step 2

Checks date overlap.

### Step 3

For overlapping dates, checks time overlap.

### Step 4

If there is a conflict, checks temporary releases.

### Step 5

Only rejects when there is a genuine unresolved conflict.

This is the core booking logic described in the source. fileciteturn0file0L153-L167

---

# 32. Example of Date/Time Conflict

Existing booking:

```text
Computer A
10 Aug → 15 Aug
10:00 → 14:00
```

New booking:

```text
Computer A
12 Aug → 13 Aug
11:00 → 13:00
```

The dates overlap.

The times also overlap.

Therefore:

```text
CONFLICT
```

But if the conflicting dates were temporarily released:

```text
12 Aug → Released
13 Aug → Released
```

then the system can resolve the apparent conflict.

---

# 33. Shared Business Policy

File:

```text
shared/policy.js
```

Contains rules such as:

```text
Lab hours      = 08:30–17:30
Minimum        = 1 hour
Maximum        = 15 days
Advance limit  = 30 days
Sunday         = Not allowed
```

Both frontend and backend use these rules.

---

# 34. Why Validate on Both Frontend and Backend?

Frontend validation gives immediate feedback.

Example:

```text
User selects 7:00 AM
       ↓
Frontend immediately says:
"Lab opens at 8:30 AM"
```

But frontend validation alone is not secure.

A user could bypass it and send:

```text
POST /api/bookings
```

directly.

Therefore:

```text
Frontend validation
       ↓
Better UX

Backend validation
       ↓
Actual enforcement
```

This is called **defense in depth**.

The project source explicitly describes this frontend + backend validation approach. fileciteturn0file0L169-L182

---

# 35. MongoDB Data Model

## User

Conceptually:

```text
User
├── firebaseUid
├── email
├── name
└── role
```

---

## Booking

Contains concepts such as:

```text
Booking
├── computer
├── user
├── start/end date
├── start/end time
├── status
├── GPU requirements
├── dataset information
├── project/problem statement
└── temporary release
```

---

## Computer

```text
Computer
├── name
├── location
├── status
├── operating system
├── CPU
├── RAM
├── GPU
└── installed software
```

---

## Notification

```text
Notification
├── user
├── type
├── message
└── read
```

---

# 36. Why MongoDB?

A good interview answer:

> "MongoDB was suitable because our booking documents contain flexible and nested information such as project details, GPU requirements, dataset information, and temporary release data. A document-oriented structure maps naturally to this data. We can keep related booking information together rather than splitting it across many relational tables."

The source specifically highlights nested booking data and embedded temporary-release information as reasons for choosing MongoDB. fileciteturn0file0L258-L260

---

# 37. Why MERN?

A good answer:

> "We used the MERN stack because React gives us a component-based frontend, Express and Node.js provide a lightweight REST backend, and MongoDB works naturally with JavaScript objects and flexible application data. It also allowed us to use JavaScript/TypeScript across most of the application."

---

# 38. Notification System

There are two different notification mechanisms.

## In-App Notifications

Users see notifications inside the application.

Examples:

```text
Booking submitted
Booking approved
Booking rejected
Booking cancelled
```

The frontend has:

```text
NotificationContext.tsx
```

It manages:

- Fetching notifications
- Unread count
- Marking notifications as read

## Email Notifications

Nodemailer sends email for important booking events.

---

# 39. Email System

File:

```text
server/services/emailService.js
```

Uses:

```text
Nodemailer
      ↓
Gmail SMTP
```

Important email types:

```text
Booking Approved
Booking Rejected
Booking Cancelled
Booking Expired
```

For rejected bookings, the rejection reason is included.

An important design point is that email failure does not necessarily fail the booking operation; the error is logged while the main booking operation can still succeed. fileciteturn0file0L237-L248

---

# 40. Background Service

File:

```text
server/services/bookingExpirationService.js
```

Purpose:

> Automatically complete bookings whose end time has passed.

Flow:

```text
Server starts
     ↓
Expiration service starts
     ↓
Check immediately
     ↓
Check every hour
     ↓
Find approved + expired bookings
     ↓
Mark completed
     ↓
Send expiry email
```

---

# 41. Docker

The project uses:

```text
Docker
Docker Compose
```

Docker packages application components into containers.

Conceptually:

```text
Docker Compose
│
├── MongoDB
├── Backend
└── Frontend
```

The benefit is consistent environments.

Instead of saying:

> "Install Node, MongoDB, configure everything manually..."

you can use the container configuration to start the required services consistently.

---

# 42. Nginx

Nginx is used as a production reverse proxy.

The routing is conceptually:

```text
User
  ↓
Nginx
  ├── /negces/ → Frontend
  └── /api/    → Backend
```

This lets the frontend and backend work behind the same production server while keeping API routing separate.

---

# 43. Your Role in the Project

Your resume says:

> **Worked in a 2-member team, handling backend logic and frontend integration.**

So your explanation should focus on:

## Backend

Be ready to discuss:

- Express routes
- Authentication middleware
- MongoDB interaction
- Booking APIs
- Booking validation
- Conflict detection
- Temporary release logic
- Notifications
- Email triggers

## Frontend Integration

Be ready to discuss:

- React components
- Axios integration
- Authentication state
- Protected routes
- Booking form integration
- Availability display
- Handling API responses
- Error handling

### Very Important

Do not claim that you personally implemented something if your teammate did it.

If the interviewer asks:

> "What exactly did YOU do?"

give a specific answer based on your actual contribution.

---

# 44. The 10 Questions You MUST Know

## Q1. Explain your project.

### Answer

> "NEGCES is a full-stack lab management and computer booking system. It allows students and faculty to browse lab computers, check their hardware and availability, and submit booking requests with project and dataset details. Admins can approve or reject bookings and manage the lab computers.
>
> We used React with Vite and TypeScript for the frontend, Node.js and Express for the backend, MongoDB for application data, and Firebase for authentication. One interesting feature is temporary release, where a user can release selected dates from a longer booking so another user can use the computer during those dates. We also implemented automatic booking expiration and email notifications."

---

# Q2. Why Firebase + MongoDB?

### Answer

> "Firebase handles identity and authentication, including login, OAuth, email verification, and token management. MongoDB stores application-specific information such as the user's role and booking-related data. We connect the two using the Firebase UID."

---

# Q3. How does authentication work?

### Answer

```text
Login
 ↓
Firebase
 ↓
ID Token
 ↓
Axios interceptor
 ↓
Authorization header
 ↓
Express middleware
 ↓
verifyIdToken()
 ↓
Firebase UID
 ↓
MongoDB role lookup
 ↓
Authorized route
```

---

# Q4. Authentication vs authorization?

### Answer

> "Authentication verifies who the user is. Authorization determines what that user is allowed to do. In our system, Firebase handles identity verification, while the backend uses the MongoDB role to enforce application permissions."

---

# Q5. How does booking conflict detection work?

### Answer

> "When a booking request comes in, the backend first finds pending or approved bookings for the same computer. It checks whether the date ranges overlap and then checks whether the time ranges overlap. If there is an apparent conflict, it checks whether the requested dates were temporarily released. Only if there is an unresolved conflict does it reject the booking."

---

# Q6. Explain temporary release.

### Answer

> "Suppose a user books a computer for ten days but doesn't need it for two of those days. Instead of cancelling the entire booking, they can temporarily release those two dates. Those dates are stored with the original booking. When another user requests one of those dates, the backend checks the release information and can allow the new booking if the requested dates are available."

---

# Q7. Why not trust frontend validation?

### Answer

> "Frontend validation is mainly for user experience. Since frontend code runs in the user's browser, it can be modified or bypassed. Therefore, the backend independently validates the booking rules and authorization before modifying the database."

---

# Q8. Why MongoDB?

### Answer

> "Our booking data contains nested and flexible information such as project details, GPU requirements, dataset information, and temporary release dates. MongoDB's document model fits this structure naturally."

---

# Q9. What was the hardest part?

### Answer

> "The most challenging part was the temporary-release conflict detection. It wasn't enough to check whether a computer had an existing booking. We had to determine whether the requested dates and times actually conflicted and whether those dates had been released. Making that logic work correctly required careful handling of overlapping bookings."

---

# Q10. What would you improve?

### Answer

> "I would add WebSocket-based real-time availability so that users immediately see when a computer becomes available or gets booked. I would also replace notification polling with push-based notifications and add rate limiting to sensitive APIs such as booking creation."

These improvements are consistent with the project's stated future-improvement direction. fileciteturn0file0L274-L276

---

# 45. Advanced Questions You May Get

Prepare these after the basics:

1. How do you calculate overlapping date ranges?
2. How do you calculate overlapping time ranges?
3. How would you prevent race conditions if two users book simultaneously?
4. Why is the backend the security boundary?
5. How does Firebase Admin SDK differ from Firebase client SDK?
6. Why use an Axios interceptor?
7. What happens if the Firebase token expires?
8. Why embed temporary releases inside the booking?
9. How would you scale the expiration service?
10. What happens if the server goes down?
11. Why use Docker Compose?
12. Why use Nginx?
13. How would you add WebSockets?
14. How would you implement rate limiting?
15. What indexes would you create in MongoDB?
16. How would you improve booking concurrency?
17. What happens if email sending fails?
18. How would you test the booking conflict logic?
19. How would you secure admin endpoints?
20. What would you change if the application had 10,000 users?

---

# 46. Important Consistency Issue in Your Resume

Your resume currently says:

> **"3 user roles: admin, faculty, and student"**

But the project details indicate the actual MongoDB roles are:

```text
user
admin
```

Students and faculty both use:

```text
role = user
```

The distinction is handled through institutional email/domain validation rather than separate permission roles. fileciteturn0file0L278-L281

## What to say if asked

> "In the application, students and faculty are both represented by the user role because they have the same system permissions. The system distinguishes them at the booking/form level using their institutional email domain. Admin is the separate elevated role."

### Do NOT say:

> "MongoDB has three roles: admin, faculty, student."

unless that is actually how your code is implemented.

---

# 47. Another Important Point: "Real-Time Availability"

Your resume says:

> **real-time availability tracking**

Be careful with the word **real-time**.

The project notes say availability is currently fetched on page load, and WebSockets are a future improvement. fileciteturn0file0L274-L276

Therefore, if asked:

> "Did you use WebSockets?"

Answer:

> "No. We currently fetch the latest availability from the backend. We did not implement WebSocket-based live synchronization. That's one improvement I would make in the future."

This is safer and technically accurate.

---

# 48. Project Architecture to Memorize

Memorize this one line:

```text
React/Vite
    ↓
Axios + Firebase ID Token
    ↓
Node.js + Express
    ↓
Firebase Token Verification
    ↓
MongoDB User/Role Lookup
    ↓
Booking Business Logic
    ↓
MongoDB
    ↓
Notifications + Email
```

And for background processing:

```text
Booking Expiration Service
        ↓
Every Hour
        ↓
Find Expired Bookings
        ↓
Mark Completed
        ↓
Send Email
```

---

# 49. Project Explanation — 30 Seconds

> "NEGCES is a full-stack lab management system that allows students and faculty to browse lab computers, check their specifications and availability, and request time slots for research or computational work. Admins manage the computers and approve or reject booking requests. We used React, Node.js, Express, MongoDB, and Firebase. A key feature is temporary release, where users can release unused dates from longer bookings so others can use those slots. We also implemented automatic booking expiration and email notifications."

---

# 50. Project Explanation — 1–2 Minutes

> "NEGCES is a full-stack lab management and resource booking system designed for university labs with high-performance computers.
>
> The problem we were solving was that students and researchers need access to specialized lab machines, but manually checking availability or contacting an administrator is inefficient. Our system lets users browse computers, view hardware and software specifications, check availability, and submit booking requests.
>
> The frontend was built using React, Vite, TypeScript, and Material UI. The backend uses Node.js and Express, while MongoDB stores application data. Firebase handles authentication, including email/password, Google, and Microsoft login.
>
> Authentication uses a dual-system approach. Firebase verifies the user's identity and provides an ID token. The frontend sends that token with API requests through an Axios interceptor. The backend verifies the token using Firebase Admin SDK, gets the Firebase UID, and then looks up the corresponding user in MongoDB to determine the user's role.
>
> The main business logic is the booking system. The backend validates lab policies such as operating hours, maximum booking duration, advance-booking limits, and Sundays. It also detects overlapping bookings. One of our more advanced features is temporary release, where a user can release specific dates from a longer booking so another user can book those dates.
>
> We also have an hourly background service that automatically marks expired bookings as completed and sends an email notification using Nodemailer. The application is containerized using Docker and uses Nginx as a production reverse proxy.
>
> I worked in a two-member team, mainly focusing on backend logic and frontend integration."

---

# 51. Final Mental Model

Think about the project as **5 connected systems**:

```text
┌────────────────────────────────────────────┐
│ 1. AUTHENTICATION                          │
│ Firebase → Identity + Token                │
└─────────────────────┬──────────────────────┘
                      ↓
┌────────────────────────────────────────────┐
│ 2. AUTHORIZATION                           │
│ MongoDB Role → What user can do            │
└─────────────────────┬──────────────────────┘
                      ↓
┌────────────────────────────────────────────┐
│ 3. BOOKING ENGINE                          │
│ Policy + Conflict Detection + Releases     │
└─────────────────────┬──────────────────────┘
                      ↓
┌────────────────────────────────────────────┐
│ 4. RESOURCE MANAGEMENT                     │
│ Computers + Availability + Admin           │
└─────────────────────┬──────────────────────┘
                      ↓
┌────────────────────────────────────────────┐
│ 5. AUTOMATION + NOTIFICATIONS              │
│ Expiration + In-App Notifications + Email  │
└────────────────────────────────────────────┘
```

If you understand these **five systems and how data moves between them**, you can answer most project-specific interview questions.

---

# 52. Final Revision Checklist

Before the interview, make sure you can explain these without reading:

- [ ] What problem does NEGCES solve?
- [ ] Who are the users?
- [ ] What can an admin do?
- [ ] What can a regular user do?
- [ ] Why did you use React?
- [ ] Why did you use Node/Express?
- [ ] Why MongoDB?
- [ ] Why Firebase?
- [ ] Authentication vs authorization
- [ ] Firebase ID token
- [ ] Axios interceptor
- [ ] `verifyIdToken()`
- [ ] Firebase UID → MongoDB user
- [ ] Role-based authorization
- [ ] ProtectedRoute
- [ ] Why frontend cannot be trusted
- [ ] Booking flow
- [ ] Booking status lifecycle
- [ ] Booking policy
- [ ] Conflict detection
- [ ] Date overlap
- [ ] Time overlap
- [ ] Temporary release
- [ ] Why temporary release is difficult
- [ ] Booking expiration service
- [ ] Nodemailer
- [ ] Notifications
- [ ] Docker
- [ ] Docker Compose
- [ ] Nginx
- [ ] Your exact contribution
- [ ] Biggest challenge
- [ ] Future improvements
- [ ] Faculty/student vs user/admin role distinction
- [ ] Real-time availability vs WebSockets

---

# 53. The Most Important Flow to Memorize

If you only revise **one thing**, revise this:

```text
USER
 ↓
Login with Firebase
 ↓
Firebase verifies identity
 ↓
Firebase gives ID Token
 ↓
React + Axios sends token
 ↓
Express receives request
 ↓
Firebase Admin verifies token
 ↓
Get Firebase UID
 ↓
Find user in MongoDB
 ↓
Get role
 ↓
Check authorization
 ↓
Validate booking policy
 ↓
Check booking conflicts
 ↓
Check temporary releases
 ↓
Save booking in MongoDB
 ↓
Notification / Email
 ↓
Response to React
```

That flow connects almost every important concept in the project.
