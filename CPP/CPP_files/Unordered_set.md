# Unordered Set in C++

An **unordered set** is a container in C++ that stores unique elements in no particular order. It is part of the `<unordered_set>` library and is implemented using **hash tables**, which provide fast insertion, deletion, and search operations with an average time complexity of **O(1)**.

## Features
1. **Unique Elements**: No duplicates are allowed.
2. **Unordered**: Elements are not stored in a specific order.
3. **Hash Table**: Uses a hash function to map elements for fast operations.
4. **Fast Operations**: Average complexity of O(1) for insertion, deletion, and search.
5. **Key-Only Storage**: Unlike maps, only keys are stored, not key-value pairs.

## Syntax
```cpp
#include <unordered_set>
std::unordered_set<Type> setName;
```

## Common Operations
| Operation         | Description                                | Example                                     |
|--------------------|--------------------------------------------|---------------------------------------------|
| `insert(val)`      | Adds an element `val` to the set.          | `mySet.insert(10);`                         |
| `erase(val)`       | Removes the element `val` from the set.    | `mySet.erase(10);`                          |
| `find(val)`        | Searches for `val` and returns an iterator.| `if (mySet.find(10) != mySet.end()) {}`     |
| `count(val)`       | Returns 1 if `val` exists, 0 otherwise.    | `if (mySet.count(10)) {}`                   |
| `size()`           | Returns the number of elements.           | `std::cout << mySet.size();`                |
| `clear()`          | Removes all elements from the set.         | `mySet.clear();`                            |

## Example Code
```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3, 4};

    // Insert an element
    mySet.insert(5);

    // Check if an element exists
    if (mySet.count(3)) {
        std::cout << "3 is present\n";
    }

    // Remove an element
    mySet.erase(2);

    // Display elements
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }

    return 0;
}
```

## Advantages
- **Fast operations** due to hashing.
- **Automatic handling of uniqueness** of elements.

## Limitations
- Cannot maintain order of elements.
- Hash collisions can degrade performance to O(n) in the worst case.
- Requires a valid hash function for custom data types.

## Use Cases
- Storing unique items where order does not matter.
- Efficient membership testing.
- Removing duplicate elements from a collection.
```
