### **Singly Linked List Using Stack for Insertion and Deletion**

---

### **1. Define Singly Linked List Node Structure**:
- Each node has:
  - `value`: The data stored in the node.
  - `next`: Pointer to the next node.

---

### **2. Define Stack Node Structure**:
- Each stack node has:
  - `value`: The data stored in the stack.
  - `next`: Pointer to the next stack node.

---

### **3. Function: Create Stack**:
- Initialize an empty stack (`top = NULL`).
- Return the stack.

---

### **4. Function: Push (To Stack)**:
- Create a new stack node with the given `value`.
- Set the new node's `next` to the current `top`.
- Update `top` to the new node.
- Return the updated stack.

---

### **5. Function: Pop (From Stack)**:
- If the stack is empty (`top == NULL`), return `NULL`.
- Store `top` in a temporary variable.
- Update `top` to `top.next`.
- Return the value of the popped node.

---

### **6. Function: Insert at Beginning (Using Stack)**:
- Push the new value to the stack.
- Create a new linked list node with the popped value from the stack.
- Set the new node's `next` to the current head.
- Set the head to the new node.
- Return the updated head.

---

### **7. Function: Insert at End (Using Stack)**:
- If the linked list is empty (`head == NULL`), create a new node with the value and return the head.
- Push each node value in the linked list to the stack.
- Push the new value onto the stack.
- Rebuild the linked list by popping each value from the stack and updating the next pointers accordingly.
- Return the updated head.

---

### **8. Function: Delete by Value (Using Stack)**:
- If the linked list is empty (`head == NULL`), return the head.
- Push each node value in the linked list to the stack.
- Rebuild the linked list by popping each value from the stack, skipping the value to delete.
- Return the updated head.

---

### **9. Function: Traverse and Print Linked List**:
- Traverse the linked list and print each node's value.
### **Summary**:
- This approach uses a **stack** for temporary storage during **insertion** and **deletion** operations.
- The **insert at beginning** and **insert at end** operations use the stack for value manipulation.
- **Delete by value** ensures that the list is reconstructed with the node to delete excluded.
