### **Singly Linked List Using Stack for Insertion and Deletion**

---

### **1. Definition:**
A **Singly Linked List** is a data structure where each node contains data and a pointer to the next node. In this approach, we use a **Stack** to assist with insertion and deletion operations. The stack temporarily stores nodes' values before manipulating the linked list, providing an organized method for adding or removing nodes.

---

### **2. Example:**
Consider the following scenario where a linked list starts empty:
- Insert at beginning: Insert `10` at the beginning.
- Insert at end: Insert `20` at the end.
- Delete by value: Delete node with value `10`.

The operations would look like:
1. Insert `10` at beginning → Linked List: `10`
2. Insert `20` at end → Linked List: `10 -> 20`
3. Delete `10` by value → Linked List: `20`

---

### **3. Pseudocode/Code:**

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.top is None:
            return None
        temp = self.top
        self.top = self.top.next
        return temp.value

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, value):
        stack = Stack()
        stack.push(value)
        new_node = Node(stack.pop())
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, value):
        if self.head is None:
            self.head = Node(value)
            return
        stack = Stack()
        current = self.head
        while current is not None:
            stack.push(current.value)
            current = current.next
        stack.push(value)
        self.head = None
        while stack.top is not None:
            new_node = Node(stack.pop())
            new_node.next = self.head
            self.head = new_node

    def delete_by_value(self, value):
        if self.head is None:
            return None
        stack = Stack()
        current = self.head
        while current is not None:
            stack.push(current.value)
            current = current.next
        self.head = None
        while stack.top is not None:
            node_value = stack.pop()
            if node_value != value:
                new_node = Node(node_value)
                new_node.next = self.head
                self.head = new_node

    def traverse(self):
        current = self.head
        while current is not None:
            print(current.value, end=" -> ")
            current = current.next
        print("None")
```

---

### **4. Time Complexity:**

- **Insert at Beginning**: `O(1)` – Inserting at the beginning of the list using a stack is a constant-time operation.
- **Insert at End**: `O(n)` – Traversing the list and rebuilding it using a stack takes linear time.
- **Delete by Value**: `O(n)` – Traversing the list and rebuilding it after removing a node takes linear time.
- **Traverse**: `O(n)` – Traversing the list to print each node's value is linear in terms of the number of nodes.

---

### **5. Input:**
- **Insert at Beginning**: `10`
- **Insert at End**: `20`
- **Delete by Value**: `10`

---

### **6. Output:**

1. After inserting `10` at the beginning:
   ```
   10 -> None
   ```
2. After inserting `20` at the end:
   ```
   10 -> 20 -> None
   ```
3. After deleting `10` by value:
   ```
   20 -> None
   ```

---

### **Summary:**
- The **Singly Linked List** uses a **stack** for managing nodes during **insertion** and **deletion**.
- **Insertion** (both at the beginning and end) and **deletion** rely on temporarily storing node values in the stack, ensuring proper order manipulation.
- **Traversal** simply prints out the values of the linked list, while the **delete by value** function reconstructs the list after excluding the specified node.

