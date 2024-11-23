### Pseudocode for Binary Heap (Min-Heap)

A **Min-Heap** is a binary heap where the value of each node is less than or equal to the values of its children. For a **Max-Heap**, the opposite is true, where the value of each node is greater than or equal to its children.

---

### 1. **Binary Heap Structure**
   - Each node in the heap has:
     - `value`: The value of the node.
     - `left`: Pointer to the left child.
     - `right`: Pointer to the right child.
     - `parent`: Pointer to the parent node.

### 2. **Function: Insert (heap, value)**
   - **Insert value into the heap**:
     - Add `value` to the end of the heap (i.e., to the next available position in the tree).
     - **Heapify up**: 
       - While the inserted node’s value is less than its parent’s value:
         - Swap the node with its parent.
   - Return the updated heap.

### 3. **Function: ExtractMin (heap)**
   - **Remove and return the minimum value** (the root of the heap):
     - Swap the root with the last element (the element at the end of the heap).
     - Remove the last element from the heap (this is the minimum value).
     - **Heapify down**:
       - Starting from the root, repeatedly swap the node with its smallest child (among the left and right children).
       - Continue the process until the heap property is restored.
   - Return the removed minimum value.

### 4. **Function: Heapify (heap, index)**
   - **Heapify down**:
     - Compare the node at `index` with its children:
       - If the node is larger than either of its children:
         - Swap it with the smallest child.
         - Continue heapifying down from the swapped child.
   - This function is used in both the insert and extract operations to restore the heap property.

### 5. **Function: BuildHeap (array)**
   - **Create a heap from an unsorted array**:
     - For each node starting from the last internal node (i.e., from `n//2 - 1` to `0`), call `Heapify` on each node.
     - This ensures the heap property is satisfied for the entire array.
   - Return the resulting heap.

---

### Example of the Binary Heap Operations:

1. **Insert Operation Example**:
   - Given heap: `[2, 4, 5]`
   - Insert `1`:
     - Add `1` to the end: `[2, 4, 5, 1]`
     - Heapify up: `1` is smaller than `2`, so swap: `[1, 4, 5, 2]`
     - Heapify up: `1` is smaller than `4`, so swap: `[1, 2, 5, 4]`
   - Resulting heap: `[1, 2, 5, 4]`

2. **ExtractMin Operation Example**:
   - Given heap: `[1, 2, 5, 4]`
   - Remove the minimum (`1`):
     - Swap root with the last element: `[4, 2, 5]`
     - Remove the last element (`1`), resulting in `[4, 2, 5]`.
     - Heapify down:
       - `4` is larger than `2`, so swap: `[2, 4, 5]`
   - Resulting heap: `[2, 4, 5]`
   - Return the extracted minimum value: `1`.

---

### Summary of Binary Heap Operations
- **Insert**: Add an element and restore heap property by "heapifying up."
- **ExtractMin**: Remove the minimum element, swap the root with the last element, and restore the heap property by "heapifying down."
- **Heapify**: Ensure that a node maintains the heap property with respect to its children.
- **BuildHeap**: Create a valid heap from an unsorted array by applying heapify on all nodes.


