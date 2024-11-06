### Pseudocode for the AVL Tree-Based Queue System

1. **Define AVL Node Structure**:
   - Each node has:
     - `customerNumber`: The number assigned to the customer.
     - `left`: Pointer to the left child.
     - `right`: Pointer to the right child.
     - `height`: Height of the node.

2. **Function: Get Height**
   - If node is `NULL`, return 0.
   - Otherwise, return `node.height`.

3. **Function: Calculate Balance Factor**
   - If node is `NULL`, return 0.
   - Return `height(node.left) - height(node.right)`.

4. **Function: Right Rotate (for balancing)**
   - `x = node.left`
   - `T2 = x.right`
   - Perform rotation:
     - `x.right = node`
     - `node.left = T2`
   - Update heights of `node` and `x`.
   - Return `x` (new root after rotation).

5. **Function: Left Rotate (for balancing)**
   - `y = node.right`
   - `T2 = y.left`
   - Perform rotation:
     - `y.left = node`
     - `node.right = T2`
   - Update heights of `node` and `y`.
   - Return `y` (new root after rotation).

6. **Function: Insert Customer Number**
   - If `node` is `NULL`, create a new node with `customerNumber`.
   - If `customerNumber < node.customerNumber`, insert into `node.left`.
   - If `customerNumber > node.customerNumber`, insert into `node.right`.
   - Update `node.height`.
   - Calculate `balance` using the balance factor.
   - **Balancing Cases**:
     - If `balance > 1` and `customerNumber < node.left.customerNumber`: Perform Right Rotate.
     - If `balance < -1` and `customerNumber > node.right.customerNumber`: Perform Left Rotate.
     - If `balance > 1` and `customerNumber > node.left.customerNumber`: Perform Left-Right Rotate.
     - If `balance < -1` and `customerNumber < node.right.customerNumber`: Perform Right-Left Rotate.
   - Return `node`.

7. **Function: In-Order Traversal**
   - If `node` is not `NULL`:
     - Traverse `node.left`.
     - Print `node.customerNumber`.
     - Traverse `node.right`.

8. **Main Function**
   - Initialize `root` as `NULL`.
   - For each `customerNumber` in the input sequence:
     - `root = InsertCustomerNumber(root, customerNumber)`
   - Perform an in-order traversal to print the numbers in sorted order.

---

### Summary of the Approach
- The AVL tree automatically rebalances itself after each insertion, maintaining a balanced structure.
- The customer numbers are kept in order, ensuring efficient access and minimal depth.
- Using an in-order traversal, the customer numbers can be retrieved in the correct sequence for processing.

This approach meets the requirements for a dynamic and efficient queue management system using an AVL tree.
