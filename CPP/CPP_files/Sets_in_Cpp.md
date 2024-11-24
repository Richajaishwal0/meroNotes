
# C++ Set and Set Operations

## Set in C++
A **set** in C++ is a part of the Standard Template Library (STL) and is defined in the `<set>` header file. It is an associative container that stores unique elements in sorted order. Sets are useful when you want to maintain a collection of unique elements and perform various set operations efficiently.

### Key Features of `set`:
- **Unique Elements**: A set only stores unique elements.
- **Ordered Elements**: Elements are stored in ascending order by default.
- **Efficient Operations**: Insertion, deletion, and search operations take O(log n) time.
- **Iterators**: Sets provide bidirectional iterators to traverse the set.

### Basic Syntax:
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet; // Declare a set of integers

    // Insert elements
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    // Iterate and print the set
    for (int elem : mySet) {
        std::cout << elem << " ";
    }

    return 0;
}
```

---

## Common Operations on `set`

| Operation                              | Description                                   | Example                                           |
|----------------------------------------|-----------------------------------------------|---------------------------------------------------|
| `insert(value)`                        | Inserts an element into the set.              | `mySet.insert(10);`                              |
| `erase(value)`                         | Removes a specific element from the set.      | `mySet.erase(20);`                               |
| `find(value)`                          | Returns an iterator to the element or `end`.  | `if (mySet.find(10) != mySet.end()) { ... }`     |
| `size()`                               | Returns the number of elements in the set.    | `mySet.size();`                                  |
| `empty()`                              | Checks if the set is empty.                   | `if (mySet.empty()) { ... }`                     |
| `clear()`                              | Removes all elements from the set.            | `mySet.clear();`                                 |
| `count(value)`                         | Returns 1 if the element exists, otherwise 0. | `if (mySet.count(10)) { ... }`                   |
| `lower_bound(value)`                   | Returns iterator to the first element ≥ value.| `mySet.lower_bound(15);`                        |
| `upper_bound(value)`                   | Returns iterator to the first element > value.| `mySet.upper_bound(15);`                        |

---

## Set Operations

### 1. Union of Sets
The **union** of two sets contains all elements from both sets, without duplicates.
```cpp
std::set<int> set1 = {1, 2, 3};
std::set<int> set2 = {3, 4, 5};
std::set<int> unionSet = set1;
unionSet.insert(set2.begin(), set2.end());
```

**Output**:
```
1 2 3 4 5
```

---

### 2. Intersection of Sets
The **intersection** of two sets contains only the elements that are present in both sets.
```cpp
std::set<int> set1 = {1, 2, 3};
std::set<int> set2 = {2, 3, 4};
std::set<int> intersectionSet;
std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersectionSet, intersectionSet.begin()));
```

**Output**:
```
2 3
```

---

### 3. Difference of Sets
The **difference** of two sets contains the elements that are in the first set but not in the second.
```cpp
std::set<int> set1 = {1, 2, 3};
std::set<int> set2 = {2, 3, 4};
std::set<int> differenceSet;
std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(differenceSet, differenceSet.begin()));
```

**Output**:
```
1
```

---

### 4. Symmetric Difference of Sets
The **symmetric difference** contains elements that are in either of the sets but not in their intersection.
```cpp
std::set<int> set1 = {1, 2, 3};
std::set<int> set2 = {3, 4, 5};
std::set<int> symDifferenceSet;
std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(symDifferenceSet, symDifferenceSet.begin()));
```

**Output**:
```
1 2 4 5
```

---

## Multiset
If you need to store duplicate elements, you can use a `multiset` instead of a `set`. The operations are the same as `set`, except it allows duplicate values.
```cpp
std::multiset<int> multiSet;
multiSet.insert(10);
multiSet.insert(10); // Duplicates are allowed
```

**Output**:
```
10 10 20
```

---

## Conclusion
- Use `set` for storing unique, ordered elements.
- Use algorithms like `set_union`, `set_intersection`, etc., from `<algorithm>` for performing set operations.
- Use `multiset` if duplicate elements are required.
