### **Pseudocode for Merge Sort with Main Function**

1. **Define MergeSort Function**:
   - If the array has more than one element:
     - Divide the array into two halves: `left` and `right`.
     - Recursively sort both halves by calling `MergeSort` on `left` and `right`.
     - Merge the two sorted halves using the `Merge` function.
   - Return the sorted array.

2. **Define Merge Function**:
   - Create an empty array `result` to store the merged elements.
   - While there are elements in both `left` and `right`:
     - Compare the first element of `left` and `right`:
       - If `left[0] <= right[0]`, append `left[0]` to `result` and remove it from `left`.
       - Else, append `right[0]` to `result` and remove it from `right`.
   - Once one of the arrays is empty, append the remaining elements of the other array (if any) to `result`.
   - Return the merged `result`.

---

### **Merge Sort Pseudocode Steps**

```plaintext
Function MergeSort(arr)
    If length(arr) > 1:
        Mid = length(arr) // 2                // Find the midpoint of the array
        Left = arr[0:Mid]                      // Split the array into left half
        Right = arr[Mid:]                      // Split the array into right half
        
        MergeSort(Left)                        // Recursively sort the left half
        MergeSort(Right)                       // Recursively sort the right half
        
        arr = Merge(Left, Right)               // Merge the sorted left and right halves
        
    Return arr                                // Return the sorted array

Function Merge(left, right)
    Create an empty array result              // Array to store the merged result
    
    While left is not empty and right is not empty:
        If left[0] <= right[0]:
            Append left[0] to result
            Remove left[0] from left
        Else:
            Append right[0] to result
            Remove right[0] from right
    
    Append remaining elements of left to result   // If left has remaining elements
    Append remaining elements of right to result  // If right has remaining elements
    
    Return result                              // Return the merged result
```

---

### **Main Function**

```plaintext
Function Main()
    arr = [38, 27, 43, 3, 9, 82, 10]  // Example array to be sorted
    sorted_arr = MergeSort(arr)        // Call MergeSort to sort the array
    Print sorted_arr                   // Output the sorted array
```

---

### **Explanation of the Process**

1. **Input**: The array `[38, 27, 43, 3, 9, 82, 10]` is passed to the `MergeSort` function.
2. **Step 1**: The array is divided into two halves:
   - Left: `[38, 27, 43, 3]`
   - Right: `[9, 82, 10]`
3. **Step 2**: Both halves are recursively sorted:
   - Left half: `[3, 27, 38, 43]`
   - Right half: `[9, 10, 82]`
4. **Step 3**: The two sorted halves are merged to form:
   - Merged: `[3, 9, 10, 27, 38, 43, 82]`
5. **Output**: The final sorted array `[3, 9, 10, 27, 38, 43, 82]` is returned.

---

### **Time Complexity**:
- **Best, Average, and Worst Case**: \( O(n \log n) \)

### **Space Complexity**:
- **O(n)** due to the extra space used for the left and right sub-arrays during the merge process.
