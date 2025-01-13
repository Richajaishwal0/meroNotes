### Pseudocode for Binary Search Tree (BST) using Linked List

1. **Define Binary Search Tree (BST) Node Structure**:
   - Each node has:
     - `value`: The value stored in the node. 
     - `left`: Pointer to the left child node.
     - `right`: Pointer to the right child node.

2. **Function: Create New Node**
   - Create a new node with the given value.
   - Set `left` and `right` pointers of the node to `NULL`.
   - Return the newly created node.

3. **Function: Insert Value into BST**
   - If the tree is empty (root is `NULL`):
     - Set the new node as the root.
   - Otherwise, start from the root:
     - If `value < current.node.value`:
       - Recursively insert the value into the left subtree (`current.left`).
     - If `value > current.node.value`:
       - Recursively insert the value into the right subtree (`current.right`).
   - Return the root of the tree (for maintaining the reference).

4. **Function: Search Value in BST**
   - Start from the root node:
     - If `value == current.node.value`: Return `current.node` (found the value).
     - If `value < current.node.value`: Recursively search in the left subtree (`current.left`).
     - If `value > current.node.value`: Recursively search in the right subtree (`current.right`).
   - If the value is not found, return `NULL`.

5. **Function: Find Minimum Node**
   - Start from the root:
     - Traverse left while `current.left` is not `NULL`.
   - Return the node with the smallest value.

6. **Function: Find Maximum Node**
   - Start from the root:
     - Traverse right while `current.right` is not `NULL`.
   - Return the node with the largest value.

7. **Function: Delete Node from BST**
   - If the node to delete is a leaf (both `left` and `right` are `NULL`):
     - Simply remove the node.
   - If the node has only one child:
     - Replace the node with its child.
   - If the node has two children:
     - Find the minimum node in the right subtree (or maximum in the left subtree).
     - Replace the node’s value with the minimum value from the right subtree.
     - Recursively delete the minimum node from the right subtree.

8. **Function: In-Order Traversal**
   - If `node` is not `NULL`:
     - Traverse the left subtree (`node.left`).
     - Print the `node.value`.
     - Traverse the right subtree (`node.right`).

9. **Main Function**
   - Initialize `root` as `NULL`.
   - For each value to be inserted:
     - Call `Insert Value`.
   - For each value to be searched:
     - Call `Search Value` and print the result.
   - For each value to be deleted:
     - Call `Delete Node`.
   - Perform an in-order traversal to print the tree in sorted order.

---

### Summary of the Approach
- The Binary Search Tree (BST) is a tree-based data structure where the left child contains a value smaller than its parent, and the right child contains a value larger than its parent.
- The tree allows efficient searching, insertion, and deletion of nodes with time complexity of `O(log n)` in the best case, though this can degrade to `O(n)` if the tree is unbalanced.
- The operations are recursive, with each node having a reference to its left and right children.
