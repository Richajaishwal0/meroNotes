### Basic Regex Patterns

| Pattern  | Meaning                 | Example                |       |      |
| -------- | ----------------------- | ---------------------- | ----- | ---- |
| `^`      | Start of string         | `^A` → starts with A   |       |      |
| `$`      | End of string           | `com$` → ends with com |       |      |
| `.`      | Any single character    | `a.c` → `abc`, `axc`   |       |      |
| `[abc]`  | One of a, b, c          | `[aeiou]` → vowel      |       |      |
| `[a-z]`  | Any lowercase letter    | `[a-z]`                |       |      |
| `[A-Z]`  | Any uppercase letter    | `[A-Z]`                |       |      |
| `[0-9]`  | Any digit               | `[0-9]`                |       |      |
| `[^abc]` | Anything except a, b, c | `[^0-9]` → non-digit   |       |      |
| `*`      | 0 or more               | `a*`                   |       |      |
| `+`      | 1 or more               | `a+`                   |       |      |
| `?`      | 0 or 1                  | `a?`                   |       |      |
| `{n}`    | Exactly n times         | `[0-9]{4}`             |       |      |
| `{n,m}`  | Between n and m times   | `[0-9]{2,4}`           |       |      |
| `        | `                       | OR                     | `cat  | dog` |
| `( )`    | Grouping                | `(cat                  | dog)` |      |

---

### 1. `^` — starts with

```sql
REGEXP_LIKE(name, '^A', 'c')
```

Matches:

```text
Alice   ✅
Ananya  ✅
Bob     ❌
```

---

### 2. `$` — ends with

```sql
REGEXP_LIKE(mail, 'com$', 'c')
```

Matches:

```text
abc@gmail.com   ✅
abc@gmail.org   ❌
```

---

### 3. `[0-9]` — digit

```sql
REGEXP_LIKE(phone, '[0-9]', 'c')
```

Checks whether there is a digit.

---

### 4. `[0-9]+` — one or more digits

```sql
REGEXP_LIKE(code, '^[0-9]+$', 'c')
```

This means:

> The **entire string** must contain only digits.

```text
12345   ✅
123     ✅
12a3    ❌
abc     ❌
```

---

### 5. `{n}` — exact number of characters

For example, exactly **4 digits**:

```sql
REGEXP_LIKE(code, '^[0-9]{4}$', 'c')
```

```text
1234    ✅
12345   ❌
123     ❌
```

Very useful for things like **PIN codes, years, etc.**

---

### 6. `{n,m}` — range

```sql
REGEXP_LIKE(code, '^[0-9]{2,4}$', 'c')
```

Means:

> 2 to 4 digits.

```text
12      ✅
123     ✅
1234    ✅
1       ❌
12345   ❌
```

---

### 7. `+` — one or more

```sql
REGEXP_LIKE(name, '^[A-Za-z]+$', 'c')
```

Means:

> One or more letters only.

```text
Richa    ✅
Alice    ✅
Richa123 ❌
Richa_   ❌
```

---

### 8. `*` — zero or more

This is what you used:

```text
[a-zA-Z0-9_.-]*
```

It means:

> These characters can appear **zero or more times**.

That's why:

```text
a@leetcode.com
```

is valid — there are **zero characters** between `a` and `@`.

---

### 9. `|` — OR

```sql
REGEXP_LIKE(name, '^(Alice|Bob)$', 'c')
```

Matches exactly:

```text
Alice   ✅
Bob     ✅
Richa   ❌
```

---

### 10. `[^...]` — NOT these characters

```sql
REGEXP_LIKE(code, '^[^0-9]+$', 'c')
```

Means:

> Contains only characters that are **not digits**.

```text
abc     ✅
hello   ✅
abc12   ❌
123     ❌
```

---

## ⭐ Most important for LeetCode

For SQL problems, I'd memorize these first:

```text
^          start
$          end
[]         allowed characters
[^]        NOT allowed characters
*          0 or more
+          1 or more
{n}        exactly n
{n,m}      n to m
|          OR
.          any character
[.]        literal dot
```

And the SQL syntax:

```sql
REGEXP_LIKE(column, 'pattern', 'c')
```
