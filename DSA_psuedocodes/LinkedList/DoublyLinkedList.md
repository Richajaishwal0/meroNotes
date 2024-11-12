# Doubly Linked List

### 1) Definition
A **Doubly Linked List** is a type of linked list where each node contains:
   - **value**: The data stored in the node.
   - **next**: A pointer to the next node in the list.
   - **prev**: A pointer to the previous node in the list.

This structure allows traversal in both directions: forward and backward. It provides more flexibility than a singly linked list, as each node knows about its previous node.

### 2) Example

Consider a doubly linked list of integers:

```
Head → [10 | prev: NULL | next] ↔ [20 | prev: 10 | next] ↔ [30 | prev: 20 | next: NULL]
```

- The first node contains the value `10`, with `prev` set to `NULL` and `next` pointing to the next node.
- The second node contains the value `20`, with `prev` pointing to the first node and `next` pointing to the third node.
- The third node contains the value `30`, with `prev` pointing to the second node and `next` set to `NULL`, indicating the end of the list.

### 3) Pseudocode/Code

```plaintext
1. Define Doubly Linked List Node Structure:
   - Each node has:
     - value: The data stored in the node.
     - next: Pointer to the next node in the list.
     - prev: Pointer to the previous node in the list.

2. Function: Create New Node
   - Create a new node with the given value.
   - Set next and prev to NULL.
   - Return the newly created node.

3. Function: Insert Value at Beginning
   - Create a new node with the given value.
   - Set the new node’s next to the current head node.
   - Set the new node’s prev to NULL.
   - If the list is not empty, update the previous head node’s prev pointer to the new node.
   - Update the head of the list to the new node.

4. Function: Insert Value at End
   - If the list is empty (head is NULL), set the head to a new node with the given value.
   - Otherwise, traverse to the last node (where next is NULL).
   - Create a new node with the given value.
   - Set the last node’s next pointer to the new node, and set the new node’s prev pointer to the last node.

5. Function: Delete Node by Value
   - If the list is empty (head is NULL), return (nothing to delete).
   - If the node to delete is the head node:
     - Update the head to the next node.
     - Set the new head node’s prev to NULL.
   - Otherwise, traverse the list:
     - If node.value == value:
       - If the node has a previous node, set node.prev.next to node.next.
       - If the node has a next node, set node.next.prev to node.prev.
       - Free the node.

6. Function: Search Value in List
   - Start from the head node:
     - If node.value == value, return the node (value found).
     - Otherwise, move to the next node.
   - If the end of the list is reached (node == NULL), return NULL.

7. Function: Traverse the List Forward
   - Start from the head node:
     - While the current node is not NULL:
       - Print the node’s value.
       - Move to the next node.

8. Function: Traverse the List Backward
   - Start from the last node:
     - While the current node is not NULL:
       - Print the node’s value.
       - Move to the previous node.

9. Function: Get Length of List
   - Initialize counter length = 0.
   - Start from the head node:
     - While the current node is not NULL:
       - Increment counter.
       - Move to the next node.
   - Return length.
```

### 4) Time Complexity

- **Insertion at the Beginning**: O(1)
- **Insertion at the End**: O(n), where n is the number of nodes.
- **Deletion by Value**: O(n), since it may require traversing the list.
- **Search for Value**: O(n), as each node must be checked.
- **Traversal Forward/Backward**: O(n), as every node needs to be visited.

### 5) Sample Input and Output

#### Sample Input 1:
```
Insert 10 at the beginning.
Insert 20 at the end.
Insert 30 at the end.
Delete 20.
Search for 10.
Traverse the list forward.
Traverse the list backward.
```

#### Sample Output 1:
```
List after Insertions: Head → [10 | prev: NULL | next] ↔ [20 | prev: 10 | next] ↔ [30 | prev: 20 | next: NULL]
List after Deletion: Head → [10 | prev: NULL | next] ↔ [30 | prev: 10 | next: NULL]
Search Result for 10: Found
Forward Traversal: 10 → 30
Backward Traversal: 30 → 10
```

#### Sample Input 2:
```
Insert 5 at the beginning.
Insert 15 at the end.
Delete 5.
Search for 15.
Traverse the list forward.
Traverse the list backward.
```

#### Sample Output 2:
```
List after Insertions: Head → [5 | prev: NULL | next] ↔ [15 | prev: 5 | next: NULL]
List after Deletion: Head → [15 | prev: NULL | next: NULL]
Search Result for 15: Found
Forward Traversal: 15
Backward Traversal: 15
``` 
