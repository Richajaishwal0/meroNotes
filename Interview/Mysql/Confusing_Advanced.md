# SQL — GROUP BY vs PARTITION BY vs CTE

## 1. GROUP BY

### Think:

> **"I want to combine rows into groups and get ONE result per group."**

Example table:

| employee_id | department_id | salary |
| ----------- | ------------- | -----: |
| 1           | 10            |    100 |
| 2           | 10            |    200 |
| 3           | 10            |    300 |
| 4           | 20            |    400 |
| 5           | 20            |    600 |

### Example

Find average salary of each department.

```sql
SELECT department_id, AVG(salary)
FROM Employee
GROUP BY department_id;
```

Result:

| department_id | AVG(salary) |
| ------------- | ----------: |
| 10            |         200 |
| 20            |         500 |

### Important

`GROUP BY` **collapses rows**.

Department 10 had:

```text
100
200
300
```

After `GROUP BY`:

```text
200
```

So:

> **GROUP BY → one row per group**

---

# 2. PARTITION BY

### Think:

> **"I want to calculate something within each group BUT I DON'T want to lose the original rows."**

Example:

Find every employee's salary along with the average salary of their department.

```sql
SELECT employee_id,
       department_id,
       salary,
       AVG(salary) OVER(PARTITION BY department_id) AS avg_salary
FROM Employee;
```

Result:

| employee_id | department_id | salary | avg_salary |
| ----------- | ------------- | -----: | ---------: |
| 1           | 10            |    100 |        200 |
| 2           | 10            |    200 |        200 |
| 3           | 10            |    300 |        200 |
| 4           | 20            |    400 |        500 |
| 5           | 20            |    600 |        500 |

Notice:

### GROUP BY

```text
Department 10
    ↓
    200
```

### PARTITION BY

```text
Employee 1 → 200
Employee 2 → 200
Employee 3 → 200
```

The average is calculated separately for department 10, but **every employee row is still present**.

---

# 3. When should I use PARTITION BY?

Look for questions like:

### "For each employee, find..."

### "Compare each row with its group..."

### "Find employees whose salary is greater than their department average"

### "Find the highest salary in each department while keeping employee details"

### "Find percentage/rank/count within each group"

These are strong signals for:

```sql
OVER(PARTITION BY ...)
```

---

# 4. Example — Salary greater than department average

Question:

> Find employees whose salary is greater than the average salary of their department.

### PARTITION BY approach

```sql
WITH temp AS (
    SELECT *,
           AVG(salary) OVER(PARTITION BY department_id) AS avg_salary
    FROM Employee
)
SELECT employee_id,
       department_id,
       salary
FROM temp
WHERE salary > avg_salary;
```

Why did we use `PARTITION BY`?

Because we need:

```text
Employee's salary
        ↓
compare with
        ↓
average salary of THEIR department
```

And we need to **keep each employee row**.

---

# 5. Why do we need CTE here?

You might try:

```sql
SELECT employee_id,
       department_id,
       salary,
       AVG(salary) OVER(PARTITION BY department_id) AS avg_salary
FROM Employee
WHERE salary > AVG(salary) OVER(PARTITION BY department_id);
```

❌ This doesn't work.

The reason:

**Window functions cannot be used directly inside `WHERE` in MySQL.**

The window function needs to be calculated first.

So we do:

```text
Employee
   ↓
calculate AVG() OVER(...)
   ↓
temporary result
   ↓
WHERE salary > avg_salary
```

The CTE gives us that temporary result.

---

# 6. What is a CTE?

CTE = **Common Table Expression**

Syntax:

```sql
WITH temp AS (
    SELECT ...
)
SELECT ...
FROM temp;
```

### Think:

> **CTE = Create an intermediate result, then use it in the next query.**

It is NOT an algorithm.

It is just a clean way to break a complicated query into steps.

---

# 7. When should I use CTE?

Use CTE when the query has **multiple logical steps**.

For example:

```text
Step 1 → calculate something
Step 2 → use that result
Step 3 → filter/group/rank
```

Instead of writing everything in one huge query:

```sql
SELECT ...
FROM (
    SELECT ...
    FROM (
        SELECT ...
    ) x
) y;
```

you can write:

```sql
WITH step1 AS (
    ...
),
step2 AS (
    ...
)
SELECT ...
FROM step2;
```

Much easier to read.

---

# 8. CTE is NOT the same as PARTITION BY

This is very important.

### PARTITION BY answers:

> **"How should my window function divide the rows?"**

Example:

```sql
AVG(salary) OVER(PARTITION BY department_id)
```

Means:

```text
Calculate average separately for each department.
```

---

### CTE answers:

> **"Do I need an intermediate result before my final query?"**

Example:

```sql
WITH temp AS (
    SELECT *,
           AVG(salary) OVER(PARTITION BY department_id) AS avg_salary
    FROM Employee
)
SELECT *
FROM temp
WHERE salary > avg_salary;
```

Here:

```text
PARTITION BY → calculates department average

CTE          → stores that calculated result

WHERE        → filters the result
```

They solve **different problems**.

---

# 9. Can I use GROUP BY instead of PARTITION BY?

YES.

The same salary problem can be solved using `GROUP BY + JOIN`.

First:

```sql
SELECT department_id,
       AVG(salary) AS avg_salary
FROM Employee
GROUP BY department_id;
```

Then join it back:

```sql
SELECT e.employee_id,
       e.department_id,
       e.salary
FROM Employee e
JOIN (
    SELECT department_id,
           AVG(salary) AS avg_salary
    FROM Employee
    GROUP BY department_id
) d
ON e.department_id = d.department_id
WHERE e.salary > d.avg_salary;
```

So:

```text
GROUP BY + JOIN
        OR
PARTITION BY
```

Both can solve it.

---

# 10. Main difference — GROUP BY vs PARTITION BY

## GROUP BY

```sql
SELECT department_id, AVG(salary)
FROM Employee
GROUP BY department_id;
```

Result:

```text
10 → 200
20 → 500
```

**Rows are collapsed.**

Think:

> "Give me one answer for each group."

---

## PARTITION BY

```sql
SELECT employee_id,
       salary,
       AVG(salary) OVER(PARTITION BY department_id)
FROM Employee;
```

Result:

```text
1 → 100 → 200
2 → 200 → 200
3 → 300 → 200
```

**Rows are NOT collapsed.**

Think:

> "Calculate within each group but keep every row."

---

# 11. Quick decision trick

When reading a SQL question, ask:

### Question 1:

> Do I need ONE row/result per group?

Use:

```sql
GROUP BY
```

---

### Question 2:

> Do I need the calculation for each row while considering its group?

Use:

```sql
OVER(PARTITION BY ...)
```

---

### Question 3:

> Do I need to use the calculated result in another step?

Use:

```sql
CTE
```

or a subquery.

---

# 12. Common interview patterns

## Pattern 1 — Aggregate per group

> Find average salary of each department.

```sql
SELECT department_id, AVG(salary)
FROM Employee
GROUP BY department_id;
```

Think:

**GROUP BY**

---

## Pattern 2 — Keep individual rows

> Show each employee and their department's average salary.

```sql
SELECT employee_id,
       salary,
       AVG(salary) OVER(PARTITION BY department_id)
FROM Employee;
```

Think:

**PARTITION BY**

---

## Pattern 3 — Compare row with group calculation

> Find employees earning more than their department average.

```sql
WITH temp AS (
    SELECT *,
           AVG(salary) OVER(PARTITION BY department_id) AS avg_salary
    FROM Employee
)
SELECT *
FROM temp
WHERE salary > avg_salary;
```

Think:

**PARTITION BY + CTE**

---

## Pattern 4 — Ranking within groups

> Find top 3 salaries in every department.

```sql
WITH ranked AS (
    SELECT *,
           DENSE_RANK() OVER(
               PARTITION BY department_id
               ORDER BY salary DESC
           ) AS rnk
    FROM Employee
)
SELECT *
FROM ranked
WHERE rnk <= 3;
```

Think:

**PARTITION BY + ranking + CTE**

---

## Pattern 5 — Consecutive rows

> Find numbers appearing consecutively at least N times.

Think:

```text
LAG()
 ↓
detect change
 ↓
create groups/islands
 ↓
SUM() OVER()
 ↓
GROUP BY
 ↓
COUNT()
```

Usually:

**Window functions + CTE**

---

# 13. My mental cheat sheet

```text
GROUP BY
    ↓
"Give me ONE result per group"

PARTITION BY
    ↓
"Calculate within a group,
 but KEEP every row"

CTE
    ↓
"I need an intermediate result
 before my final query"

WINDOW FUNCTION
    ↓
"Need information from other rows
 without collapsing rows"

LAG()
    ↓
"Look at previous row"

LEAD()
    ↓
"Look at next row"

ROW_NUMBER()
    ↓
"Give unique ranking"

RANK()
    ↓
"Ranking with gaps after ties"

DENSE_RANK()
    ↓
"Ranking without gaps after ties"
```

# ⭐ Most important distinction

Remember this one line:

```text
GROUP BY    → COLLAPSES rows
PARTITION BY → DOES NOT collapse rows
CTE         → BREAKS query into steps
```

That is the core idea.

# SQL Window Functions: SUM / AVG with ORDER BY

## 1. The main idea

When you write:

```sql
SUM(weight) OVER (ORDER BY turn)
```

SQL calculates a **cumulative (running) sum**.

Think:

> "For this row, add everything from the beginning up to this row."

---

## 2. SUM() OVER (ORDER BY ...)

Example table:

| turn | person | weight |
|---:|---|---:|
| 1 | A | 200 |
| 2 | B | 300 |
| 3 | C | 400 |
| 4 | D | 200 |

Query:

```sql
SELECT
    turn,
    person,
    weight,
    SUM(weight) OVER (ORDER BY turn) AS cumulative_weight
FROM Queue;
```

Result:

| turn | person | weight | cumulative_weight |
|---:|---|---:|---:|
| 1 | A | 200 | 200 |
| 2 | B | 300 | 500 |
| 3 | C | 400 | 900 |
| 4 | D | 200 | 1100 |

### How SQL calculates it

```text
Turn 1:
200
= 200

Turn 2:
200 + 300
= 500

Turn 3:
200 + 300 + 400
= 900

Turn 4:
200 + 300 + 400 + 200
= 1100
```

So:

```sql
SUM(x) OVER (ORDER BY something)
```

means:

**Running / cumulative SUM in that order.**

---

# 3. AVG() OVER (ORDER BY ...)

The same idea works with `AVG`.

```sql
AVG(weight) OVER (ORDER BY turn)
```

This gives a **running average**.

For the same data:

| turn | weight | cumulative average |
|---:|---:|---:|
| 1 | 200 | 200 |
| 2 | 300 | 250 |
| 3 | 400 | 300 |
| 4 | 200 | 275 |

Calculation:

```text
Turn 1:
200 / 1 = 200

Turn 2:
(200 + 300) / 2 = 250

Turn 3:
(200 + 300 + 400) / 3 = 300

Turn 4:
(200 + 300 + 400 + 200) / 4 = 275
```

So:

```sql
AVG(x) OVER (ORDER BY something)
```

means:

**Running / cumulative AVG in that order.**

---

# 4. What does ORDER BY do here?

This is extremely important.

```sql
SUM(weight) OVER (ORDER BY turn)
```

The `ORDER BY turn` tells SQL:

> "Start from the smallest turn and keep adding as turn increases."

Without `ORDER BY`:

```sql
SUM(weight) OVER ()
```

you get the **total sum of the entire table on every row**.

Example:

| turn | weight | SUM(weight) OVER () |
|---:|---:|---:|
| 1 | 200 | 1100 |
| 2 | 300 | 1100 |
| 3 | 400 | 1100 |
| 4 | 200 | 1100 |

Compare:

```sql
SUM(weight) OVER ()
```

→ Total for everyone.

```sql
SUM(weight) OVER (ORDER BY turn)
```

→ Running total.

---

# 5. What if we use PARTITION BY?

Now suppose we have:

| employee | department | salary |
|---|---|---:|
| A | IT | 100 |
| B | IT | 200 |
| C | HR | 300 |
| D | HR | 500 |

Query:

```sql
SUM(salary) OVER (
    PARTITION BY department
)
```

SQL creates separate groups internally:

```text
IT → 100, 200
HR → 300, 500
```

Result:

| employee | department | salary | department_sum |
|---|---|---:|---:|
| A | IT | 100 | 300 |
| B | IT | 200 | 300 |
| C | HR | 300 | 800 |
| D | HR | 500 | 800 |

`PARTITION BY` means:

> Calculate separately for each group, but keep every row.

---

# 6. PARTITION BY + ORDER BY

This is where things become very useful.

```sql
SUM(salary) OVER (
    PARTITION BY department
    ORDER BY employee
)
```

Now we get a **cumulative sum separately inside each department**.

Result:

| employee | department | salary | cumulative_sum |
|---|---|---:|---:|
| A | IT | 100 | 100 |
| B | IT | 200 | 300 |
| C | HR | 300 | 300 |
| D | HR | 500 | 800 |

Notice:

```text
IT:
100
100 + 200 = 300

HR:
300
300 + 500 = 800
```

The cumulative calculation **resets when the partition changes**.

---

# 7. The easiest way to remember

## SUM

```sql
SUM(x) OVER (ORDER BY id)
```

→ Running total.

```text
10
10 + 20 = 30
10 + 20 + 30 = 60
...
```

## AVG

```sql
AVG(x) OVER (ORDER BY id)
```

→ Running average.

```text
10
(10 + 20) / 2
(10 + 20 + 30) / 3
...
```

## No ORDER BY

```sql
SUM(x) OVER ()
```

→ Total of all rows, repeated on every row.

## PARTITION BY

```sql
SUM(x) OVER (PARTITION BY group_col)
```

→ Total separately for each group.

## PARTITION BY + ORDER BY

```sql
SUM(x) OVER (
    PARTITION BY group_col
    ORDER BY id
)
```

→ Running total separately for each group.

---

# 8. Connection to LeetCode 1204

For **Last Person to Fit in the Bus**, you need:

```sql
SUM(weight) OVER (ORDER BY turn)
```

because you need to know:

> "After this person boards, what is the total weight of everyone who has boarded so far?"

Then:

```text
cumulative weight <= 1000
```

means that person can still board.

The person with the **largest turn** among those rows is the answer.

---

# Quick Revision

| Query | Meaning |
|---|---|
| `SUM(x)` | One total when used as a normal aggregate |
| `SUM(x) OVER ()` | Total repeated on every row |
| `SUM(x) OVER (ORDER BY id)` | Running/cumulative total |
| `SUM(x) OVER (PARTITION BY dept)` | Total per department, repeated on each row |
| `SUM(x) OVER (PARTITION BY dept ORDER BY id)` | Running total within each department |
| `AVG(x) OVER ()` | Overall average repeated on every row |
| `AVG(x) OVER (ORDER BY id)` | Running average |
| `AVG(x) OVER (PARTITION BY dept)` | Average per department |
| `AVG(x) OVER (PARTITION BY dept ORDER BY id)` | Running average within each department |

## One-line memory trick

```text
PARTITION BY → where to reset
ORDER BY     → where to start and what order to accumulate
SUM          → running total
AVG          → running average
```
