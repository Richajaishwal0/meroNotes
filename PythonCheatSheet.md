# Python in One Day — Beginner-Friendly Cheat Sheet

> **Goal:** Learn the Python syntax and ideas you are most likely to need in one focused day.
>
> This guide is a **simplified version of the uploaded Beginner's Python Cheat Sheet**. It keeps the important concepts and examples, but removes repetition and puts related ideas together. fileciteturn0file0L5-L18

---

## How to use this file

If you have only **one day**, don't try to memorize everything.

### Priority order

1. ⭐ Variables + data types
2. ⭐ Strings
3. ⭐ Lists
4. ⭐ Dictionaries
5. ⭐ `if / elif / else`
6. ⭐ `for` loops + `range()`
7. ⭐ `while` loops
8. ⭐ Functions
9. ⭐ List comprehensions
10. ⭐ Tuples
11. ⭐ Classes / OOP basics
12. Read files + exceptions
13. Modules, `*args`, `**kwargs` — learn last

The source emphasizes keeping solutions simple when possible. That is a good rule for one-day revision too. fileciteturn1file8L924-L944

---

# 1. Variables

A variable is simply a **name attached to a value**.

```python
name = "Richa"
age = 20
marks = 95.5
is_student = True
```

### Basic data types

```python
name = "Richa"       # str
age = 20             # int
price = 99.5         # float
passed = True        # bool
```

Think:

```text
"hello"  → string
10       → integer
10.5     → float
True     → boolean
```

---

# 2. Printing

```python
print("Hello")
print(name)
print(age)
```

### f-strings ⭐

Use f-strings when you want variables inside text.

```python
name = "Richa"
age = 20

print(f"My name is {name}")
print(f"I am {age} years old")
```

The source uses f-strings for building dynamic messages. fileciteturn1file0L13-L27

---

# 3. Strings

A string is text inside quotes.

```python
name = "python"
```

### Common string operations

```python
name = "python"

print(name.upper())      # PYTHON
print(name.lower())      # python
print(name.title())      # Python
print(len(name))         # 6
```

### Indexing

Python starts indexing from **0**.

```python
word = "Python"

print(word[0])    # P
print(word[1])    # y
print(word[-1])   # n
```

Remember:

```text
 P  y  t  h  o  n
 0  1  2  3  4  5
```

---

# 4. Lists ⭐⭐⭐

A list stores multiple values in order.

```python
fruits = ["apple", "banana", "mango"]
```

## Access elements

```python
print(fruits[0])     # apple
print(fruits[-1])    # mango
```

Python lists use indexes starting at 0, and negative indexes access items from the end. fileciteturn1file9L1015-L1029

## Change an element

```python
fruits[0] = "orange"
```

## Add elements

### `append()` → add at end

```python
fruits.append("grapes")
```

### `insert()` → add at a specific index

```python
fruits.insert(1, "kiwi")
```

The source covers `append()` and `insert()` as the main ways to add list elements. fileciteturn1file9L1038-L1053

## Remove elements

### `del`

Remove using index:

```python
del fruits[0]
```

### `remove()`

Remove using value:

```python
fruits.remove("banana")
```

### `pop()`

Remove **and return** an item:

```python
x = fruits.pop()       # last item
x = fruits.pop(0)      # first item
```

---

# 5. Useful list functions

```python
nums = [5, 2, 9, 1]
```

### Length

```python
len(nums)       # 4
```

### Minimum

```python
min(nums)       # 1
```

### Maximum

```python
max(nums)       # 9
```

### Sum

```python
sum(nums)       # 17
```

### Sort

```python
nums.sort()                 # changes original list
nums.sort(reverse=True)    # descending
```

### `sorted()`

```python
new_nums = sorted(nums)
```

Difference:

```text
sort()     → changes original list
sorted()   → creates sorted result
```

The source explicitly distinguishes permanent `sort()` from `sorted()`, which returns a sorted copy. fileciteturn0file0L324-L340

---

# 6. List slicing ⭐

Slicing means taking part of a list.

```python
nums = [10, 20, 30, 40, 50]
```

```python
nums[1:4]
```

Result:

```text
[20, 30, 40]
```

Important pattern:

```python
list[start:end]
```

`end` is **not included**.

### Common patterns

```python
nums[:3]      # first 3
nums[2:]      # from index 2 to end
nums[-3:]     # last 3
nums[:]       # copy
```

The source uses slicing for selecting parts of a list and copying a list. fileciteturn0file0L391-L412

---

# 7. `for` loops ⭐⭐⭐

Use a `for` loop when you want to process each item.

```python
fruits = ["apple", "banana", "mango"]

for fruit in fruits:
    print(fruit)
```

Think:

```text
for each item in collection:
    do something
```

---

# 8. `range()` ⭐⭐⭐

`range()` generates numbers.

```python
for i in range(5):
    print(i)
```

Output:

```text
0
1
2
3
4
```

### Start and end

```python
for i in range(1, 6):
    print(i)
```

Output:

```text
1
2
3
4
5
```

Remember:

```python
range(start, end)
```

The `end` is excluded. The source explains that `range()` starts at 0 by default and stops one number before the given endpoint. fileciteturn0file0L365-L378

---

# 9. Loop with index

Sometimes you need the index too.

```python
fruits = ["apple", "banana", "mango"]

for i in range(len(fruits)):
    print(i, fruits[i])
```

---

# 10. List comprehensions ⭐⭐

A short way to create a list.

Normal:

```python
squares = []

for x in range(1, 6):
    squares.append(x ** 2)
```

Comprehension:

```python
squares = [x ** 2 for x in range(1, 6)]
```

Think:

```python
[what_you_want for item in collection]
```

Example:

```python
names = ["richa", "alex", "john"]

upper_names = [name.upper() for name in names]
```

The source recommends using the normal loop first if comprehensions feel confusing. fileciteturn0file0L413-L439

---

# 11. Tuples

A tuple is similar to a list, but you **cannot change individual values** after creation.

```python
point = (10, 20)
```

Access:

```python
print(point[0])
```

Loop:

```python
for value in point:
    print(value)
```

Use:

```text
list  → values may change
tuple → values should stay fixed
```

This is the distinction made in the source. fileciteturn0file0L447-L463

---

# 12. Dictionaries ⭐⭐⭐

A dictionary stores data as:

```text
key → value
```

Example:

```python
student = {
    "name": "Richa",
    "age": 20,
    "marks": 95
}
```

## Access a value

```python
print(student["name"])
print(student["marks"])
```

## Add a new key

```python
student["city"] = "Chennai"
```

## Change a value

```python
student["marks"] = 98
```

## Delete

```python
del student["age"]
```

The source defines dictionaries as collections of key-value pairs and shows accessing, adding, modifying, and deleting values. fileciteturn1file7L775-L806

---

# 13. Dictionary `get()` ⭐⭐

Instead of:

```python
student["phone"]
```

which can give an error if the key doesn't exist, use:

```python
student.get("phone")
```

You can also provide a default:

```python
student.get("phone", "Not available")
```

The source specifically describes `get()` as returning `None`, or a supplied default, when a key is missing. fileciteturn1file7L91-L114

---

# 14. Loop through a dictionary ⭐⭐⭐

### Keys + values

```python
for key, value in student.items():
    print(key, value)
```

### Keys only

```python
for key in student.keys():
    print(key)
```

### Values only

```python
for value in student.values():
    print(value)
```

These three patterns are directly covered in the source. fileciteturn1file7L784-L806

---

# 15. Nested data

You can put a list inside a dictionary:

```python
student = {
    "name": "Richa",
    "skills": ["Python", "SQL", "C++"]
}
```

Access:

```python
print(student["skills"][0])
```

You can also have a list of dictionaries:

```python
students = [
    {"name": "Richa", "age": 20},
    {"name": "Alex", "age": 21}
]
```

The source calls these structures **nesting** and covers lists of dictionaries, lists inside dictionaries, and dictionaries inside dictionaries. fileciteturn1file3L341-L385

---

# 16. `if` statements ⭐⭐⭐

Use `if` to make decisions.

```python
age = 20

if age >= 18:
    print("Adult")
```

## `if / else`

```python
if age >= 18:
    print("Adult")
else:
    print("Minor")
```

## `if / elif / else`

```python
marks = 75

if marks >= 90:
    print("A")
elif marks >= 60:
    print("B")
else:
    print("C")
```

The source covers simple `if`, `if-else`, and `if-elif-else` chains. fileciteturn1file4L469-L492

---

# 17. Comparison operators ⭐⭐⭐

Memorize these:

```text
==     equal
!=     not equal
>      greater than
<      less than
>=     greater than or equal
<=     less than or equal
```

Example:

```python
age = 20

age == 20
age != 18
age > 18
age >= 18
age < 30
age <= 30
```

### VERY IMPORTANT

```python
=       assignment
==      comparison
```

Example:

```python
x = 10       # assign
x == 10      # compare
```

The source explicitly warns about confusing `=` with `==`. fileciteturn1file1L141-L155

---

# 18. `and`, `or`, `not`

### `and`

Both conditions must be true.

```python
age = 20

if age >= 18 and age <= 60:
    print("Allowed")
```

### `or`

At least one condition must be true.

```python
if age < 18 or age > 60:
    print("Special case")
```

### `not`

Reverses True/False.

```python
if not is_valid:
    print("Invalid")
```

The source explains `and` as requiring all conditions and `or` as requiring any condition to be true. fileciteturn1file1L178-L196

---

# 19. `in` and `not in`

Very useful with lists and strings.

```python
fruits = ["apple", "banana"]

if "apple" in fruits:
    print("Found")
```

```python
if "mango" not in fruits:
    print("Not found")
```

The source demonstrates both membership checks and `not in`. fileciteturn1file4L493-L513

---

# 20. User input

`input()` gives you a **string**.

```python
name = input("Enter your name: ")
print(name)
```

For numbers:

```python
age = int(input("Enter age: "))
```

For decimal numbers:

```python
price = float(input("Enter price: "))
```

Remember:

```text
input()        → string
int(input())   → integer
float(input()) → float
```

The source explicitly notes that input is initially stored as a string and must be converted for numerical use. fileciteturn1file4L522-L540

---

# 21. `while` loops ⭐⭐

A `while` loop runs **while a condition is true**.

```python
count = 1

while count <= 5:
    print(count)
    count += 1
```

Think:

```text
while condition is true:
    keep doing this
```

The source describes `while` loops this way and uses an incrementing counter as the basic example. fileciteturn1file5L569-L583

---

# 22. `break`

Stop the loop immediately.

```python
while True:
    x = input("Enter: ")

    if x == "quit":
        break

    print(x)
```

---

# 23. `continue`

Skip the current iteration.

```python
for i in range(10):
    if i == 5:
        continue

    print(i)
```

Output:

```text
0 1 2 3 4 6 7 8 9
```

The source covers both `break` for exiting a loop and `continue` for skipping an item. fileciteturn1file4L541-L548

---

# 24. Avoid infinite loops

Be careful:

```python
while True:
    print("Hello")
```

This never stops unless you use `break` or otherwise terminate it.

A normal `while` loop should have something that eventually makes its condition false. The source specifically warns about infinite loops. fileciteturn1file4L978-L986

---

# 25. Functions ⭐⭐⭐

A function is a reusable block of code.

```python
def greet():
    print("Hello")

greet()
```

Think:

```text
define function
      ↓
call function
```

---

# 26. Function parameters

```python
def greet(name):
    print(f"Hello {name}")

greet("Richa")
greet("Alex")
```

Here:

```text
name   → parameter
"Richa" → argument
```

The source distinguishes a parameter (in the function definition) from an argument (the value passed when calling it). fileciteturn1file5L584-L604

---

# 27. Return values ⭐⭐⭐

A function can calculate something and return it.

```python
def add(a, b):
    return a + b

result = add(5, 3)

print(result)
```

Output:

```text
8
```

Important:

```text
print()  → displays something
return   → sends a value back
```

The source demonstrates functions that return calculated values. fileciteturn1file5L605-L610

---

# 28. Default parameters

```python
def greet(name="User"):
    print(f"Hello {name}")

greet()
```

Output:

```text
Hello User
```

You can override it:

```python
greet("Richa")
```

The source covers default parameter values and notes that parameters without defaults should come before parameters with defaults. fileciteturn1file6L1063-L1083

---

# 29. Positional vs keyword arguments

### Positional

```python
def student(name, age):
    print(name, age)

student("Richa", 20)
```

### Keyword

```python
student(age=20, name="Richa")
```

Keyword arguments explicitly identify which parameter receives each value. fileciteturn1file6L1040-L1062

---

# 30. Passing lists to functions

```python
def print_names(names):
    for name in names:
        print(name)

students = ["Richa", "Alex", "John"]

print_names(students)
```

Lists can be modified inside a function, which can affect the original list. To avoid that, pass a copy:

```python
print_names(students[:])
```

The source explicitly discusses passing lists and using a slice copy to prevent modification of the original list. fileciteturn1file6L1126-L1171

---

# 31. `*args` ⭐

Use `*args` when you don't know how many positional arguments will be passed.

```python
def add_all(*numbers):
    total = 0

    for num in numbers:
        total += num

    return total

print(add_all(1, 2, 3))
print(add_all(1, 2, 3, 4, 5))
```

Think:

```text
*args → many positional arguments
```

The source describes `*args` as collecting an arbitrary number of positional arguments. fileciteturn1file6L673-L695

---

# 32. `**kwargs` ⭐

Use `**kwargs` for many keyword arguments.

```python
def create_profile(**info):
    return info

user = create_profile(
    name="Richa",
    age=20,
    city="Chennai"
)

print(user)
```

Think:

```text
**kwargs → many keyword arguments → dictionary
```

The source describes `**kwargs` as collecting arbitrary keyword arguments into a dictionary. fileciteturn1file6L696-L708

---

# 33. Classes / OOP ⭐⭐

A class is a blueprint for creating objects.

Example:

```python
class Dog:

    def __init__(self, name):
        self.name = name

    def bark(self):
        print(f"{self.name} says Woof!")
```

Create an object:

```python
dog1 = Dog("Bruno")
```

Access attribute:

```python
print(dog1.name)
```

Call method:

```python
dog1.bark()
```

The source describes attributes as information stored in an object and methods as functions belonging to a class. fileciteturn1file8L865-L880

---

# 34. Understand `self`

This is one of the most important beginner OOP ideas.

```python
class Student:

    def __init__(self, name):
        self.name = name
```

When:

```python
s1 = Student("Richa")
```

think:

```text
s1.name = "Richa"
```

`self` refers to the **current object**.

---

# 35. `__init__`

```python
def __init__(self, name):
    self.name = name
```

`__init__` runs automatically when you create an object.

```python
s1 = Student("Richa")
```

Python automatically calls the initializer.

---

# 36. Inheritance

A child class can inherit from a parent class.

```python
class Dog:

    def bark(self):
        print("Woof")


class SearchDog(Dog):

    def search(self):
        print("Searching")
```

Now:

```python
dog = SearchDog()

dog.bark()
dog.search()
```

`SearchDog` gets `bark()` from `Dog`.

The source demonstrates inheritance and `super().__init__()` for initializing the parent class. fileciteturn1file8L881-L893

---

# 37. `super()`

When a child class has its own `__init__`, use:

```python
super().__init__(...)
```

Example:

```python
class Dog:

    def __init__(self, name):
        self.name = name


class SearchDog(Dog):

    def __init__(self, name):
        super().__init__(name)
```

Think:

```text
super() → call parent class functionality
```

---

# 38. Files

The source uses `pathlib` for reading and writing files. fileciteturn1file8L905-L923

### Read a file

```python
from pathlib import Path

path = Path("data.txt")

contents = path.read_text()

print(contents)
```

### Read line by line

```python
from pathlib import Path

path = Path("data.txt")

contents = path.read_text()
lines = contents.splitlines()

for line in lines:
    print(line)
```

### Write to a file

```python
from pathlib import Path

path = Path("output.txt")

path.write_text("Hello Python")
```

---

# 39. Exceptions

Exceptions allow your program to handle errors instead of crashing.

Basic structure:

```python
try:
    # code that may fail
except:
    # what to do if it fails
```

Better:

```python
try:
    age = int(input("Age: "))
except ValueError:
    print("Please enter a number.")
```

### `else`

Run when no exception occurs:

```python
try:
    age = int(input("Age: "))

except ValueError:
    print("Invalid number.")

else:
    print(f"Your age is {age}")
```

The source explains `try`, `except`, and `else` in exactly this pattern. fileciteturn1file8L924-L938

---

# 40. Modules / imports

A module is another Python file containing reusable code.

Suppose:

```text
pizza.py
```

contains:

```python
def make_pizza():
    print("Pizza!")
```

Import it:

```python
import pizza

pizza.make_pizza()
```

Or import only the function:

```python
from pizza import make_pizza

make_pizza()
```

The source covers importing an entire module, importing a specific function, and aliases. fileciteturn1file2L263-L301

---

# 41. Useful built-in functions

Memorize these first:

```python
len(x)       # length
max(x)       # maximum
min(x)       # minimum
sum(x)       # total
sorted(x)    # sorted copy
range(x)     # sequence of numbers
```

Also useful:

```python
type(x)      # type of value
int(x)       # convert to integer
float(x)     # convert to float
str(x)       # convert to string
```

---

# 42. Common Python patterns

## Pattern 1 — Count something

```python
count = 0

for x in nums:
    if x > 5:
        count += 1
```

## Pattern 2 — Find maximum

```python
max_value = nums[0]

for x in nums:
    if x > max_value:
        max_value = x
```

## Pattern 3 — Build a new list

```python
result = []

for x in nums:
    if x > 5:
        result.append(x)
```

## Pattern 4 — Search

```python
found = False

for x in nums:
    if x == target:
        found = True
        break
```

## Pattern 5 — Frequency dictionary ⭐⭐⭐

This is extremely useful.

```python
freq = {}

for x in nums:
    if x in freq:
        freq[x] += 1
    else:
        freq[x] = 1
```

Shorter:

```python
freq = {}

for x in nums:
    freq[x] = freq.get(x, 0) + 1
```

Example:

```python
nums = [1, 2, 2, 3, 3, 3]

freq = {}

for x in nums:
    freq[x] = freq.get(x, 0) + 1

print(freq)
```

Result:

```python
{1: 1, 2: 2, 3: 3}
```

---

# 43. Nested loops

A loop inside another loop:

```python
for i in range(3):

    for j in range(3):
        print(i, j)
```

Think:

```text
i = 0 → j runs 0,1,2
i = 1 → j runs 0,1,2
i = 2 → j runs 0,1,2
```

Useful for:

- matrices
- grids
- comparing every pair
- 2D problems

---

# 44. Common mistakes

## Mistake 1

```python
if x = 5:
```

Wrong.

Use:

```python
if x == 5:
```

---

## Mistake 2 — Forgetting indentation

Wrong:

```python
if age > 18:
print("Adult")
```

Correct:

```python
if age > 18:
    print("Adult")
```

Python uses indentation to define blocks. The source recommends four spaces per indentation level. fileciteturn0file0L440-L446

---

## Mistake 3 — `range()`

```python
range(5)
```

means:

```text
0, 1, 2, 3, 4
```

NOT 1 through 5.

---

## Mistake 4 — Input is a string

This:

```python
age = input("Age: ")
```

does not give an integer.

Use:

```python
age = int(input("Age: "))
```

---

# 45. One-page syntax memory map

```text
VARIABLE
x = 10

STRING
name = "Richa"

LIST
nums = [1, 2, 3]
nums.append(4)
nums.pop()

TUPLE
point = (10, 20)

DICTIONARY
person = {"name": "Richa", "age": 20}
person["name"]

IF
if condition:
    ...
elif condition:
    ...
else:
    ...

FOR
for x in nums:
    ...

RANGE
for i in range(5):
    ...

WHILE
while condition:
    ...

FUNCTION
def add(a, b):
    return a + b

CLASS
class Student:
    def __init__(self, name):
        self.name = name

TRY/EXCEPT
try:
    ...
except ValueError:
    ...

IMPORT
import module
```

---

# 46. What to memorize vs what to understand

## ⭐ MUST MEMORIZE

```text
if / elif / else
for
while
range()
list indexing
list slicing
append()
pop()
remove()
len()
dict[key]
dict.get()
dict.items()
dict.keys()
dict.values()
def
return
class
self
__init__
import
try / except
```

## ⭐ MUST UNDERSTAND

```text
= vs ==
list vs tuple
list vs dictionary
for vs while
parameter vs argument
print vs return
mutable vs fixed data
object vs class
parent vs child class
```

## LOW PRIORITY FOR ONE DAY

Don't spend too much time memorizing:

```text
*args
**kwargs
deep nesting
dictionary comprehensions
module aliases
advanced OOP
```

Know what they mean, but come back to them later.

---

# 47. One-day study plan

## Hour 1 — Basics

Read and practice:

- variables
- strings
- `print()`
- f-strings
- type conversion
- input

Practice:

```python
name = input("Name: ")
age = int(input("Age: "))

print(f"{name} is {age} years old.")
```

---

## Hours 2–3 — Lists

Focus heavily on:

```python
nums[0]
nums[-1]
nums.append()
nums.pop()
nums.remove()
nums.sort()
sorted(nums)
nums[:]
nums[:3]
nums[2:]
len(nums)
```

Then practice:

```python
for x in nums:
    print(x)
```

---

## Hour 4 — Dictionaries

Memorize:

```python
d[key]
d.get(key)
d.items()
d.keys()
d.values()
```

Practice frequency counting:

```python
freq = {}

for x in nums:
    freq[x] = freq.get(x, 0) + 1
```

---

## Hours 5–6 — Conditions + loops

Practice:

```python
if
elif
else
and
or
not
in
not in
```

Then:

```python
for
range
while
break
continue
```

---

## Hours 7–8 — Functions

Practice:

```python
def function():
```

Then:

```python
def function(x):
```

Then:

```python
def function(x):
    return ...
```

Then default arguments.

---

## Hour 9 — OOP basics

Only understand:

```text
class
object
self
__init__
attribute
method
inheritance
super()
```

Don't go deep into advanced OOP today.

---

## Hour 10 — Files + exceptions + modules

Know the basic syntax:

```python
from pathlib import Path
```

```python
try:
except
else
```

```python
import module
```

---

## Final 1–2 hours — Practice

Don't reread everything.

Write small programs.

### Program 1 — Even numbers

```python
nums = [1, 2, 3, 4, 5, 6]

for x in nums:
    if x % 2 == 0:
        print(x)
```

### Program 2 — Count frequencies

```python
nums = [1, 1, 2, 2, 2, 3]

freq = {}

for x in nums:
    freq[x] = freq.get(x, 0) + 1

print(freq)
```

### Program 3 — Function

```python
def square(x):
    return x * x

print(square(5))
```

### Program 4 — List comprehension

```python
squares = [x * x for x in range(1, 6)]
print(squares)
```

### Program 5 — Dictionary loop

```python
student = {
    "name": "Richa",
    "age": 20,
    "marks": 95
}

for key, value in student.items():
    print(key, value)
```

---

# 48. Final mental model

When you see a Python problem, think in this order:

```text
1. What data do I have?
        ↓
2. Which data structure?
        ↓
3. Do I need a condition?
        ↓
4. Do I need a loop?
        ↓
5. Do I need a function?
        ↓
6. Do I need a dictionary to count/store information?
        ↓
7. Can I make it simpler?
```

Most beginner Python programs are combinations of:

```text
VARIABLES
   +
LISTS / DICTIONARIES
   +
IF
   +
LOOPS
   +
FUNCTIONS
```

Master those first.

---

# 🚀 30-minute final revision

Before your exam/interview, quickly write these from memory:

```python
# list
nums = [1, 2, 3]
nums.append(4)

# loop
for x in nums:
    print(x)

# range
for i in range(5):
    print(i)

# condition
if x > 2:
    print("yes")
else:
    print("no")

# dictionary
freq = {}
freq[x] = freq.get(x, 0) + 1

# function
def add(a, b):
    return a + b

# comprehension
squares = [x*x for x in range(5)]

# class
class Student:
    def __init__(self, name):
        self.name = name

# exception
try:
    x = int(input())
except ValueError:
    print("Invalid")
```

If you can understand and write these patterns without looking, you have covered the **core beginner Python syntax** from the uploaded cheat sheet.
