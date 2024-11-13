# Skip List

## Definition
A Skip List is a probabilistic data structure that maintains elements in sorted order and allows for efficient search, insertion, and deletion operations. It achieves this by utilizing multiple levels of linked lists, where each level allows elements to "skip" over parts of the list for faster access. The height (or level) of each node is determined randomly, resulting in a balanced structure similar to balanced trees.

## Example
Consider inserting and searching for numbers in a skip list:
- **Insertions**: 5, 3, 9, 2
- After inserting, the skip list arranges nodes such that higher levels allow for quicker access.
- **Search**: Looking for number 3, the skip list allows efficient traversal to find 3 without traversing every node at the base level.

## Pseudocode

1. **Define Skip List Node Structure**
   ```plaintext
   Node:
      value          // The value stored in the node
      forward[]      // Array of pointers to nodes at each level
      level          // The highest level of this node
   ```

2. **Create Skip List Function**
   - **Process**:
     - Initialize `skipList` with a header node (`value = NULL`, `level = 0`).
     - Set `maxLevel` and probability factor for generating new levels.

3. **Random Level Generator Function**
   - **Process**:
     - Initialize `level = 0`.
     - While a random probability is less than a given threshold, increment `level`.
     - Return `level`.

4. **Insert Value Function**
   - **Input**: `value` (value to insert).
   - **Process**:
     - Initialize `update[]` to store nodes needing pointer adjustments.
     - Starting at `maxLevel`, move forward at each level while the next node’s value is less than `value`.
     - Store current pointers in `update[]`.
     - Generate a random level for the new node.
     - Insert the new node, adjusting `forward[]` pointers in `update[]` for each level.
     - If new node’s level exceeds `maxLevel`, update `maxLevel`.

5. **Search Value Function**
   - **Input**: `value` (value to search).
   - **Process**:
     - Starting at `maxLevel`, traverse each level moving forward until the next node’s value is no longer less than `value`.
     - At the base level (level 0), check if the target node’s value matches `value`.
     - Return the node if found; otherwise, return `NULL`.

6. **Delete Value Function**
   - **Input**: `value` (value to delete).
   - **Process**:
     - Initialize `update[]` to store nodes needing pointer adjustments.
     - Starting at `maxLevel`, traverse each level moving forward until the next node’s value is no longer less than `value`.
     - Store pointers in `update[]`.
     - If node with `value` is found, adjust `forward[]` pointers in `update[]` to remove the node.
     - Update `maxLevel` if needed.

7. **Traverse Skip List Function**
   - **Process**:
     - Starting from the header node, move through the first level.
     - For each node, print its `value`.

8. **Main Function**
   - **Process**:
     - Initialize `skipList`.
     - For each value to be inserted, call `Insert Value`.
     - For each value to be searched, call `Search Value` and print the result.
     - For each value to be deleted, call `Delete Value`.

## Summary of the Approach
- The Skip List provides an efficient alternative to balanced trees with logarithmic time complexity for `Insert`, `Search`, and `Delete` operations.
- Nodes are assigned levels randomly, which allows for faster traversal across levels, reducing the time spent on operations.
- The Skip List's probabilistic nature makes it adaptable and easy to maintain while achieving a balanced structure.

## Time Complexity
- **Insertion**: \( O(\log n) \) due to level traversal and pointer adjustments.
- **Search**: \( O(\log n) \) because levels enable faster access.
- **Deletion**: \( O(\log n) \) due to traversal across levels.

## Sample Input and Output
- **Input**: Insert `5, 3, 9, 2`; Search `3`; Delete `9`.
- **Output**:
  - **After Insertions**: `2, 3, 5, 9`
  - **Search for 3**: Found
  - **After Deletion of 9**: `2, 3, 5`
