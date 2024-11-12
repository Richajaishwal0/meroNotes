# Singly Linked List

### 1) Definition
A **Singly Linked List** is a linear data structure where each element, called a **node**, consists of two parts:
   - **Value/Data**: Holds the data of the node.
   - **Next Pointer**: A reference to the next node in the sequence.

In a singly linked list, nodes are linked sequentially, and each node points to the next node in the list. The last node's next pointer is set to `NULL`, indicating the end of the list.

### 2) Example

Consider a linked list of integers:

```
Head → [10 | next] → [20 | next] → [30 | next] → NULL
```

- The first node contains the value `10` and points to the next node.
- The second node contains the value `20` and points to the next node.
- The third node contains the value `30` and points to `NULL`, indicating the end of the list.

### 3) Pseudocode/Code

```plaintext
1. Define Linked List Node Structure:
   - Each node has:
     - value: The data stored in the node.
     - next: Pointer to the next node in the list.

2. Function: Create New Node
   - Create a new node with the given value.
   - Set next to NULL.
   - Return the newly created node.

3. Function: Insert Value at Beginning
   - Create a new node with the given value.
   - Set the new node’s next to the current head node.
   - Update the head of the list to the new node.

4. Function: Insert Value at End
   - If the list is empty (head is NULL), set the head to a new node with the given value.
   - Otherwise, traverse the list to find the last node (where next is NULL).
   - Set the last node’s next to the new node with the given value.

5. Function: Delete Node by Value
   - If the list is empty (head is NULL), return (nothing to delete).
   - If the head node’s value matches the given value, update the head to the next node.
   - Otherwise, traverse the list to find the node with the matching value and remove it.

6. Function: Search Value in List
   - Traverse the list and return the node if the value is found.
   - If not found, return NULL.

7. Function: Traverse the List
   - Traverse the list and print the value of each node.

8. Function: Get Length of List
   - Traverse the list and count the number of nodes.
   - Return the count.
```

### 4) Time Complexity

- **Insertion at the Beginning**: O(1)
- **Insertion at the End**: O(n), where n is the number of nodes in the list.
- **Deletion by Value**: O(n), since it may require traversing the entire list.
- **Search for Value**: O(n), as each node must be checked in the worst case.
- **Traversal**: O(n), as every node needs to be visited.

### 5) Sample Input and Output

#### Sample Input 1:
```
Insert 10 at the beginning.
Insert 20 at the end.
Insert 30 at the end.
Delete 20.
Search for 10.
Traverse the list.
```

#### Sample Output 1:
```
List after Insertions: Head → [10 | next] → [20 | next] → [30 | next] → NULL
List after Deletion: Head → [10 | next] → [30 | next] → NULL
Search Result for 10: Found
Traversal Output: 10 → 30
```

#### Sample Input 2:
```
Insert 5 at the beginning.
Insert 15 at the end.
Delete 5.
Search for 15.
Traverse the list.
```

#### Sample Output 2:
```
List after Insertions: Head → [5 | next] → [15 | next] → NULL
List after Deletion: Head → [15 | next] → NULL
Search Result for 15: Found
Traversal Output: 15
``` 
