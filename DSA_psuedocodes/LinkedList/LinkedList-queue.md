
### **1) Definition**:
- A **Queue** is a linear data structure that follows the **First In First Out (FIFO)** principle, where elements are added at the rear (end) and removed from the front (beginning). It is implemented using a **Singly Linked List**, where:
  - `front`: Points to the first element (head of the list).
  - `rear`: Points to the last element (tail of the list).

---

### **2) Example**:
Consider the following operations on an initially empty queue:

1. **Enqueue(10)**  
   Queue = [10]  
   **Output**: Queue after Enqueue = [10]

2. **Enqueue(20)**  
   Queue = [10, 20]  
   **Output**: Queue after Enqueue = [10, 20]

3. **Dequeue()**  
   Queue = [20] (10 is removed)  
   **Output**: Dequeued value = 10

4. **Peek()**  
   Front of the queue is 20.  
   **Output**: Peek value = 20

5. **Dequeue()**  
   Queue = [] (20 is removed)  
   **Output**: Dequeued value = 20

6. **Peek()**  
   The queue is now empty.  
   **Output**: Peek value = NULL

---

### **3) Pseudocode/Code**:

```
Node:
    value ← data stored in the node
    next ← pointer to the next node

Queue:
    front ← points to the first node in the queue
    rear ← points to the last node in the queue

Function CreateQueue():
    front ← NULL
    rear ← NULL
    Return Queue

Function Enqueue(value):
    new_node ← Create new node with value
    If front is NULL:
        front ← new_node
        rear ← new_node
    Else:
        rear.next ← new_node
        rear ← new_node
    EndIf

Function Dequeue():
    If front is NULL:
        Return NULL  // Queue is empty
    EndIf
    temp ← front
    front ← front.next
    If front is NULL:
        rear ← NULL  // Queue is now empty
    EndIf
    Return temp.value  // Return the dequeued value

Function Peek():
    If front is NULL:
        Return NULL  // Queue is empty
    EndIf
    Return front.value  // Return the value at the front of the queue

Function Traverse():
    current ← front
    While current is not NULL:
        Print current.value
        current ← current.next
    EndWhile
    Print "None"  // Indicating the end of the queue
```

---

### **4) Time Complexity**:
- **Enqueue**: O(1) – Insertion happens at the rear of the queue.
- **Dequeue**: O(1) – Removal happens at the front of the queue.
- **Peek**: O(1) – Fetching the value at the front.
- **Traverse**: O(n) – Traversing through all elements in the queue.

---

### **5) Sample Input and Output**:

- **Input 1**: Enqueue(10)
  - **Output**: Queue = [10]

- **Input 2**: Enqueue(20)
  - **Output**: Queue = [10, 20]

- **Input 3**: Dequeue()
  - **Output**: Dequeued value = 10
  - **Queue after Dequeue**: [20]

- **Input 4**: Peek()
  - **Output**: Peek value = 20

- **Input 5**: Dequeue()
  - **Output**: Dequeued value = 20
  - **Queue after Dequeue**: []

- **Input 6**: Peek()
  - **Output**: Peek value = NULL (Queue is empty)

---

### **6) Output**:
- **Enqueue(value)**: Updates the queue by adding the given value at the rear.
  - Example: Enqueue(10) → Queue = [10]
  
- **Dequeue()**: Returns the value of the dequeued element, or `NULL` if the queue is empty.
  - Example: Dequeue() → Dequeued value = 10
  
- **Peek()**: Returns the value at the front of the queue, or `NULL` if the queue is empty.
  - Example: Peek() → Peek value = 20
  
- **Traverse()**: Prints the entire queue from front to rear.
  - Example: Traverse() → Prints 10 20 None
  
---

### **Summary**:
- The **Queue** uses a **Singly Linked List** with the `front` and `rear` pointers.
- **Enqueue** adds elements at the rear of the queue, and **Dequeue** removes elements from the front, ensuring the **FIFO** order.
- **Peek** allows you to see the front element without removing it.
