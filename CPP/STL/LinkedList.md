Here’s the table summarizing STL functions for different types of linked lists, along with their declaration methods.

| **Operation**          | **Singly Linked List (Simulated)**      | **Doubly Linked List (`std::list`)**                | **Circular Linked List (Simulated)**                     |
|-------------------------|-----------------------------------------|-----------------------------------------------------|----------------------------------------------------------|
| **Declaration**         | `std::list<int> lst;`                  | `std::list<int> lst;`                               | `std::list<int> lst;`                                    |
| **Insertion**           | `lst.push_back(value);`                | `lst.push_front(value);`<br>`lst.push_back(value);`<br>`lst.insert(it, value);` | `lst.push_back(value);` + manual linking for circularity |
| **Deletion**            | `lst.pop_back();`                      | `lst.pop_front();`<br>`lst.pop_back();`<br>`lst.erase(it);` | `lst.pop_back();` + manual unlinking for circularity    |
| **Traversal**           | `for (auto x : lst)`                   | `for (auto x : lst)` or iterators                  | `for (auto it = lst.begin(); it != lst.end(); ++it)`     |
| **Search**              | `std::find(lst.begin(), lst.end(), value);` | `std::find(lst.begin(), lst.end(), value);`         | `std::find(lst.begin(), lst.end(), value);`              |
| **Reverse**             | -                                      | `lst.reverse();`                                    | Simulate manually by iterating and swapping              |
| **Sort**                | -                                      | `lst.sort();`                                       | Simulate manually                                        |
| **Unique (Remove Duplicates)** | -                              | `lst.unique();`                                     | Simulate manually                                        |
| **Merge**               | -                                      | `lst1.merge(lst2);`                                 | Simulate manually                                        |
| **Splice**              | -                                      | `lst.splice(it, lst2);`                             | Not applicable directly                                  |
| **Size**                | `lst.size();`                          | `lst.size();`                                       | `lst.size();`                                            |
| **Check Empty**         | `lst.empty();`                         | `lst.empty();`                                      | `lst.empty();`                                           |
| **Front Element**       | `lst.front();`                         | `lst.front();`                                      | `lst.front();`                                           |
| **Back Element**        | `lst.back();`                          | `lst.back();`                                       | `lst.back();`                                            |

---

### **Ways to Declare Lists**
1. **Singly Linked List**  
   Use `std::list<int>` but avoid bidirectional operations.  
   ```cpp
   std::list<int> lst;
   ```

2. **Doubly Linked List**  
   Fully supported by STL `list`.  
   ```cpp
   std::list<int> lst; // Declares an empty doubly linked list
   std::list<int> lst = {1, 2, 3, 4}; // Initializes with values
   ```

3. **Circular Linked List**  
   Use `std::list<int>` and manually link the last node to the first:  
   ```cpp
   std::list<int> lst = {1, 2, 3};
   auto it = lst.end();
   --it; // Point to the last element
   // Custom circular linkage (requires pointer manipulation)
   ```

---

Let me know if you need examples or more details on specific operations!
