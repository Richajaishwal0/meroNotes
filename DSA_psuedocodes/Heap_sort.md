### **Pseudocode for Heap Sort**

1. **Define Heapify Function**:
   - The `Heapify` function is responsible for maintaining the heap property (max heap or min heap).
   - It checks whether the left or right child of a node is larger (or smaller in the case of a min heap) than the current node. If so, it swaps the nodes and recursively heapifies the affected subtree.

2. **Define BuildHeap Function**:
   - The `BuildHeap` function builds the heap by calling the `Heapify` function starting from the last non-leaf node down to the root.

3. **Define Heap Sort Function**:
   - The `HeapSort` function sorts the array by first building a max heap and then repeatedly swapping the root element (the maximum value) with the last element of the heap, reducing the heap size and calling `Heapify` on the root node to restore the heap property.

---

### **Heap Sort Algorithm Steps**

```plaintext
Function Heapify(arr, n, i)
    left = 2 * i + 1                // Left child index
    right = 2 * i + 2               // Right child index
    largest = i                     // Assume current node is the largest

    If left < n and arr[left] > arr[largest]      // If left child is larger than current largest
        largest = left

    If right < n and arr[right] > arr[largest]    // If right child is larger than current largest
        largest = right

    If largest != i
        Swap arr[i] with arr[largest]             // Swap current node with largest
        Heapify(arr, n, largest)                  // Recursively heapify the affected subtree

Function BuildHeap(arr)
    n = length(arr)
    // Start heapifying from the last non-leaf node
    For i = n // 2 - 1 down to 0
        Heapify(arr, n, i)    // Call Heapify for each node

Function HeapSort(arr)
    n = length(arr)
    
    // Build a max heap
    BuildHeap(arr)

    // Extract elements from the heap one by one
    For i = n - 1 down to 1
        Swap arr[0] with arr[i]              // Swap root (max element) with last element
        Heapify(arr, i, 0)                   // Heapify the reduced heap
```

---

### **Main Function**

```plaintext
Function Main()
    arr = [38, 27, 43, 3, 9, 82, 10]  // Example array to sort
    HeapSort(arr)                      // Call HeapSort to sort the array
    Print arr                           // Output the sorted array
```

---

### **Explanation of the Process**

1. **Initial Array**: `[38, 27, 43, 3, 9, 82, 10]`
2. **Step 1**: **Build the Max Heap**:
   - The heap is built starting from the last non-leaf node.
   - After building the heap, the root element will be the maximum.
3. **Step 2**: **Heap Sort**:
   - The root (maximum element) is swapped with the last element of the heap.
   - After the swap, the heap size is reduced by one.
   - The `Heapify` function is called on the root to restore the heap property.
   - This process is repeated until the entire array is sorted.

4. **Final Sorted Array**: `[3, 9, 10, 27, 38, 43, 82]`

---

### **Time Complexity**:
- **Best, Average, and Worst Case**: \( O(n \log n) \)  
  (This is because we perform heapify \( O(\log n) \) for each element \( n \), and building the heap also takes \( O(n) \)).

### **Space Complexity**:
- **O(1)** since Heap Sort is an in-place sorting algorithm that does not require any additional space besides the input array.
