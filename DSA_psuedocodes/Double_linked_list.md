### Pseudocode for Doubly Linked List

1. **Define Doubly Linked List Node Structure**:
   - Each node has:
     - `value`: The data stored in the node.
     - `next`: Pointer to the next node in the list.
     - `prev`: Pointer to the previous node in the list.

2. **Function: Create New Node**
   - Create a new node with the given `value`.
   - Set both `next` and `prev` pointers to `NULL`.
   - Return the newly created node.

3. **Function: Insert Value at Beginning**
   - Create a new node with the given `value`.
   - Set the new node’s `next` to the current head node.
   - Set the new node’s `prev` to `NULL`.
   - If the list is not empty, update the previous head node’s `prev` pointer to the new node.
   - Update the head of the list to the new node.

4. **Function: Insert Value at End**
   - If the list is empty (head is `NULL`), set the head to a new node with the given `value`.
   - Otherwise, start at the head node and traverse to the last node (where `next` is `NULL`).
   - Create a new node with the given `value`.
   - Set the last node’s `next` pointer to the new node, and set the new node’s `prev` pointer to the last node.

5. **Function: Delete Node by Value**
   - If the list is empty (head is `NULL`), return (nothing to delete).
   - If the node to delete is the head node:
     - Update the head to the next node.
     - Set the new head node’s `prev` to `NULL`.
   - Otherwise, start from the head node and traverse the list:
     - For each node, check if `node.value == value`.
     - If found:
       - If the node has a previous node, set `node.prev.next` to `node.next`.
       - If the node has a next node, set `node.next.prev` to `node.prev`.
       - Free the node.
   - If the node is not found, return `NULL`.

6. **Function: Search Value in List**
   - Start from the head node:
     - If `node.value == value`, return the node (value found).
     - Otherwise, move to the next node (`node = node.next`).
   - If the end of the list is reached (`node == NULL`), return `NULL`.

7. **Function: Traverse the List Forward**
   - Start from the head node:
     - While the current node is not `NULL`:
       - Print the node’s `value`.
       - Move to the next node (`node = node.next`).

8. **Function: Traverse the List Backward**
   - Start from the last node:
     - While the current node is not `NULL`:
       - Print the node’s `value`.
       - Move to the previous node (`node = node.prev`).

9. **Function: Get Length of List**
   - Initialize a counter `length = 0`.
   - Start from the head node:
     - While the current node is not `NULL`:
       - Increment the counter.
       - Move to the next node.
   - Return the `length`.

10. **Main Function**
    - Initialize `head` as `NULL`.
    - For each value to be inserted at the beginning:
      - Call `Insert Value at Beginning`.
    - For each value to be inserted at the end:
      - Call `Insert Value at End`.
    - For each value to be searched:
      - Call `Search Value` and print the result.
    - For each value to be deleted:
      - Call `Delete Node by Value`.
    - Perform a forward traversal to print the list.
    - Perform a backward traversal to print the list in reverse order.

---

### Summary of the Approach
- A **Doubly Linked List** is a linear data structure where each node contains a value, a pointer to the next node, and a pointer to the previous node.
- This allows for both forward and backward traversal of the list, making operations like deletion more efficient compared to a singly linked list (since both the next and previous nodes are accessible).
- The time complexity for operations like insertion, deletion, and searching is `O(n)` in the worst case, but the list’s structure allows more flexible manipulation.
