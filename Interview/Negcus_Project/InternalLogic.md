# NEGCES — Deep Internal Logic & Code-Level Understanding

> **This document intentionally skips the basic project introduction, feature list, tech-stack explanation, and simple user flow.**
>
> The purpose here is to understand **what the code is actually doing internally**, why fields exist, what happens inside requests, how data changes, and what edge cases/interview questions can expose whether you really understand the implementation.

---

# 1. The Core Mental Model: A Booking Is Not Just "Available / Unavailable"

The most important thing to understand is that the system does **not** treat a computer as simply:

```text
available = true/false
```

Availability is calculated from several pieces of information:

```text
computer
   |
   +-- current status
   |
   +-- existing bookings
   |      |
   |      +-- pending
   |      +-- approved
   |      +-- cancelled
   |      +-- completed
   |
   +-- temporary releases inside approved bookings
   |
   +-- requested date/time
```

So the real question asked by the backend is:

> "Does this requested interval overlap a relevant booking, and if it does, can the overlap be legally resolved because the conflicting dates were released?"

That is much more important than knowing that there is a booking form.

---

# 2. What Actually Happens When `POST /api/bookings` Arrives

Think of the request as passing through several gates.

```text
HTTP request
    |
    v
Firebase token verification
    |
    v
req.user available
    |
    v
Validate request body
    |
    v
Validate shared lab policy
    |
    v
Find relevant bookings
    |
    v
Detect date/time overlap
    |
    +---- no conflict ----> create booking
    |
    +---- conflict --------> inspect temporary releases
                              |
                              +-- fully resolvable --> create temporary booking
                              |
                              +-- unresolved --------> reject
```

The important distinction is:

**Frontend conflict detection is only a convenience. Backend conflict detection is the actual authority.**

A user can bypass React completely and send a request manually, so the server must repeat the important rules.

---

# 3. Authentication Internally: Firebase UID Is the Bridge

The application deliberately splits identity from application data.

Firebase knows:

```text
Who is the person?
Is the token valid?
Is the email verified?
```

MongoDB knows:

```text
What application user corresponds to this Firebase account?
What is their role?
```

The bridge is:

```text
Firebase UID
     |
     v
MongoDB User.firebaseUid
```

## Backend middleware conceptually

```js
const decoded = await firebaseAdmin
    .auth()
    .verifyIdToken(token);

const user = await User.findOne({
    firebaseUid: decoded.uid
});

req.user = user;
req.userRole = user.role;
```

So the backend does **not** trust a role sent by the browser.

It derives the role from its own MongoDB record.

That is the important security property.

---

# 4. Why `firebaseUid` Instead of MongoDB `_id`?

The booking stores:

```text
userId = Firebase UID
```

instead of:

```text
userId = MongoDB ObjectId
```

This is deliberate because Firebase is the identity provider.

The relationship becomes:

```text
Firebase
uid = ABC123
      |
      v
User.firebaseUid = ABC123
      |
      v
Booking.userId = ABC123
```

This also explains the Mongoose virtual:

```js
userSchema.virtual('bookings', {
    ref: 'Booking',
    localField: 'firebaseUid',
    foreignField: 'userId'
});
```

There is no physical `bookings` array inside the User document.

`populate('bookings')` performs the relationship lookup when requested.

### Interview trap

If asked:

> "Is Booking.userId a MongoDB reference?"

Answer:

> "No. It is a Firebase UID string. The User-to-Booking relationship is represented using matching `firebaseUid` and `userId` fields, with Mongoose virtual populate."

---

# 5. Frontend Token Injection: What Happens Automatically?

The frontend uses one Axios instance.

The important behavior is the interceptor.

Conceptually:

```js
axiosInstance.interceptors.request.use(async (config) => {
    const user = auth.currentUser;

    if (user) {
        const token = await user.getIdToken(true);

        config.headers.Authorization =
            `Bearer ${token}`;
    }

    return config;
});
```

Therefore individual API calls do not have to manually implement:

```text
get token
attach token
send request
```

every time.

The API layer centralizes it.

---

# 6. Why `getIdToken(true)` Matters

The `true` requests a refreshed token rather than blindly using a possibly stale cached token.

The result is:

```text
React API call
      |
      v
Axios interceptor
      |
      v
Firebase current user
      |
      v
Fresh ID token
      |
      v
Authorization header
      |
      v
Express middleware
```

This is the real frontend → backend authentication pipeline.

---

# 7. ProtectedRoute Is Not the Security Boundary

The frontend has:

```text
ProtectedRoute
```

which checks:

```text
authenticated?
email verified?
correct role?
```

But this is not enough for security.

A user can manually call:

```text
/api/admin/...
```

without using the React UI.

Therefore there are two layers:

```text
Frontend
    |
    | ProtectedRoute
    | -> UX / navigation
    v
Backend
    |
    | Firebase token verification
    | role middleware
    v
Actual authorization
```

This is a classic defense-in-depth pattern.

---

# 8. Booking Conflict Detection — The Important Algorithm

Suppose an existing booking is:

```text
Computer A
10 Aug → 15 Aug
10:00 → 14:00
```

and a new request is:

```text
Computer A
12 Aug → 13 Aug
11:00 → 13:00
```

The system does not just compare strings.

It conceptually performs:

### Gate 1 — Same computer?

```text
existing.computerId === requested.computerId
```

If not, ignore that booking.

### Gate 2 — Relevant status?

Only:

```text
pending
approved
```

matter for normal conflict detection.

Cancelled/rejected/completed bookings should not block a new request.

### Gate 3 — Date overlap?

Conceptually:

```text
existing.startDate <= requested.endDate
AND
existing.endDate >= requested.startDate
```

If false:

```text
No date overlap
```

No conflict.

### Gate 4 — Time overlap

For overlapping dates, the system checks whether the actual time intervals overlap.

Conceptually:

```text
existing.startTime < requested.endTime
AND
existing.endTime > requested.startTime
```

If the time intervals do not overlap, the request can coexist.

---

# 9. Why Date and Time Cannot Be Checked Independently

Consider:

```text
Existing:
10 Aug
10:00 → 12:00

New:
10 Aug
14:00 → 16:00
```

Same computer.

Same date.

But there is no time collision.

Therefore:

```text
same date ≠ necessarily conflict
```

This is why the booking system needs interval logic rather than a simple date equality check.

---

# 10. The Hard Case: Multi-Day Bookings

Suppose:

```text
Existing:
10 Aug → 15 Aug
10:00 → 14:00
```

and:

```text
New:
12 Aug → 13 Aug
11:00 → 13:00
```

Both requested dates are inside the existing booking.

Now suppose:

```text
12 Aug → released
13 Aug → released
```

The existing booking still exists.

So a naïve algorithm would say:

```text
overlap = true
=> reject
```

But this project needs another layer:

```text
overlap
   |
   v
check released dates
   |
   v
are ALL conflicting requested dates released?
```

Only then can the apparent conflict be resolved.

---

# 11. Why "ALL Dates" Matters

This is an important edge case.

Existing booking:

```text
10 → 15 Aug
```

Released:

```text
12 Aug
```

New request:

```text
12 → 13 Aug
```

Only one of the two requested dates is released.

Therefore:

```text
12 = available
13 = still occupied
```

The request must **not** be treated as completely available.

The logic is effectively:

```text
every conflicting date
        must have
a matching unused release slot
```

Not:

```text
at least one released date
```

This distinction prevents partial overlap from being incorrectly approved.

---

# 12. `releasedDates` Is More Than a Date Array

Inside the original booking:

```js
temporaryRelease: {
    releasedDates: [
        {
            date,
            isBooked,
            tempBookingId
        }
    ]
}
```

Each element represents a stateful slot.

Initially:

```text
date       = 13 Aug
isBooked   = false
tempBookingId = null
```

After someone takes the released slot:

```text
date       = 13 Aug
isBooked   = true
tempBookingId = NEW_BOOKING_ID
```

So the array acts almost like a small embedded allocation table.

---

# 13. Why `tempBookingId` Is Stored

Without `tempBookingId`, the system would know:

```text
13 Aug was released
13 Aug was later booked
```

but not directly know:

```text
WHICH booking consumed it?
```

With:

```text
tempBookingId
```

the relationship becomes:

```text
Original booking
      |
      +-- released date: 13 Aug
                |
                +-- consumed by booking XYZ123
```

That makes the history traceable.

---

# 14. `isTemporaryBooking` + `originalBookingId`

When a released date is booked, the new booking receives:

```text
isTemporaryBooking = true
originalBookingId = original booking
```

This creates a reverse relationship:

```text
Original Booking
       |
       | released
       v
TemporaryReleaseDetail
       |
       | consumed
       v
Temporary Booking
```

The original booking therefore does not disappear or get split.

Instead, the new booking explicitly identifies that it came from a released portion of another booking.

---

# 15. Why There Are Three Places Involved in Temporary Release

This is easy to misunderstand.

### Layer 1 — Original Booking

Used for fast conflict logic:

```text
booking.temporaryRelease.releasedDates
```

### Layer 2 — TemporaryReleaseDetail

Used as the historical/audit record:

```text
who released?
when?
why?
which dates?
which dates were consumed?
```

### Layer 3 — Old TemporaryRelease model

Legacy architecture.

It exists because the project evolved.

The important architectural lesson is:

> **The old model is not evidence that the current system needs three independent sources of truth. The current design uses the Booking's embedded release state for operational checks and TemporaryReleaseDetail for history.**

---

# 16. The Release Number Is Per Booking

Suppose booking `ABC123` creates:

```text
Release #1
Release #2
Release #3
```

The release number is not globally:

```text
Release 1
Release 2
Release 3
```

It is scoped to the booking.

Conceptually:

```js
getNextReleaseNumber(bookingId)
```

does:

```text
find releases for bookingId
        |
        v
sort/find latest release number
        |
        v
latest + 1
```

So:

```text
Booking A → #1, #2
Booking B → #1
```

This makes the release history readable within the context of one booking.

---

# 17. TemporaryReleaseDetail Status Is Derived State

The status should not be trusted as arbitrary user input.

It is recalculated during save.

Conceptually:

```js
if (cancelled) {
    status = "cancelled";
}
else if (bookedCount === 0) {
    status = "active";
}
else if (bookedCount < releasedCount) {
    status = "partially_booked";
}
else {
    // fully consumed state according to implementation
}
```

The important concept is:

```text
releasedDates
      |
      v
count consumed dates
      |
      v
derive status
```

This avoids asking every API caller to calculate status consistently.

---

# 18. Why `hasActiveReleases` Exists

Suppose the system repeatedly asks:

```text
Which bookings currently have temporary release slots?
```

A naïve query could inspect:

```text
releasedDates array
```

for every document.

Instead the model maintains:

```text
hasActiveReleases: true / false
```

and indexes it.

So the database can quickly narrow the candidate documents.

This is an example of **denormalized derived state for query performance**.

The important trade-off is:

```text
extra field to maintain
        versus
cheaper/faster queries
```

Mongoose pre-save middleware helps keep the derived field synchronized.

---

# 19. Compound Index #1 — What It Is Really Optimizing

The booking model contains an index conceptually like:

```js
{
    computerId: 1,
    status: 1,
    startDate: 1,
    endDate: 1
}
```

The conflict query naturally asks:

```text
same computer
AND relevant status
AND date range
```

The index is therefore aligned with the query shape.

The key lesson is not:

> "Indexes make MongoDB faster."

The stronger answer is:

> "The index is designed around the fields used together by the booking conflict query, so MongoDB can narrow the candidate booking set before evaluating the overlap logic."

---

# 20. Why an Index Does Not Solve the Entire Conflict Problem

An index can quickly find candidate bookings.

It does **not** magically determine the final business decision.

The final decision still requires:

```text
candidate bookings
        |
        v
date overlap
        |
        v
time overlap
        |
        v
temporary release state
        |
        v
final decision
```

So:

```text
Index = performance optimization
Business logic = correctness
```

Do not confuse the two in an interview.

---

# 21. Computer Status Protection Is a Consistency Guard

Imagine:

```text
Computer A
approved booking exists until Aug 20
```

An admin tries:

```text
Computer A → maintenance
```

If the backend simply changed the status, the system would end up with:

```text
Computer = maintenance

Booking = approved
Computer A
until Aug 20
```

Now the database contains contradictory business state.

The guard prevents this.

Conceptually:

```js
Booking.findOne({
    computerId,
    status: { $in: ["approved", "pending"] },
    endDate: { $gte: today }
});
```

If a match exists:

```text
reject status change
```

This is not just a UI restriction.

It is a **data consistency rule enforced by the backend**.

---

# 22. Why Delete Has the Same Guard

Deleting a computer with future bookings would produce:

```text
Booking.computerId
        |
        X
Computer document no longer exists
```

That creates an orphaned relationship.

So deletion is blocked while active/future bookings exist.

Again:

```text
frontend restriction = UX
backend restriction = integrity
```

---

# 23. Public Endpoints Are Not Duplicate Business Logic

There are routes such as:

```text
/public
```

and authenticated versions.

The purpose is not to create two different systems.

The distinction is:

```text
same type of information
        |
        +---- public browsing
        |
        +---- authenticated application
```

This allows:

```text
homepage → public API
booking/dashboard → authenticated API
```

without forcing visitors to create accounts just to inspect lab information.

---

# 24. Notification Routing Is a Small Authorization System

The notification `userId` field has special meanings:

```text
Firebase UID
"admin"
"all"
```

Think of it as:

```text
UID
  = direct message

admin
  = admin audience

all
  = regular-user broadcast
```

The fetch query then decides which audience the current user belongs to.

For admin:

```js
{
    $or: [
        { userId: currentFirebaseUid },
        { userId: "admin" }
    ]
}
```

For regular user:

```js
{
    $or: [
        { userId: currentFirebaseUid },
        { userId: "all" }
    ]
}
```

This means the database itself stores audience semantics rather than the frontend manually filtering every notification.

---

# 25. Why `insertMany` Is Used for Admin Notifications

Suppose an admin selects:

```text
User A
User B
User C
User D
```

Instead of:

```text
POST notification
POST notification
POST notification
POST notification
```

the frontend sends a target list.

The backend generates notification documents and uses:

```js
insertMany(...)
```

Conceptually:

```text
selected users
      |
      v
create N notification docs
      |
      v
one bulk insert
```

This reduces repeated database round trips.

---

# 26. "Cancel Booking" and "Free System" Are Different State Transitions

This is not just two buttons doing similar things.

### Cancel

Usually means:

```text
pending
   ↓
cancelled
```

The requested booking never became an active approved allocation.

### Free System

Means:

```text
approved
   ↓
completed
```

because the user has finished early or no longer needs the allocation.

For an active booking:

```text
current time
      |
      v
new end time = now
      |
      v
completed
```

For a future booking:

```text
approved
      |
      v
completed
```

without pretending that the computer was actually used until the original future time.

This distinction preserves more accurate history.

---

# 27. Why `freedAt` and `freedBy` Matter

If the booking is completed early, the system records:

```text
freedAt
freedBy
```

Otherwise, months later an admin would only see:

```text
completed
```

and would not know:

```text
Who released it?
When did they release it?
```

So these fields are audit metadata around a state transition.

---

# 28. Admin Extension Is Not a New Booking

When an admin extends a booking:

```text
Existing:
10 Aug → 15 Aug

Extended:
10 Aug → 18 Aug
```

The booking identity remains the same.

That matters because:

```text
booking history
temporary releases
notifications
audit references
```

remain attached to the same booking.

The implementation changes the end date rather than creating a second booking.

---

# 29. Revoke Uses the Existing Status State Machine

Admin revoke uses the same status-update mechanism rather than creating a special "revoked booking" model/state.

Conceptually:

```text
approved
   |
   v
cancelled
reason = "Revoked by admin"
```

The reason distinguishes the cause without introducing another status enum.

This is a useful design choice:

```text
small state machine
+
metadata explaining transition
```

instead of exploding the number of statuses.

---

# 30. Booking Expiration Is a Background Process

The server has a booking expiration service.

It runs approximately every hour.

Conceptually:

```js
setInterval(async () => {
    find approved bookings
    whose end datetime is in the past

    mark them completed
    send expiry notification/email
}, 60 * 60 * 1000);
```

The important detail is that expiration is based on the **combined date + time**, not only the date.

For example:

```text
endDate = today
endTime = 11:00
currentTime = 14:00
```

means:

```text
expired
```

but:

```text
endDate = today
endTime = 17:00
currentTime = 14:00
```

does not.

---

# 31. Why Expiration Runs Outside the Request

The user should not have to call:

```text
GET /bookings
```

to cause another booking to expire.

Expiration is a lifecycle concern.

Therefore:

```text
server process
      |
      v
background interval
      |
      v
find expired approvals
      |
      v
transition to completed
```

This is a lightweight scheduler approach.

It is not a distributed job queue.

That distinction is worth knowing.

---

# 32. Email Is Deliberately Not Part of the Transaction

Suppose approval performs:

```text
1. update booking
2. create notification
3. send email
```

Email is an external dependency.

If SMTP fails after steps 1 and 2:

```text
booking = approved
notification = created
email = failed
```

The code catches the email error instead of rolling back the booking.

So the design treats email as:

```text
side effect
```

rather than:

```text
critical source-of-truth operation
```

This is why the API should not return "booking failed" just because Gmail is unavailable.

---

# 33. But There Is an Important Trade-Off

This design means email delivery is not guaranteed.

You can have:

```text
database success
email failure
```

So the system prioritizes:

```text
correct booking state
```

over:

```text
guaranteed email delivery
```

If the system later required guaranteed delivery, a better architecture would be something like:

```text
booking update
      |
      v
outbox/event
      |
      v
background email worker
      |
      v
retry on failure
```

The current project does not implement that queue/outbox architecture.

---

# 34. Why Shared `policy.js` Is More Important Than It Looks

Rules such as:

```text
lab opens at 08:30
minimum booking = 1 hour
maximum booking = 15 days
maximum advance booking = 30 days
Sunday closed
```

are business rules.

If React and Node each had separate copies:

```text
Frontend says 15 days
Backend says 14 days
```

the UI and server would disagree.

The project instead imports the same constants.

```text
                 shared/policy.js
                    /       \
                   /         \
             React           Node
```

The frontend uses the rules for immediate feedback.

The backend uses the same rules for enforcement.

---

# 35. Why Frontend Validation Uses `useEffect`

The BookingForm watches fields such as:

```text
startDate
endDate
startTime
endTime
```

When one changes:

```text
state changes
    |
    v
useEffect runs
    |
    v
recalculate validation
    |
    v
update error/conflict state
```

This gives the user immediate feedback instead of waiting until pressing "Next".

However, this is still only client-side state.

The server repeats the important validation.

---

# 36. The "Full Day" Checkbox Is a Derived Form State

The checkbox does not represent a separate backend booking type.

Instead it modifies existing form values:

```text
fullDay = true
      |
      v
startTime = LAB_OPEN_HOUR
endTime = LAB_CLOSE_HOUR
      |
      v
disable time inputs
```

So the checkbox is a UI shortcut, not a separate database concept.

That is why no special `fullDayBooking` field is required just to represent the choice.

---

# 37. Terms Are a Submission Gate, Not a Booking State

The seven checkboxes do not create seven database flags.

They act as a final UI gate:

```text
terms[0..6] all true?
       |
   +---+---+
   |       |
  no      yes
   |       |
 block    submit
```

The important distinction is:

```text
UI acceptance state
```

versus:

```text
persistent business data
```

Do not assume every checkbox shown in the UI is stored in MongoDB.

---

# 38. Why the Software Pool Is Static

The software pool is not a full software inventory database.

It is closer to:

```text
predefined selectable vocabulary
```

Each item has:

```text
name
keywords
icon
```

This is useful when editing computer specifications because the admin can select known software consistently.

The computer document then stores the installed software list.

So:

```text
softwarePool
    = available choices

computer.systemDetails.installedSoftware
    = actual selected values
```

The two should not be confused.

---

# 39. Admin Creation Is Intentionally Outside the Web UI

The `makeAdmin.js` script requires server-side access.

The flow is:

```text
operator runs script
      |
      v
enter email
      |
      v
Firebase getUserByEmail()
      |
      v
get Firebase UID
      |
      v
find/create MongoDB user
      |
      v
role = admin
```

This avoids an endpoint like:

```text
POST /users/promote
```

that could become a privilege-escalation vulnerability if improperly protected.

The security boundary is therefore:

```text
server/SSH access
```

rather than:

```text
browser
```

---

# 40. Migration Reveals Why the Current Model Looks Complicated

The current temporary-release design did not start this way.

Earlier architecture:

```text
TemporaryRelease collection
```

contained release dates and temporary bookings.

Later architecture:

```text
Booking.temporaryRelease
+
TemporaryReleaseDetail
```

was introduced.

The migration script converts:

```text
old representation
        ↓
new representation
```

and backfills:

```text
isTemporaryBooking
originalBookingId
```

for existing temporary bookings.

This is why you may see seemingly duplicate/legacy models in the repository.

They are evidence of schema evolution.

---

# 41. Rollback Is More Than a Backup

The migration script also supports rollback.

Conceptually:

```text
new hybrid data
      |
      v
reconstruct old release representation
      |
      v
old TemporaryRelease collection
```

That means the migration logic understands both representations.

This is useful when explaining why old models should not automatically be deleted just because the new model is now active.

---

# 42. Achievement `publishedAt` Is Another Derived Field

The achievement model has:

```text
status
publishedAt
```

When an achievement first becomes:

```text
published
```

the pre-save hook sets:

```text
publishedAt = current time
```

This means the publication timestamp is generated from the state transition.

Conceptually:

```text
draft
  |
  | status changed to published
  v
published
  |
  +--> publishedAt = now
```

This is another example of middleware maintaining derived metadata.

---

# 43. Important Security Quirk in Achievements

The source notes reveal a subtle weakness.

The achievement GET endpoint checks whether an `Authorization` header exists to decide whether non-published content may be returned.

But:

```text
header exists
```

is not the same as:

```text
token is valid
```

A stronger implementation would:

```text
Authorization header
       |
       v
verify Firebase token
       |
       v
identify user
       |
       v
check role/permission
```

This is an important example of the difference between:

```text
authentication check
```

and:

```text
header presence check
```

---

# 44. Notification Context Is Polling, Not Real-Time Messaging

The frontend notification context does not maintain:

```text
WebSocket
SSE
Firebase realtime listener
```

Instead:

```text
component/context mounted
       |
       v
fetch notifications
       |
       v
store in React state
```

Therefore if the backend creates a notification while the user is sitting on the page, the UI is not receiving a push event.

The application needs another fetch/polling cycle.

This is an architectural limitation worth knowing.

---

# 45. Optimistic Notification Updates

For:

```text
markAsRead
markAllAsRead
```

the frontend can update local state even if the server call fails.

Conceptually:

```text
click "mark read"
      |
      +--> API request
      |
      +--> immediately update UI
```

This improves responsiveness.

But it creates a consistency trade-off:

```text
UI says read
server may still say unread
```

if the request fails.

A later refresh reconciles the state.

---

# 46. Settings Page: UI State vs Persisted State

The settings page visually suggests:

```text
email notifications
push notifications
booking reminders
maintenance alerts
```

But the save handler does not persist those settings.

So:

```text
UI exists
      |
      X
no backend persistence
```

This is an important interview honesty point.

Do not say:

> "Users can configure notification preferences."

Say:

> "The notification preference UI exists, but persistence is not implemented."

---

# 47. Production Architecture: Follow the Actual Deployment, Not the Dev Files

The repository contains files that can make the deployment look confusing.

The actual production path described in the project notes is:

```text
Internet
   |
   v
Apache HTTPD
   |
   +---- /negces/ ------> frontend static files
   |
   +---- /negcesapi/ ---> backend :5001
                              |
                              v
                           MongoDB
```

Podman runs the containers.

systemd manages the services.

So:

```text
Apache
    = web server + reverse proxy

Podman
    = container runtime

systemd
    = service lifecycle manager

MongoDB
    = database
```

---

# 48. Why the Backend Waits for MongoDB

The backend service waits until MongoDB passes its health check.

Conceptually:

```bash
while ! podman healthcheck run mongodb
do
    sleep 2
done

start backend
```

Without this dependency:

```text
backend starts
    |
    v
MongoDB not ready
    |
    v
connection failure
```

The health-check dependency makes startup more deterministic.

---

# 49. Graceful Shutdown Is a Request-Lifecycle Problem

When a container receives:

```text
SIGTERM
```

the backend does not immediately kill the process.

It does:

```text
SIGTERM
   |
   v
server.close()
   |
   v
stop accepting new requests
   |
   v
wait for active requests
   |
   v
close MongoDB connection
   |
   v
process.exit()
```

This prevents the application from abandoning in-flight work and leaving database connections hanging.

---

# 50. Backup Flow

The production backup is essentially:

```text
cron
  |
  v
backup.sh
  |
  v
read Mongo credentials
  |
  v
mongodump inside MongoDB container
  |
  v
podman cp
  |
  v
backup stored outside container
  |
  v
delete backups older than 7 days
```

The important concept is that the dump is copied **outside the database container**.

Otherwise destroying/replacing the container could also destroy the only copy of the backup.

---

# 51. A Subtle Data-Consistency Problem to Think About

Temporary release creation touches two representations:

```text
TemporaryReleaseDetail
+
Booking.temporaryRelease.releasedDates
```

The conceptual operation is:

```text
create audit document
+
update original booking
```

This creates a potential consistency concern if one succeeds and the other fails.

A stronger implementation could wrap both changes in a MongoDB transaction:

```text
START TRANSACTION
      |
      +-- create TemporaryReleaseDetail
      |
      +-- update Booking
      |
      +-- COMMIT
```

If something fails:

```text
ROLLBACK
```

The current design should therefore be understood as a multi-document consistency problem.

This is a good **future-improvement discussion** in an interview.

---

# 52. Another Important Race Condition

Two users could theoretically try to acquire the same released date at nearly the same time.

Conceptually:

```text
User A checks:
13 Aug is free

User B checks:
13 Aug is free

A books it
B books it
```

If the check and update are not made atomic, both requests can pass the initial check.

A stronger implementation would use:

```text
atomic update
+
conditional predicate
```

or a transaction/locking strategy.

For example, the database operation could conceptually say:

```text
update this release
ONLY IF
isBooked == false
```

Then only one request wins.

This is the kind of issue that is invisible in normal single-user testing but important in production booking systems.

---

# 53. Another Race: Computer Status Changes

Similarly:

```text
Admin checks:
no active booking

User creates booking

Admin sets computer = maintenance
```

If these operations happen concurrently, simple sequential checks are not enough to guarantee perfect serialization.

The system currently has backend guards, which are good for normal consistency, but a highly concurrent reservation system may need stronger transactional/locking guarantees.

This is a useful distinction:

```text
validation
```

is not always equivalent to:

```text
atomic concurrency control
```

---

# 54. Why "Approved" Is Not the Same as "Currently In Use"

The dashboard utilization formula is approximately:

```text
approved bookings / total computers
```

So:

```text
10 computers
3 approved bookings
```

produces:

```text
30%
```

even if:

```text
one booking starts tomorrow
```

That means this metric is really closer to:

```text
booking occupancy ratio
```

than physical real-time utilization.

A future improvement would calculate only bookings whose datetime interval contains `now`.

---

# 55. What You Should Say If Asked "What Is the Most Complex Part?"

Do **not** answer:

> "The booking form has four steps."

A stronger answer is:

> "The difficult part is the booking conflict engine, especially temporary releases. A normal booking system rejects any overlapping booking, but here an existing approved booking can release individual dates. The backend therefore has to identify overlapping bookings, determine the exact conflicting dates and times, check whether every conflicting date has an unused release slot, and then create a traceable temporary booking linked back to the original booking. The system also maintains embedded release state for fast checks and a separate detail document for audit history."

That demonstrates actual understanding.

---

# 56. What You Should Say If Asked "Why MongoDB?"

Avoid:

> "MongoDB is flexible."

Say:

> "The booking document contains naturally nested state, especially project metadata and temporary-release information. Embedding the released-date state inside the booking lets the conflict logic inspect the booking and its released dates together. We still use a separate detail collection where an audit-oriented history is more appropriate."

That answer connects the database choice to the actual data model.

---

# 57. What You Should Say If Asked "How Do You Prevent Unauthorized Admin Access?"

A strong answer:

> "The frontend hides admin routes using role-aware protected routes, but that is not the security boundary. Every protected backend request carries a Firebase ID token. The auth middleware verifies the token with Firebase Admin, looks up the MongoDB user using the Firebase UID, attaches the user's role to the request, and admin middleware checks that role. Admin creation itself is intentionally kept out of the public UI and is performed through a server-side CLI script."

---

# 58. What You Should Say If Asked "What Happens If Email Fails?"

Strong answer:

> "Email is treated as a non-critical side effect. The booking and in-app notification are committed independently, and the email call is wrapped in a try/catch. If SMTP fails, we log the error but do not convert a successful booking operation into a failed API request."

Then add:

> "If I were scaling this system, I would move email into an asynchronous outbox/queue with retries."

That shows both current understanding and engineering judgment.

---

# 59. What You Should Say If Asked "What Would You Improve?"

Good technical improvements:

### 1. Transactions for multi-document release updates

```text
Booking update
+
TemporaryReleaseDetail update
```

should be atomic.

### 2. Atomic released-slot claiming

Prevent two users from consuming the same release simultaneously.

### 3. Background email queue

Use:

```text
outbox / queue / worker
```

instead of sending synchronously.

### 4. Real-time notifications

Use:

```text
WebSocket / SSE
```

instead of polling.

### 5. Persist settings

Connect notification preference UI to MongoDB.

### 6. Fix achievement authorization

Verify the Firebase token instead of checking only whether an Authorization header exists.

### 7. Better utilization metric

Calculate active intervals using the current timestamp.

### 8. Remove or isolate legacy models

Once migration/rollback requirements disappear.

---

# 60. Final "Deep Understanding" Checklist

Before an interview, you should be able to answer these without opening the code:

```text
□ Why does Booking.userId contain Firebase UID?
□ How does the Axios interceptor attach authentication?
□ What exactly does auth middleware do?
□ Why isn't ProtectedRoute enough for security?
□ Which booking statuses participate in conflict detection?
□ How is date overlap determined?
□ How is time overlap determined?
□ Why can an overlapping booking sometimes be allowed?
□ Why must ALL conflicting dates be released?
□ What does isBooked mean inside releasedDates?
□ Why does tempBookingId exist?
□ Why do we need originalBookingId?
□ Why is hasActiveReleases duplicated as a boolean?
□ Why are there compound indexes?
□ What is the purpose of TemporaryReleaseDetail?
□ Why is releaseNumber scoped to a booking?
□ How is release status derived?
□ What prevents deleting a computer with future bookings?
□ Why are public and authenticated endpoints separate?
□ How are notifications routed using "admin" and "all"?
□ Why does admin notification use insertMany?
□ Difference between cancel and free?
□ What happens when a user frees an active booking?
□ What happens when a user frees a future booking?
□ How does automatic booking expiration work?
□ What happens if SMTP fails?
□ What happens if two users try to claim the same released date?
□ What happens if two release-related DB writes partially fail?
□ Why does migration code still exist?
□ What is actually production: Podman/Apache/systemd?
□ Why does backend wait for MongoDB health?
□ What does graceful shutdown do?
□ Which features are UI-only or incomplete?
```

---

# 61. The One Diagram to Memorize

```text
                    BOOKING REQUEST
                           |
                           v
                 Firebase Token Verify
                           |
                           v
                  MongoDB User + Role
                           |
                           v
                  Policy Validation
                           |
                           v
                Same Computer + Status
                           |
                           v
                    Date Overlap?
                       /       \
                     NO         YES
                     |           |
                  CREATE        Time Overlap?
                                  /       \
                                NO         YES
                                |           |
                             CREATE     Temporary Release?
                                           /       \
                                         NO         YES
                                         |           |
                                       REJECT    Every conflicting
                                                   date released?
                                                   /       \
                                                 NO         YES
                                                 |           |
                                               REJECT    Claim release
                                                            |
                                                            v
                                                     Create temporary
                                                         booking
                                                            |
                                                            v
                                                  Link originalBookingId
                                                            |
                                                            v
                                                  Mark release slot booked
                                                            |
                                                            v
                                                     Notification
                                                            |
                                                            v
                                                      Email attempt
                                                            |
                                                            v
                                                   Booking state stored
```

If you can explain **this diagram line by line**, you understand the core internal logic of NEGCES rather than just knowing what the pages do.

---

