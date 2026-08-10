# SQL Data Type Conversions --- MySQL Cheat Sheet

This cheat sheet covers the **common MySQL data type conversions**
useful for SQL practice, interviews, and LeetCode/SQL exercises.

------------------------------------------------------------------------

# 1. Main Conversion Methods

MySQL commonly uses:

``` sql
CAST(expression AS type)
```

``` sql
CONVERT(expression, type)
```

For some conversions, functions such as `DATE()`, `TIME()`, `YEAR()`,
`MONTH()`, `CONCAT()`, and `STR_TO_DATE()` are also useful.

------------------------------------------------------------------------

# 2. INT → STRING

## Using CAST()

``` sql
SELECT CAST(patient_id AS CHAR)
FROM patients;
```

## Using CONVERT()

``` sql
SELECT CONVERT(patient_id, CHAR)
FROM patients;
```

## Using CONCAT()

``` sql
SELECT CONCAT(patient_id, '')
FROM patients;
```

### Recommended

``` sql
CAST(patient_id AS CHAR)
```

------------------------------------------------------------------------

# 3. STRING → INT

## Using CAST()

``` sql
SELECT CAST('123' AS UNSIGNED);
```

## Using CONVERT()

``` sql
SELECT CONVERT('123', UNSIGNED);
```

Result:

``` text
123
```

### Signed integer

``` sql
SELECT CAST('-123' AS SIGNED);
```

### Recommended

``` sql
CAST(column_name AS UNSIGNED)
```

Use `SIGNED` when negative values are possible.

------------------------------------------------------------------------

# 4. INT → DECIMAL

``` sql
SELECT CAST(100 AS DECIMAL(10,2));
```

Result:

``` text
100.00
```

You can also use:

``` sql
SELECT CAST(column_name AS DECIMAL(10,2))
FROM table_name;
```

------------------------------------------------------------------------

# 5. DECIMAL → INT

``` sql
SELECT CAST(123.89 AS SIGNED);
```

Result:

``` text
123
```

For positive values:

``` sql
SELECT CAST(123.89 AS UNSIGNED);
```

> Note: `CAST(... AS SIGNED)` is generally used when you want an integer
> representation. If you specifically need rounding, use `ROUND()`.

``` sql
SELECT ROUND(123.89);
```

------------------------------------------------------------------------

# 6. STRING → DECIMAL

``` sql
SELECT CAST('123.45' AS DECIMAL(10,2));
```

Result:

``` text
123.45
```

Example:

``` sql
SELECT CAST(price AS DECIMAL(10,2))
FROM products;
```

------------------------------------------------------------------------

# 7. DECIMAL → STRING

``` sql
SELECT CAST(123.45 AS CHAR);
```

Or:

``` sql
SELECT CONVERT(123.45, CHAR);
```

------------------------------------------------------------------------

# 8. INT → FLOAT

MySQL's `CAST()` does not use `FLOAT` as a general-purpose
`CAST(... AS FLOAT)` target in the same way some other SQL databases do.

A common approach is:

``` sql
SELECT CAST(100 AS DECIMAL(10,2));
```

or use arithmetic:

``` sql
SELECT 100 * 1.0;
```

For most SQL practice questions, `DECIMAL` is preferable when exact
decimal precision matters.

------------------------------------------------------------------------

# 9. FLOAT → INT

``` sql
SELECT CAST(123.89 AS SIGNED);
```

Result:

``` text
123
```

If you want rounding instead:

``` sql
SELECT ROUND(123.89);
```

If you want to always round down:

``` sql
SELECT FLOOR(123.89);
```

If you want to always round up:

``` sql
SELECT CEIL(123.11);
```

------------------------------------------------------------------------

# 10. STRING → FLOAT / DECIMAL

For exact numeric values, use `DECIMAL`:

``` sql
SELECT CAST('123.45' AS DECIMAL(10,2));
```

For approximate numeric calculations, MySQL can infer a floating-point
value through arithmetic:

``` sql
SELECT '123.45' * 1.0;
```

------------------------------------------------------------------------

# 11. STRING → DATE

Use `STR_TO_DATE()` when the string has a known format.

``` sql
SELECT STR_TO_DATE('2026-08-11', '%Y-%m-%d');
```

Result:

``` text
2026-08-11
```

Example:

``` sql
SELECT STR_TO_DATE(date_string, '%d/%m/%Y')
FROM table_name;
```

For:

``` text
11/08/2026
```

use:

``` sql
STR_TO_DATE(date_string, '%d/%m/%Y')
```

------------------------------------------------------------------------

# 12. DATE → STRING

Use `DATE_FORMAT()`:

``` sql
SELECT DATE_FORMAT(order_date, '%Y-%m-%d')
FROM orders;
```

Example:

``` sql
SELECT DATE_FORMAT(order_date, '%d/%m/%Y')
FROM orders;
```

Common format symbols:

  Symbol   Meaning                             Example
  -------- ----------------------------------- ----------
  `%Y`     4-digit year                        `2026`
  `%y`     2-digit year                        `26`
  `%m`     Month number                        `08`
  `%c`     Month number without leading zero   `8`
  `%d`     Day with leading zero               `11`
  `%e`     Day without leading zero            `11`
  `%M`     Full month name                     `August`
  `%b`     Short month name                    `Aug`

------------------------------------------------------------------------

# 13. DATETIME → DATE

Use `DATE()`:

``` sql
SELECT DATE(created_at)
FROM users;
```

Example:

``` text
2026-08-11 14:35:20
```

becomes:

``` text
2026-08-11
```

Alternative:

``` sql
SELECT CAST(created_at AS DATE)
FROM users;
```

------------------------------------------------------------------------

# 14. DATE → DATETIME

A `DATE` can be cast to `DATETIME`:

``` sql
SELECT CAST(order_date AS DATETIME)
FROM orders;
```

A date such as:

``` text
2026-08-11
```

becomes a datetime value with a time component, typically:

``` text
2026-08-11 00:00:00
```

------------------------------------------------------------------------

# 15. STRING → DATETIME

Use `STR_TO_DATE()`:

``` sql
SELECT STR_TO_DATE(
    '2026-08-11 14:30:00',
    '%Y-%m-%d %H:%i:%s'
);
```

Common time format symbols:

  Symbol   Meaning         Example
  -------- --------------- ---------
  `%H`     Hour (00--23)   `14`
  `%h`     Hour (01--12)   `02`
  `%i`     Minutes         `30`
  `%s`     Seconds         `00`
  `%p`     AM/PM           `PM`

------------------------------------------------------------------------

# 16. DATETIME → STRING

Use `DATE_FORMAT()`:

``` sql
SELECT DATE_FORMAT(
    created_at,
    '%Y-%m-%d %H:%i:%s'
)
FROM users;
```

------------------------------------------------------------------------

# 17. DATETIME → TIME

``` sql
SELECT TIME(created_at)
FROM users;
```

Example:

``` text
2026-08-11 14:30:00
```

becomes:

``` text
14:30:00
```

Alternative:

``` sql
SELECT CAST(created_at AS TIME)
FROM users;
```

------------------------------------------------------------------------

# 18. TIME → STRING

``` sql
SELECT CAST('14:30:00' AS CHAR);
```

Or:

``` sql
SELECT TIME_FORMAT(start_time, '%H:%i:%s')
FROM appointments;
```

------------------------------------------------------------------------

# 19. STRING → TIME

Use `STR_TO_DATE()`:

``` sql
SELECT STR_TO_DATE('14:30:00', '%H:%i:%s');
```

You can also use:

``` sql
SELECT CAST('14:30:00' AS TIME);
```

------------------------------------------------------------------------

# 20. DATE → YEAR

Use `YEAR()`:

``` sql
SELECT YEAR(order_date)
FROM orders;
```

Example:

``` text
2026-08-11
```

becomes:

``` text
2026
```

------------------------------------------------------------------------

# 21. DATE → MONTH

``` sql
SELECT MONTH(order_date)
FROM orders;
```

Result:

``` text
8
```

For month name:

``` sql
SELECT MONTHNAME(order_date)
FROM orders;
```

Result:

``` text
August
```

------------------------------------------------------------------------

# 22. DATE → DAY

``` sql
SELECT DAY(order_date)
FROM orders;
```

For day of month:

``` sql
SELECT DAYOFMONTH(order_date)
FROM orders;
```

------------------------------------------------------------------------

# 23. DATE → DAY OF WEEK

``` sql
SELECT DAYOFWEEK(order_date)
FROM orders;
```

or:

``` sql
SELECT DAYNAME(order_date)
FROM orders;
```

Example:

``` text
Monday
```

------------------------------------------------------------------------

# 24. YEAR / MONTH / DAY → DATE

Use `MAKEDATE()` for year + day-of-year:

``` sql
SELECT MAKEDATE(2026, 223);
```

For explicit year/month/day, `STR_TO_DATE()` is often convenient:

``` sql
SELECT STR_TO_DATE('2026-08-11', '%Y-%m-%d');
```

------------------------------------------------------------------------

# 25. STRING → BOOLEAN

MySQL commonly represents Boolean values as `0` and `1`.

``` sql
SELECT CAST('1' AS UNSIGNED);
```

Result:

``` text
1
```

You can also use:

``` sql
SELECT IF(value = 'true', 1, 0)
FROM table_name;
```

MySQL accepts:

``` sql
TRUE
FALSE
```

as Boolean-style values, where:

``` text
TRUE  = 1
FALSE = 0
```

------------------------------------------------------------------------

# 26. BOOLEAN → STRING

``` sql
SELECT CAST(is_active AS CHAR)
FROM users;
```

Or:

``` sql
SELECT IF(is_active = 1, 'TRUE', 'FALSE')
FROM users;
```

------------------------------------------------------------------------

# 27. BOOLEAN → INT

MySQL Boolean values are already represented numerically:

``` sql
SELECT is_active + 0
FROM users;
```

Or explicitly:

``` sql
SELECT CAST(is_active AS UNSIGNED)
FROM users;
```

------------------------------------------------------------------------

# 28. INT → BOOLEAN

``` sql
SELECT IF(value <> 0, TRUE, FALSE)
FROM table_name;
```

For example:

``` sql
SELECT IF(age >= 18, 1, 0)
FROM patients;
```

------------------------------------------------------------------------

# 29. NULL → Default Value

This is not technically a data-type conversion, but it is extremely
common in SQL.

Use `COALESCE()`:

``` sql
SELECT COALESCE(phone, 'Unknown')
FROM patients;
```

For numbers:

``` sql
SELECT COALESCE(salary, 0)
FROM employees;
```

Alternative:

``` sql
SELECT IFNULL(salary, 0)
FROM employees;
```

------------------------------------------------------------------------

# 30. NULL → STRING

``` sql
SELECT COALESCE(CAST(patient_id AS CHAR), 'Unknown')
FROM patients;
```

------------------------------------------------------------------------

# 31. Number → Formatted STRING

Use `FORMAT()`:

``` sql
SELECT FORMAT(1234567.89, 2);
```

Result:

``` text
1,234,567.89
```

> `FORMAT()` returns a string, not a numeric value.

------------------------------------------------------------------------

# 32. Number → HEX STRING

``` sql
SELECT HEX(255);
```

Result:

``` text
FF
```

------------------------------------------------------------------------

# 33. HEX STRING → BINARY

``` sql
SELECT UNHEX('FF');
```

This converts hexadecimal text into binary data.

------------------------------------------------------------------------

# 34. BINARY → HEX STRING

``` sql
SELECT HEX(binary_column)
FROM table_name;
```

------------------------------------------------------------------------

# 35. STRING → BINARY

``` sql
SELECT CAST('hello' AS BINARY);
```

You can also specify a length:

``` sql
SELECT CAST('hello' AS BINARY(10));
```

------------------------------------------------------------------------

# 36. BINARY → STRING

A binary value can be converted to character data:

``` sql
SELECT CAST(binary_column AS CHAR)
FROM table_name;
```

For a specific character set:

``` sql
SELECT CONVERT(binary_column USING utf8mb4)
FROM table_name;
```

------------------------------------------------------------------------

# 37. CHAR → VARCHAR

In MySQL, explicit conversion is usually unnecessary for ordinary use,
but you can use:

``` sql
SELECT CAST(char_column AS CHAR)
FROM table_name;
```

If you need a specific length:

``` sql
SELECT CAST(char_column AS CHAR(100))
FROM table_name;
```

The distinction between `CHAR` and `VARCHAR` is primarily a **column
storage/data type definition**, not something you normally need to
convert in a `SELECT`.

------------------------------------------------------------------------

# 38. VARCHAR → CHAR

``` sql
SELECT CAST(varchar_column AS CHAR)
FROM table_name;
```

Again, this is usually unnecessary for normal querying.

------------------------------------------------------------------------

# 39. JSON → STRING

``` sql
SELECT CAST(json_column AS CHAR)
FROM table_name;
```

You can also extract a JSON value as text:

``` sql
SELECT JSON_UNQUOTE(JSON_EXTRACT(json_column, '$.name'))
FROM table_name;
```

For example, JSON:

``` json
{"name": "Riya"}
```

``` sql
SELECT JSON_UNQUOTE(
    JSON_EXTRACT(json_column, '$.name')
)
FROM users;
```

Result:

``` text
Riya
```

------------------------------------------------------------------------

# 40. STRING → JSON

``` sql
SELECT CAST('{"name":"Riya"}' AS JSON);
```

Or:

``` sql
SELECT JSON_OBJECT('name', 'Riya');
```

------------------------------------------------------------------------

# 41. JSON → INT

Extract the JSON value and cast it:

``` sql
SELECT CAST(
    JSON_UNQUOTE(JSON_EXTRACT(json_column, '$.age'))
    AS UNSIGNED
)
FROM users;
```

------------------------------------------------------------------------

# 42. INT → JSON

``` sql
SELECT CAST(25 AS JSON);
```

Or create JSON:

``` sql
SELECT JSON_OBJECT('age', 25);
```

------------------------------------------------------------------------

# 43. STRING → JSON NUMBER

If a JSON document contains a numeric value as a string and you need a
number:

``` sql
SELECT CAST(
    JSON_UNQUOTE(JSON_EXTRACT(json_column, '$.age'))
    AS UNSIGNED
)
FROM users;
```

------------------------------------------------------------------------

# 44. Important CAST Types in MySQL

Common `CAST()` targets include:

``` sql
CHAR
SIGNED
UNSIGNED
DECIMAL(M,D)
DATE
DATETIME
TIME
BINARY
JSON
```

Examples:

``` sql
CAST(x AS CHAR)

CAST(x AS SIGNED)

CAST(x AS UNSIGNED)

CAST(x AS DECIMAL(10,2))

CAST(x AS DATE)

CAST(x AS DATETIME)

CAST(x AS TIME)

CAST(x AS BINARY)

CAST(x AS JSON)
```

------------------------------------------------------------------------

# 45. CAST vs CONVERT

## CAST

More portable SQL syntax:

``` sql
CAST(value AS CHAR)
```

``` sql
CAST(value AS SIGNED)
```

``` sql
CAST(value AS DATE)
```

## CONVERT

MySQL supports:

``` sql
CONVERT(value, CHAR)
```

``` sql
CONVERT(value, SIGNED)
```

``` sql
CONVERT(value, DATE)
```

It also has a MySQL-specific character-set form:

``` sql
CONVERT(value USING utf8mb4)
```

------------------------------------------------------------------------

# 46. Most Important Conversions for SQL Interviews

If you are preparing for SQL coding questions, memorize these first:

## INT → STRING

``` sql
CAST(column AS CHAR)
```

## STRING → INT

``` sql
CAST(column AS UNSIGNED)
```

## STRING → DECIMAL

``` sql
CAST(column AS DECIMAL(10,2))
```

## DECIMAL → INT

``` sql
CAST(column AS SIGNED)
```

## STRING → DATE

``` sql
STR_TO_DATE(column, '%Y-%m-%d')
```

## DATE → STRING

``` sql
DATE_FORMAT(column, '%Y-%m-%d')
```

## DATETIME → DATE

``` sql
DATE(column)
```

or:

``` sql
CAST(column AS DATE)
```

## DATETIME → TIME

``` sql
TIME(column)
```

## DATE → YEAR

``` sql
YEAR(column)
```

## DATE → MONTH

``` sql
MONTH(column)
```

## DATE → DAY

``` sql
DAY(column)
```

## NULL → Default

``` sql
COALESCE(column, default_value)
```

------------------------------------------------------------------------

# 47. Quick Conversion Table

  From       To                 Common MySQL Method
  ---------- ------------------ ---------------------------------------
  INT        STRING             `CAST(x AS CHAR)`
  STRING     INT                `CAST(x AS UNSIGNED)`
  STRING     SIGNED INT         `CAST(x AS SIGNED)`
  INT        DECIMAL            `CAST(x AS DECIMAL(10,2))`
  DECIMAL    INT                `CAST(x AS SIGNED)`
  STRING     DECIMAL            `CAST(x AS DECIMAL(10,2))`
  DECIMAL    STRING             `CAST(x AS CHAR)`
  NUMBER     STRING             `CAST(x AS CHAR)`
  NUMBER     formatted STRING   `FORMAT(x, 2)`
  STRING     DATE               `STR_TO_DATE()`
  DATE       STRING             `DATE_FORMAT()`
  DATETIME   DATE               `DATE()` / `CAST(... AS DATE)`
  DATE       DATETIME           `CAST(... AS DATETIME)`
  DATETIME   TIME               `TIME()` / `CAST(... AS TIME)`
  STRING     TIME               `CAST(... AS TIME)`
  TIME       STRING             `CAST(... AS CHAR)`
  DATE       YEAR               `YEAR()`
  DATE       MONTH              `MONTH()`
  DATE       DAY                `DAY()`
  DATE       DAY NAME           `DAYNAME()`
  DATE       MONTH NAME         `MONTHNAME()`
  INT        BOOLEAN            `IF(x <> 0, 1, 0)`
  BOOLEAN    INT                `CAST(x AS UNSIGNED)`
  BOOLEAN    STRING             `IF(x=1,'TRUE','FALSE')`
  STRING     BINARY             `CAST(x AS BINARY)`
  BINARY     STRING             `CAST(x AS CHAR)`
  BINARY     HEX                `HEX(x)`
  HEX        BINARY             `UNHEX(x)`
  STRING     JSON               `CAST(x AS JSON)`
  JSON       STRING             `CAST(x AS CHAR)`
  JSON       INT                `CAST(JSON_EXTRACT(...) AS UNSIGNED)`
  NULL       Default            `COALESCE(x, default)`

------------------------------------------------------------------------

# 48. Easy Rule to Remember

For basic SQL problems:

``` text
INT      ↔ CHAR
NUMBER   ↔ DECIMAL
STRING   ↔ DATE
DATETIME → DATE / TIME
DATE     → YEAR / MONTH / DAY
NULL     → COALESCE()
JSON     → Extract → CAST()
```

The most important syntax to remember is:

``` sql
CAST(value AS data_type)
```

Examples:

``` sql
CAST(123 AS CHAR)

CAST('123' AS UNSIGNED)

CAST('123.45' AS DECIMAL(10,2))

CAST('2026-08-11' AS DATE)

CAST('2026-08-11 10:30:00' AS DATETIME)
```
