# Deadlock — OS Interview Notes

> **Goal:** Understand deadlock clearly enough to explain it in an interview, identify its conditions, and explain prevention, avoidance, detection, and recovery.

---

# 1. What is a Resource?

A **resource** is anything a process/thread needs to perform its work.

### Examples

- CPU
- Memory
- Files
- Locks
- Sockets
- I/O devices
- Printers
- Database connections

A resource type can have **multiple instances**.

Example:

```text
Resource = CPU
Instances = 2 CPUs
```

Another example:

```text
Resource = Printer
Instances = 3 printers
```

---

# 2. How Does a Process Use a Resource?

A process normally follows three steps:

```text
Request → Use → Release
```

### 1. Request

The process asks for the resource.

- If available → resource is allocated.
- If unavailable → process waits.

### 2. Use

The process uses the resource.

### 3. Release

The process finishes using the resource and releases it so another process can use it.

### Example

```text
Process P1
   ↓
Request printer
   ↓
Printer available?
   ↓ Yes
Use printer
   ↓
Release printer
```

---

# 3. What is Deadlock?

A **deadlock** occurs when two or more processes are permanently waiting for resources held by each other.

As a result:

- Processes cannot continue.
- Processes never finish.
- Resources remain occupied.
- Other processes may also be blocked.

### Simple real-world example

Imagine:

```text
Person A has Key 1
Person B has Key 2

A needs Key 2 to continue.
B needs Key 1 to continue.
```

So:

```text
A → waiting for B
B → waiting for A
```

Neither can continue.

This is **deadlock**.

---

# 4. OS Example of Deadlock

Suppose:

```text
P1 holds R1
P1 wants R2

P2 holds R2
P2 wants R1
```

Then:

```text
P1 → waiting for R2 → held by P2
P2 → waiting for R1 → held by P1
```

Neither process can proceed.

Therefore:

> **P1 and P2 are deadlocked.**

---

# 5. Deadlock vs Normal Waiting

Not every waiting situation is a deadlock.

### Normal waiting

```text
P1 holds resource
P2 waits

P1 finishes
↓
P1 releases resource
↓
P2 gets resource
```

P2 eventually proceeds.

### Deadlock

```text
P1 waits for P2
P2 waits for P1
```

Neither can proceed.

> **Deadlock = permanent waiting caused by circular dependency.**

---

# 6. Four Necessary Conditions for Deadlock

A deadlock can occur **only when all four conditions exist simultaneously**.

Remember:

> **M-H-N-C**

```text
M → Mutual Exclusion
H → Hold and Wait
N → No Preemption
C → Circular Wait
```

---

# 7. Condition 1 — Mutual Exclusion

Only **one process at a time** can use a particular resource instance.

If another process requests it, that process must wait.

### Example

One printer:

```text
P1 → using Printer
P2 → requests Printer → waits
```

The printer cannot be used by P1 and P2 simultaneously.

### Important

Some resources are inherently non-shareable.

Examples:

- Printer
- Mutex lock
- Some I/O devices

Therefore, mutual exclusion cannot always be eliminated.

---

# 8. Condition 2 — Hold and Wait

A process is:

> **Holding at least one resource while waiting for another resource.**

### Example

```text
P1 holds R1
P1 waits for R2
```

P1 does not release R1 while waiting for R2.

This creates the possibility of deadlock.

---

# 9. Condition 3 — No Preemption

A resource cannot be forcibly taken away from a process.

The process must voluntarily release it after finishing.

### Example

```text
P1 has a resource
P2 wants it
```

The OS cannot simply take the resource away from P1.

P1 must release it.

---

# 10. Condition 4 — Circular Wait

A circular chain of processes exists where each process is waiting for a resource held by the next process.

Example:

```text
P1 → waiting for resource held by P2
P2 → waiting for resource held by P3
P3 → waiting for resource held by P1
```

Graphically:

```text
P1 → P2
↑     ↓
└──── P3
```

This is a **cycle**.

---

# 11. Important Interview Point

All four conditions must exist **at the same time** for deadlock to occur.

```text
Mutual Exclusion
       +
Hold and Wait
       +
No Preemption
       +
Circular Wait
       ↓
   DEADLOCK
```

If we break **even one** condition, deadlock can be prevented.

---

# 12. Methods for Handling Deadlock

There are three major approaches:

```text
Deadlock Handling
       │
       ├── Prevention
       │
       ├── Avoidance
       │
       └── Detection + Recovery
```

There is also:

```text
Ignore the problem
```

This is sometimes called the **Ostrich Algorithm**.

---

# 13. Deadlock Prevention

## Idea

Prevent deadlock by ensuring that **at least one of the four necessary conditions can never occur**.

```text
4 conditions
     ↓
Break at least one
     ↓
Deadlock cannot occur
```

---

# 14. Prevention — Break Mutual Exclusion

Try to make resources **shareable** where possible.

### Example

Read-only file:

```text
P1 → reads
P2 → reads
P3 → reads
```

Multiple processes can read it simultaneously.

Therefore, no mutual exclusion is required for the read operation.

### But:

Some resources are inherently non-shareable.

Example:

```text
Printer
```

Two processes cannot safely print on the same printer at exactly the same time.

Therefore:

> We generally cannot prevent deadlock by simply removing mutual exclusion because some resources must be exclusive.

---

# 15. Prevention — Break Hold and Wait

Ensure that a process does not hold one resource while waiting for another.

### Method 1: Request everything at once

A process must request all required resources before starting.

Example:

```text
P1 needs:
R1 + R2 + R3

Request all three first.
If all are available → start.
Otherwise → wait without holding resources.
```

### Method 2: Release before requesting more

A process can request additional resources only after releasing the resources it currently holds.

### Advantage

No hold-and-wait → deadlock cannot occur through this condition.

### Disadvantage

Resource utilization may be poor because a process may reserve resources before actually needing them.

---

# 16. Prevention — Break No Preemption

Allow the OS to **take/preempt resources** from a process in certain situations.

### Example

```text
P1 holds R1
P1 requests R2
R2 unavailable
```

Instead of making P1 keep R1:

```text
Preempt R1
↓
P1 releases its resources
↓
P1 waits
↓
Later it gets R1 + R2
↓
Continues
```

This breaks the no-preemption condition.

### Important

Resource preemption is not possible for every resource.

For example, forcibly taking a printer while it is halfway through printing may not be practical.

---

# 17. Prevention — Break Circular Wait

Impose a fixed ordering on resources.

For example:

```text
R1 < R2 < R3
```

Processes must always request resources in increasing order.

### Example

Both P1 and P2 need:

```text
R1 and R2
```

Both must follow:

```text
Lock R1 → Lock R2
```

Suppose P1 gets R1 first:

```text
P1 → R1 → R2
P2 → waits for R1
```

P2 cannot hold R2 while waiting for R1 because it must request R1 first.

Therefore, circular wait is prevented.

### Interview shortcut

> **Resource ordering prevents circular wait.**

---

# 18. Deadlock Avoidance

## Idea

Unlike prevention, avoidance does not simply break one condition.

Instead:

> The OS examines each resource request and grants it only if doing so keeps the system in a **safe state**.

The OS needs information about:

- Resources currently available
- Resources currently allocated
- Maximum resources each process may need
- Future resource requests

---

# 19. Safe State

A system is in a **safe state** if there is some order in which every process can obtain its required resources, finish, and release them without causing deadlock.

That order is called a:

> **Safe Sequence**

### Simple example

Suppose:

```text
Available resources = 3

P1 needs 2 more
P2 needs 4 more
P3 needs 1 more
```

The OS can give 1 resource to P3.

P3 finishes and releases its resources.

Then more resources become available.

If eventually all processes can finish in some order, the system is **safe**.

---

# 20. Unsafe State

An **unsafe state** means the OS cannot guarantee that all processes can finish without deadlock.

Important:

> **Unsafe state ≠ Deadlock necessarily.**

An unsafe state **may lead to deadlock**, but deadlock has not necessarily happened yet.

### Relationship

```text
Safe state
    ↓
Deadlock cannot occur if system follows the safe allocation strategy

Unsafe state
    ↓
Deadlock may occur

Deadlocked state
    ↓
Processes are already permanently blocked
```

---

# 21. Key Difference: Safe vs Unsafe vs Deadlock

| State | Meaning |
|---|---|
| Safe | System can find a safe sequence for all processes |
| Unsafe | No guaranteed safe sequence; deadlock may occur |
| Deadlock | Processes are already permanently waiting |

### Interview trap

> **Every deadlock state is unsafe, but every unsafe state is not necessarily deadlocked.**

---

# 22. Banker’s Algorithm

The **Banker's Algorithm** is a classic deadlock avoidance algorithm.

It is called "Banker's" because it works like a bank deciding whether it can safely give a customer a loan without running out of money for all customers.

### Main idea

When a process requests resources:

```text
Process requests resources
        ↓
Can we grant them?
        ↓
Pretend to grant them
        ↓
Check whether resulting state is safe
        ↓
 ┌───────────────┬───────────────┐
 ↓               ↓
Safe            Unsafe
 ↓               ↓
Grant           Make process wait
```

### Interview answer

> The Banker's Algorithm grants a resource request only if the resulting state remains safe.

---

# 23. Deadlock Prevention vs Avoidance

| Prevention | Avoidance |
|---|---|
| Breaks at least one deadlock condition | Checks whether allocation keeps system safe |
| Deadlock is structurally prevented | Deadlock is avoided by careful allocation |
| Does not require maximum future needs in the same way | Requires information about maximum resource needs |
| Examples: resource ordering, no hold-and-wait | Banker's Algorithm |

### Easy memory trick

> **Prevention = Break a condition.**

> **Avoidance = Check safety before giving resources.**

---

# 24. Deadlock Detection

Another approach is:

> Let deadlock happen, then detect it and recover.

This is useful when prevention/avoidance is too expensive or not practical.

```text
Allow allocation
      ↓
Periodically check
      ↓
Deadlock?
   /       \
 No         Yes
 ↓           ↓
Continue   Recover
```

---

# 25. Deadlock Detection — Single Instance

If every resource type has only **one instance**, we can use a **Wait-for Graph**.

### Wait-for Graph

A node represents a process.

An edge:

```text
P1 → P2
```

means:

> P1 is waiting for a resource held by P2.

### Example

```text
P1 → P2
↑     ↓
└──── P3
```

There is a cycle.

Therefore:

> **For a single instance of each resource type, a cycle in the wait-for graph indicates deadlock.**

---

# 26. Deadlock Detection — Multiple Instances

When resource types have multiple instances, detection is more complicated.

A detection algorithm similar in idea to the Banker's safety checking can be used to determine whether processes can still finish.

For interviews, remember:

```text
Single instance → Wait-for Graph → Cycle
Multiple instances → Detection algorithm using available/allocation/request information
```

---

# 27. Recovery from Deadlock

After detecting deadlock, the OS needs to recover.

Two common approaches:

```text
Recovery
   ├── Process Termination
   └── Resource Preemption
```

---

# 28. Recovery — Process Termination

### Option 1: Abort all deadlocked processes

Immediately terminate all processes involved in the deadlock.

### Advantage

Simple and quickly removes the deadlock.

### Disadvantage

A lot of work may be lost.

---

### Option 2: Abort one process at a time

Terminate one process, release its resources, and check whether the deadlock is broken.

```text
Detect deadlock
      ↓
Abort one process
      ↓
Release resources
      ↓
Check again
      ↓
Deadlock gone?
```

This may reduce unnecessary work loss but takes more time.

---

# 29. Recovery — Resource Preemption

Take resources from some processes and give them to others to break the deadlock.

```text
P1 holds R1
P2 holds R2

Preempt R1
↓
Give R1 to another process
↓
Break the waiting cycle
```

Important issues include:

- Which process should lose its resource?
- Which resource should be preempted?
- How do we avoid repeatedly selecting the same process?

---

# 30. Deadlock vs Starvation vs Livelock

These are commonly confused in interviews.

| Concept | Meaning |
|---|---|
| Deadlock | Processes wait forever for each other |
| Starvation | A process waits indefinitely because others keep getting the resource |
| Livelock | Processes keep changing state/responding but make no progress |

### Deadlock

```text
P1 waits for P2
P2 waits for P1

Nothing changes.
```

### Starvation

```text
P1 keeps getting resource
P2 keeps waiting
P3 keeps getting resource
P2 keeps waiting...
```

### Livelock

Processes are active but still make no useful progress.

---

# 31. Deadlock vs Race Condition

Another important interview distinction.

### Race Condition

Multiple processes access shared data concurrently and the result depends on execution timing.

```text
Shared data
   ↓
Concurrent access
   ↓
Incorrect/unpredictable result
```

### Deadlock

Processes are permanently waiting for resources.

```text
P1 waits for P2
P2 waits for P1
   ↓
Permanent waiting
```

### Easy difference

> **Race condition = wrong result because of timing.**

> **Deadlock = no progress because of waiting.**

---

# 32. Real-World Deadlock Example

Consider two database transactions.

```text
Transaction T1:
Locks Account A
Waits for Account B

Transaction T2:
Locks Account B
Waits for Account A
```

Result:

```text
T1 → waiting for B
T2 → waiting for A
```

Neither can continue.

The database must detect/prevent this situation.

---

# 33. Most Important Interview Questions

## Basic Questions

### Q1. What is deadlock?

> Deadlock is a situation where two or more processes are permanently waiting for resources held by each other, so none of them can proceed.

### Q2. What are the four necessary conditions?

> Mutual exclusion, hold and wait, no preemption, and circular wait.

### Q3. Do all four conditions need to exist?

> Yes. All four must hold simultaneously for deadlock to occur.

### Q4. What is the easiest way to prevent deadlock?

> Break at least one of the four necessary conditions.

### Q5. Give an example of deadlock.

> P1 holds R1 and waits for R2, while P2 holds R2 and waits for R1. Both wait forever.

---

# 34. Prevention Questions

### Q6. How do you prevent circular wait?

> Assign an ordering to resource types and require processes to request resources only in that order.

### Q7. How do you prevent hold and wait?

> Require a process to request all resources before execution, or require it to release its currently held resources before requesting additional ones.

### Q8. How can no-preemption be broken?

> If a requested resource cannot be allocated, preempt resources held by the process and make it wait until it can obtain all required resources.

### Q9. Can mutual exclusion always be removed?

> No. Some resources are inherently non-shareable, such as certain locks or devices like printers.

---

# 35. Avoidance Questions

### Q10. What is deadlock avoidance?

> It is a strategy where the OS examines each resource request and grants it only if the resulting state remains safe.

### Q11. What is a safe state?

> A state in which there exists a safe sequence allowing every process to obtain its required resources, finish, and release them.

### Q12. What is an unsafe state?

> A state in which there is no guaranteed safe sequence. It may lead to deadlock, but it is not necessarily already deadlocked.

### Q13. What is Banker's Algorithm?

> It is a deadlock avoidance algorithm that checks whether granting a resource request would leave the system in a safe state.

---

# 36. Detection and Recovery Questions

### Q14. What is deadlock detection?

> Instead of preventing deadlock, the system periodically checks whether a deadlock has occurred.

### Q15. How do you detect deadlock with one instance of each resource?

> Use a wait-for graph. A cycle indicates deadlock.

### Q16. How can the system recover from deadlock?

> By terminating processes or preempting resources.

### Q17. What is the difference between prevention and recovery?

> Prevention tries to ensure deadlock never happens. Recovery deals with deadlock after it has already been detected.

---

# 37. Important Interview Traps

### Trap 1

**Unsafe state = deadlock?**

❌ No.

> Unsafe state means deadlock **may** occur.

---

### Trap 2

**If there is a cycle, is there always deadlock?**

For a **wait-for graph with a single instance of each resource type**:

> Yes, a cycle indicates deadlock.

For a general resource-allocation graph with **multiple instances**, a cycle alone is not necessarily sufficient.

---

### Trap 3

**Does deadlock mean CPU is doing nothing?**

Not necessarily.

The deadlocked processes are blocked, but the CPU may still execute other processes.

---

### Trap 4

**Can deadlock happen with only one process?**

Normally, deadlock requires a waiting dependency involving multiple processes/threads or resource requests that cannot be satisfied. A single process can become permanently blocked on a resource, but this is generally not described as the classic multi-process deadlock.

---

# 38. Quick Comparison of Handling Methods

| Method | Main Idea | Example |
|---|---|---|
| Prevention | Break a necessary condition | Resource ordering |
| Avoidance | Grant request only if state remains safe | Banker's Algorithm |
| Detection | Allow deadlock and periodically detect it | Wait-for graph |
| Recovery | Remove an existing deadlock | Process termination / resource preemption |
| Ignore | Pretend deadlock does not happen | Ostrich approach |

---

# 39. One Complete Example

Suppose:

```text
P1 needs R1 and R2
P2 needs R1 and R2
```

### Bad allocation

```text
P1 gets R1
P2 gets R2

P1 waits for R2
P2 waits for R1
```

Now:

```text
P1 → R2 → P2
P2 → R1 → P1
```

Deadlock occurs.

### Prevention using resource ordering

Define:

```text
R1 < R2
```

Both processes must request:

```text
R1 → R2
```

Then:

```text
P1 gets R1
P2 waits for R1

P1 gets R2
P1 finishes
P1 releases R1 + R2
P2 continues
```

No circular wait → no deadlock.

---

# 40. Final Interview Cheat Sheet

```text
DEADLOCK
│
├── Meaning
│   └── Processes permanently wait for resources
│
├── 4 Necessary Conditions
│   ├── Mutual Exclusion
│   ├── Hold & Wait
│   ├── No Preemption
│   └── Circular Wait
│
├── Handling
│   ├── Prevention
│   │   └── Break at least one condition
│   │
│   ├── Avoidance
│   │   └── Keep system in safe state
│   │       └── Banker's Algorithm
│   │
│   ├── Detection
│   │   └── Wait-for Graph for single instances
│   │
│   ├── Recovery
│   │   ├── Process termination
│   │   └── Resource preemption
│   │
│   └── Ignore
│       └── Ostrich Algorithm
│
└── Important distinctions
    ├── Safe ≠ Unsafe ≠ Deadlock
    ├── Deadlock ≠ Starvation
    ├── Deadlock ≠ Race Condition
    └── Deadlock ≠ Livelock
```

# 41. 30-Second Interview Answer

> **Deadlock is a situation where two or more processes are permanently waiting for resources held by each other, so none can proceed. It requires four conditions: mutual exclusion, hold and wait, no preemption, and circular wait. Deadlocks can be handled using prevention, avoidance, detection and recovery, or by ignoring them. Prevention breaks at least one necessary condition, while avoidance checks whether allocating a resource keeps the system in a safe state. The Banker's Algorithm is a common deadlock avoidance algorithm. If deadlock is detected, the OS can recover by terminating processes or preempting resources.**

## Final Memory Trick

> **Deadlock = M-H-N-C**

> **Prevention = Break a condition**

> **Avoidance = Check safe state**

> **Banker's = Avoidance**

> **Detection = Find deadlock**

> **Recovery = Remove deadlock**

> **Safe ≠ Deadlock**

> **Unsafe may lead to Deadlock**
