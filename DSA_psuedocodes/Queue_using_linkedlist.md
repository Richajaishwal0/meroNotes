
### **Queue Using Singly Linked List**

---

### **1. Define Singly Linked List Node Structure**:
- Each node has:
  - `value`: The data stored in the node.
  - `next`: Pointer to the next node.

---

### **2. Define Queue Structure**:
- The Queue has:
  - `front`: Points to the front of the queue (head of the list).
  - `rear`: Points to the rear of the queue (tail of the list).

---

### **3. Function: Create Queue**:
- Initialize `front` and `rear` as `NULL`.
- Return the queue.

---

### **4. Function: Enqueue (Insert into Queue)**:
- Create a new node with the given `value`.
- If the queue is empty (`front == NULL`):
  - Set both `front` and `rear` to the new node.
- Otherwise:
  - Set `rear.next` to the new node and update `rear` to the new node.
- Return the updated queue.

---

### **5. Function: Dequeue (Remove from Queue)**:
- If the queue is empty (`front == NULL`), return `NULL`.
- Store the `front` node in a temporary variable.
- Update `front` to `front.next`.
- If `front` becomes `NULL`, update `rear` to `NULL` (queue is now empty).
- Return the value of the dequeued node.

---

### **6. Function: Peek (Get Front of Queue)**:
- If the queue is empty (`front == NULL`), return `NULL`.
- Return the value of the `front` node.

---

### **7. Function: Traverse and Print Queue**:
- Traverse the linked list from `front` to `rear` and print each node's value.

---

### **Summary**:

- The **Queue** uses a **Singly Linked List** where `front` points to the first element and `rear` points to the last element.
- **Enqueue** adds an element to the rear of the queue, and **Dequeue** removes the element from the front.
- **Peek** allows you to view the element at the front of the queue without removing it.
