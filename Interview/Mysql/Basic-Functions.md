# SQL Interview Cheat Sheet

## SQL Built-in Functions

The GeeksforGeeks SQL Interview Questions page uses a mix of **String Functions, Aggregate Functions, Date Functions, Numeric Functions, NULL Functions, Window Functions, and Conditional Functions**.

---

# 1. String Functions

| Function      | Purpose                    | Syntax                                     |
| ------------- | -------------------------- | ------------------------------------------ |
| `UPPER()`     | Convert to uppercase       | `SELECT UPPER(column_name);`               |
| `LOWER()`     | Convert to lowercase       | `SELECT LOWER(column_name);`               |
| `SUBSTRING()` | Extract part of a string   | `SELECT SUBSTRING(column, start, length);` |
| `INSTR()`     | Find position of substring | `SELECT INSTR(column,'text');`             |
| `LENGTH()`    | Returns string length      | `SELECT LENGTH(column);`                   |
| `REPLACE()`   | Replace characters         | `SELECT REPLACE(column,'old','new');`      |
| `CONCAT()`    | Join strings               | `SELECT CONCAT(col1,col2);`                |
| `TRIM()`      | Remove spaces              | `SELECT TRIM(column);`                     |
| `LTRIM()`     | Remove left spaces         | `SELECT LTRIM(column);`                    |
| `RTRIM()`     | Remove right spaces        | `SELECT RTRIM(column);`                    |
| `REVERSE()`   | Reverse string             | `SELECT REVERSE(column);`                  |

## Examples

```sql
SELECT UPPER(first_name);

SELECT LOWER(first_name);

SELECT SUBSTRING(first_name,1,3);

SELECT INSTR(first_name,'a');

SELECT LENGTH(first_name);

SELECT REPLACE(first_name,'a','A');

SELECT CONCAT(first_name,' ',last_name);

SELECT TRIM(name);

SELECT REVERSE(first_name);
```

---

# 2. Aggregate Functions

| Function  | Purpose        | Syntax                        |
| --------- | -------------- | ----------------------------- |
| `COUNT()` | Count rows     | `COUNT(*)` or `COUNT(column)` |
| `SUM()`   | Sum values     | `SUM(column)`                 |
| `AVG()`   | Average        | `AVG(column)`                 |
| `MAX()`   | Largest value  | `MAX(column)`                 |
| `MIN()`   | Smallest value | `MIN(column)`                 |

## Examples

```sql
SELECT COUNT(*) FROM Student;

SELECT SUM(salary) FROM Employee;

SELECT AVG(salary) FROM Employee;

SELECT MAX(salary) FROM Employee;

SELECT MIN(salary) FROM Employee;
```

---

# 3. Date Functions

| Function     | Purpose               | Syntax                  |
| ------------ | --------------------- | ----------------------- |
| `NOW()`      | Current date and time | `NOW()`                 |
| `CURDATE()`  | Current date          | `CURDATE()`             |
| `CURTIME()`  | Current time          | `CURTIME()`             |
| `YEAR()`     | Extract year          | `YEAR(date)`            |
| `MONTH()`    | Extract month         | `MONTH(date)`           |
| `DAY()`      | Extract day           | `DAY(date)`             |
| `DATEDIFF()` | Difference in days    | `DATEDIFF(date1,date2)` |

## Examples

```sql
SELECT NOW();

SELECT CURDATE();

SELECT YEAR(enroll_date);

SELECT MONTH(enroll_date);

SELECT DATEDIFF(CURDATE(),joining_date);
```

---

# 4. Numeric Functions

| Function  | Purpose        | Syntax                         |
| --------- | -------------- | ------------------------------ |
| `ROUND()` | Round number   | `ROUND(number,decimal_places)` |
| `CEIL()`  | Round up       | `CEIL(number)`                 |
| `FLOOR()` | Round down     | `FLOOR(number)`                |
| `ABS()`   | Absolute value | `ABS(number)`                  |
| `MOD()`   | Remainder      | `MOD(a,b)`                     |
| `POWER()` | Exponent       | `POWER(a,b)`                   |
| `SQRT()`  | Square root    | `SQRT(number)`                 |

## Examples

```sql
SELECT ROUND(15.678,2);

SELECT CEIL(15.2);

SELECT FLOOR(15.8);

SELECT ABS(-90);

SELECT MOD(15,4);

SELECT POWER(5,3);

SELECT SQRT(49);
```

---

# 5. NULL Functions

| Function     | Purpose                          | Syntax                    |
| ------------ | -------------------------------- | ------------------------- |
| `IFNULL()`   | Replace NULL values (MySQL)      | `IFNULL(column,value)`    |
| `COALESCE()` | Returns first non-NULL value     | `COALESCE(col1,col2,...)` |
| `NULLIF()`   | Returns NULL if values are equal | `NULLIF(a,b)`             |

## Examples

```sql
SELECT IFNULL(salary,0);

SELECT COALESCE(phone,mobile,'Not Available');

SELECT NULLIF(10,10);
```

---

# 6. Window Functions

| Function       | Purpose                 | Syntax                   |
| -------------- | ----------------------- | ------------------------ |
| `ROW_NUMBER()` | Unique row numbering    | `ROW_NUMBER() OVER(...)` |
| `RANK()`       | Ranking with gaps       | `RANK() OVER(...)`       |
| `DENSE_RANK()` | Ranking without gaps    | `DENSE_RANK() OVER(...)` |
| `NTILE()`      | Divide rows into groups | `NTILE(n) OVER(...)`     |
| `LEAD()`       | Get next row value      | `LEAD(column) OVER(...)` |
| `LAG()`        | Get previous row value  | `LAG(column) OVER(...)`  |

## Examples

```sql
SELECT ROW_NUMBER()
OVER(ORDER BY salary DESC);

SELECT RANK()
OVER(ORDER BY salary DESC);

SELECT DENSE_RANK()
OVER(ORDER BY salary DESC);

SELECT LEAD(salary)
OVER(ORDER BY salary);

SELECT LAG(salary)
OVER(ORDER BY salary);
```

---

# 7. Conditional Function

## CASE

### Syntax

```sql
CASE
    WHEN condition THEN value
    WHEN condition THEN value
    ELSE value
END
```

### Example

```sql
SELECT
CASE
    WHEN salary > 50000 THEN 'High'
    ELSE 'Low'
END
FROM Employee;
```
# Other uses

```sql
CASE
    WHEN condition1 THEN result1
    WHEN condition2 THEN result2
    ...
    ELSE default_result
END AS column_name
```

# Example 1: Convert Gender Codes

```sql
SELECT
    first_name,
    last_name,
    CASE
        WHEN gender = 'M' THEN 'MALE'
        ELSE 'FEMALE'
    END AS gender
FROM patients;
```

### Output

| first_name | last_name | gender |
|------------|-----------|--------|
| John | Smith | MALE |
| Emma | Brown | FEMALE |

---

# Example 2: Classify Patients by Age

```sql
SELECT
    first_name,
    age,
    CASE
        WHEN age < 18 THEN 'Child'
        WHEN age >= 18 AND age < 60 THEN 'Adult'
        ELSE 'Senior'
    END AS age_group
FROM patients;
```

### Output

| first_name | age | age_group |
|------------|-----|-----------|
| Alice | 12 | Child |
| Bob | 35 | Adult |
| Mary | 67 | Senior |

---
### `ORDER BY CASE` — Put Specific Value First

Use `CASE` inside `ORDER BY` when you want a **specific value to always come first/last**, regardless of alphabetical order.

```sql
ORDER BY
    CASE 
        WHEN column = 'SpecificValue' THEN 0
        ELSE 1
    END,
    column ASC;
```

**Example: Ontario first, then alphabetical:**

```sql
ORDER BY
    CASE 
        WHEN province_name = 'Ontario' THEN 0
        ELSE 1
    END,
    province_name ASC;
```
 **Remember:**

* `0` → comes **first**
* `1` → comes **after**
* Second `ORDER BY` → sorts the remaining values

---

## Key Points

- `CASE` is evaluated from top to bottom.
- The first matching `WHEN` condition is returned.
- `ELSE` is optional. If omitted and no condition matches, the result is `NULL`.
- Always end the statement with `END`.
- Use `AS` to give the computed column a meaningful name.
---

# 8. Functions Used with GROUP BY

Common aggregate functions:

```text
COUNT()
SUM()
AVG()
MIN()
MAX()
```

Example:

```sql
SELECT department,
AVG(salary)
FROM Employee
GROUP BY department;
```

---

# 9. Frequently Asked SQL Functions

* `UPPER()`
* `LOWER()`
* `LENGTH()`
* `SUBSTRING()`
* `INSTR()`
* `REPLACE()`
* `CONCAT()`
* `TRIM()`
* `COUNT()`
* `SUM()`
* `AVG()`
* `MIN()`
* `MAX()`
* `ROUND()`
* `IFNULL()`
* `COALESCE()`
* `NOW()`
* `DATEDIFF()`
* `ROW_NUMBER()`
* `RANK()`
* `DENSE_RANK()`
* `LEAD()`
* `LAG()`
* `CASE`

---

# UNION vs UNION ALL

## 1. UNION

`UNION` combines results from multiple queries and removes duplicate rows.

### Syntax

```sql
SELECT column1, column2
FROM table1

UNION

SELECT column1, column2
FROM table2;
```

### Example

### Student_A

| Name | GPA |
| ---- | --- |
| Riya | 9.5 |
| Amit | 9.0 |
| John | 8.5 |

### Student_B

| Name  | GPA |
| ----- | --- |
| Riya  | 9.5 |
| Neha  | 9.2 |
| Rahul | 8.8 |

Query:

```sql
SELECT Name, GPA FROM Student_A

UNION

SELECT Name, GPA FROM Student_B;
```

Output:

| Name  | GPA |
| ----- | --- |
| Riya  | 9.5 |
| Amit  | 9.0 |
| John  | 8.5 |
| Neha  | 9.2 |
| Rahul | 8.8 |

Duplicate `Riya` is removed.

---

# 2. UNION ALL

`UNION ALL` combines results and keeps duplicate rows.

### Syntax

```sql
SELECT column1, column2
FROM table1

UNION ALL

SELECT column1, column2
FROM table2;
```

Example:

```sql
SELECT Name, GPA FROM Student_A

UNION ALL

SELECT Name, GPA FROM Student_B;
```

Output:

| Name  | GPA |
| ----- | --- |
| Riya  | 9.5 |
| Amit  | 9.0 |
| John  | 8.5 |
| Riya  | 9.5 |
| Neha  | 9.2 |
| Rahul | 8.8 |

Duplicate `Riya` is retained.

---

# Difference Between UNION and UNION ALL

| Feature              | UNION            | UNION ALL    |
| -------------------- | ---------------- | ------------ |
| Removes duplicates   | Yes              | No           |
| Keeps duplicate rows | No               | Yes          |
| Speed                | Slower           | Faster       |
| Sorting overhead     | Usually required | Not required |
| Memory usage         | Higher           | Lower        |

---
# SQL Subqueries in the `FROM` Clause (Derived Tables)

A **subquery** is a query written inside another query.

When a subquery is placed inside the `FROM` clause, SQL treats its result as a **temporary table** (also called a **derived table**).

---

# Syntax

```sql
SELECT column_name(s)
FROM (
    SELECT column_name(s)
    FROM table_name
    WHERE condition
    GROUP BY column_name
) AS subquery_alias;
```

> **Important:** Most SQL databases require an alias (`AS subquery_alias`) for the subquery.
# User-Defined Variables in MySQL

A user-defined variable stores a value temporarily during a session.

## Syntax

```sql
SET @variable_name = value;
```

Example:

```sql
SET @count = 10;
```

Now:

```sql
@count
```

stores:

```
10
```

## Example with SQL Query

```sql
SET @half_count = (
    SELECT FLOOR(COUNT(*) / 2)
    FROM Student
);

SELECT *
FROM Student
LIMIT @half_count;
```

Explanation:

1. `COUNT(*)` counts total rows.
2. Divide by `2` to get 50%.
3. `FLOOR()` removes decimal values.
4. Store result in `@half_count`.
5. Use it in `LIMIT` to fetch that many rows.

Example:

If Student table has 100 records:

```
COUNT(*) = 100

100 / 2 = 50

@half_count = 50
```

Then:

```sql
SELECT *
FROM Student
LIMIT 50;
```

returns the first 50 records.


<img width="644" height="611" alt="image" src="https://github.com/user-attachments/assets/8ef3a51f-c8bd-4db3-b65b-8686b50a33fc" />
![Uploading image.png…]()

