# Circular Linkedlist
### **1) Definition**:
A **Circular Linked List** is a variation of a linked list where the last node points back to the first node, forming a continuous circular structure. This allows for endless traversal and manipulation of the list, as the last node does not point to `NULL`, but to the head node.

---

### **2) Example**:

Consider a Circular Linked List with the following values: **10, 20, 30, 40**

- The nodes are connected as follows:
  - `Node1(value=10)` → `Node2(value=20)` → `Node3(value=30)` → `Node4(value=40)` → back to `Node1` (head).

This creates a loop in the list, where traversal can continue indefinitely starting from any node.

---

### **3) Pseudocode/Code**:

```plaintext
1. Define Circular Linked List Node Structure:
   Node Structure:
      - value: Stores data in the node.
      - next: Points to the next node in the list.

2. Function: Create New Node
   - Create a new node with the given value.
   - Set next to NULL.
   - Return the newly created node.

3. Function: Insert Value at Beginning
   - Create a new node with the given value.
   - If the list is empty (head is NULL):
       - Set new node’s next to itself (only node in the list).
       - Set head to the new node.
   - Otherwise:
       - Set new node’s next to the head node.
       - Traverse to the last node (where next points to head).
       - Set last node’s next to the new node.
       - Set head to the new node.

4. Function: Insert Value at End
   - If the list is empty (head is NULL), call Insert Value at Beginning.
   - Otherwise, traverse to the last node (where next points to head).
   - Create a new node with the given value.
   - Set last node’s next to new node.
   - Set new node’s next to head node.

5. Function: Delete Node by Value
   - If the list is empty (head is NULL), return (nothing to delete).
   - If head node’s value matches the given value:
       - Traverse to the last node (where next points to head).
       - Set head to the next node.
       - Set last node’s next to the new head.
   - Otherwise, start from the head node and traverse the list:
       - For each node, check if node.next.value == value.
       - If found:
           - Set node.next to node.next.next (removes the node).

6. Function: Search Value in List
   - Start from the head node:
       - If node.value == value, return the node (value found).
       - Move to the next node (node = node.next).
       - Continue until you loop back to the head node.
   - If the list is traversed completely and value is not found, return NULL.

7. Function: Traverse the List
   - Start from the head node:
       - While the current node is not equal to the head node:
           - Print the node’s value.
           - Move to the next node (node = node.next).
       - Once the traversal reaches the head node again, stop.

8. Function: Get Length of List
   - Initialize counter length = 0.
   - Start from the head node:
       - While the current node is not equal to the head node:
           - Increment the counter.
           - Move to the next node.
   - Return the length.

---

### **4) Time Complexity**:

- **Insert at Beginning**: `O(1)` - Directly adds the new node at the head, updating the necessary pointers.
- **Insert at End**: `O(n)` - Must traverse the entire list to find the last node and then link the new node.
- **Delete by Value**: `O(n)` - May require traversing the entire list to find and delete the node.
- **Search**: `O(n)` - May require checking each node in the list, especially in a non-sorted list.
- **Traverse**: `O(n)` - Traversing the entire list once.
- **Get Length**: `O(n)` - Needs to traverse the list to count the nodes.

---

### **5) Input**:

- For insertion: A value (e.g., 10, 20, 30) to insert into the list.
- For deletion: A value (e.g., 20) to delete from the list.
- For searching: A value (e.g., 30) to search within the list.

---

### **6) Output**:

- After **insertion**: The list reflects the new element added at the desired position (beginning or end).
- After **deletion**: The list reflects the removal of the specified element.
- After **search**: The output is either the node with the searched value or `NULL` if the value is not found.
- **Traversal**: Prints the entire list in a circular fashion, and stops when it loops back to the head node.
- **Length**: Returns the total number of nodes in the list.

---

### **Example Run**:

#### Input:
```plaintext
Insert at Beginning: 10
Insert at Beginning: 20
Insert at End: 30
Search: 20
Delete: 10
```

#### Output:
```plaintext
List after insertion: 20 → 10 → 30 → 20 (Circular)
Found value 20
List after deletion: 20 → 30 → 20 (Circular)
```
