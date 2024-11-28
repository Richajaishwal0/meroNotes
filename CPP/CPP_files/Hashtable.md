# HashMap in C++

## Introduction
A **HashMap** is an associative container in C++ that stores key-value pairs. It is implemented using the `unordered_map` in the STL (Standard Template Library). HashMaps provide **O(1)** average time complexity for insertion, deletion, and lookup operations due to their hash-based implementation.

---

## Key Features
- **Key-Value Pair Storage:** Each key is unique and mapped to a specific value.
- **Hashing:** Internally uses a hash function to compute an index for storing elements.
- **Non-Sorted Order:** The elements are not stored in any particular order.
- **Collision Handling:** Handles hash collisions using chaining or open addressing.

---

## Common Operations

| Operation       | Method                         | Description                                 |
|------------------|--------------------------------|---------------------------------------------|
| **Insert**       | `mp[key] = value;` or `mp.insert({key, value});` | Adds a key-value pair to the map.          |
| **Access**       | `mp[key]`                     | Retrieves the value associated with a key. |
| **Erase**        | `mp.erase(key);`              | Removes the key-value pair for a given key.|
| **Search**       | `mp.find(key)`                | Returns an iterator to the key if found; otherwise, `mp.end()`. |
| **Size**         | `mp.size()`                   | Returns the number of elements.            |
| **Clear**        | `mp.clear()`                  | Removes all elements.                      |
| **Check Existence** | `mp.count(key)`            | Returns `1` if the key exists, otherwise `0`. |

---

## Code Example

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> mp;

    // Insert
    mp["apple"] = 5;
    mp.insert({"banana", 10});

    // Access
    cout << "Apple count: " << mp["apple"] << endl;

    // Search
    if (mp.find("banana") != mp.end()) {
        cout << "Banana found." << endl;
    }

    // Erase
    mp.erase("apple");

    // Check size
    cout << "Size: " << mp.size() << endl;

    return 0;
}
```

---

## Applications in DSA
1. **Frequency Counting:** Track the occurrences of elements in an array or string.
2. **Anagrams:** Group or check for anagrams using character frequency maps.
3. **Two-Sum Problem:** Store the indices of numbers for quick lookup.
4. **Subarray Problems:** Use HashMaps to store cumulative sums or prefix sums.
5. **Graph Algorithms:** Store adjacency lists or track visited nodes.
6. **Caching:** Implement LRU (Least Recently Used) or other cache mechanisms.

---

## Notes
- **Complexity:**  
  - Average Case: **O(1)** for insert, delete, search.  
  - Worst Case: **O(n)** (rare, when hash collisions are frequent).
- Use **`map`** instead of `unordered_map` if sorted order is required (logarithmic time complexity).
- Always include **`<unordered_map>`** to use HashMaps.
