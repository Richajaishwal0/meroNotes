# B-Tree-Based Queue System

## Definition
A B-Tree-Based Queue System is a data structure that uses a B-Tree to manage a dynamic queue of elements (e.g., customer numbers) while maintaining sorted order. The B-Tree allows for efficient insertion, deletion, and in-order traversal, ensuring that elements are always sorted and accessible in logarithmic time.

## Example
Imagine a queue of customer numbers being processed in sorted order:
- Initial insertions: 5, 3, 7, 1, 6
- Expected sorted output after insertion: 1, 3, 5, 6, 7
Using the B-Tree structure, we insert elements, ensuring they are organized efficiently, and perform an in-order traversal to retrieve them in sorted order.

## Pseudocode

1. **Define B-Tree Node Structure**  
   ```plaintext
   Node:
      keys[]       // Array to store keys in the node
      children[]   // Array of child pointers
      isLeaf       // Boolean indicating if the node is a leaf
      numKeys      // Number of keys currently in the node
   ```

2. **Split Child Function**  
   - **Input**: `parent` (the node whose child is full), `index` (location of child to split), `child` (the full child node).
   - **Process**:
     - Create `newChild` for the last `t-1` keys of `child`.
     - If `child` is not a leaf, move its last `t` children to `newChild`.
     - Insert `newChild` into `parent.children[]` at `index + 1`.
     - Move `child`'s middle key to `parent.keys[]` at `index`.
     - Update `numKeys` for `parent` and `child`.

3. **Insert into Non-Full Node Function**  
   - **Input**: `node` (node to insert key), `key` (key to insert).
   - **Process**:
     - If `node` is a leaf:
       - Insert `key` in `node.keys[]` in sorted order.
       - Increment `node.numKeys`.
     - If not a leaf:
       - Locate the child for `key` insertion.
       - If child is full, call `splitChild()`.
       - Recursively call `insert into non-full node` on the child.

4. **Insert Key Function**  
   - **Input**: `key` (key to insert).
   - **Process**:
     - If `root` is full:
       - Create `newRoot`, set `root` as its child.
       - Call `splitChild()` on `newRoot`.
       - Insert `key` into `newRoot`.
       - Update `root`.
     - If not full, call `insert into non-full node` on `root`.

5. **Delete Key Function**  
   - **Input**: `key` (key to delete).
   - **Process**:
     - If `key` is in a leaf, remove it.
     - If in an internal node:
       - Replace with predecessor or successor if children have `t` keys.
       - Otherwise, merge nodes and delete from merged node.
     - If `key` not found, descend with `t` keys in each child before moving down.

6. **In-Order Traversal Function**  
   - **Input**: `node` (node to traverse).
   - **Process**:
     - Traverse `node.children[0]`.
     - For each key in `node.keys[]`:
       - Print the key.
       - Traverse each corresponding child in `node.children[]`.

7. **Main Function**  
   - **Process**:
     - Initialize `root` as an empty node.
     - For each `customerNumber` in input:
       - Call `Insert Key` with `customerNumber`.
     - Call `In-Order Traversal` on `root` to output sorted order.

## Time Complexity
- **Insertion**: \( O(\log n) \) per insertion due to splitting and balancing.
- **Deletion**: \( O(\log n) \) per deletion.
- **Traversal**: \( O(n) \), since each node is visited in order.

## Sample Input and Output
- **Input Sequence**: `5, 3, 7, 1, 6`
- **Sorted Output**: `1, 3, 5, 6, 7`
