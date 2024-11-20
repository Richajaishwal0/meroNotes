## Constructor Overloading in C++

### **Definition**
Constructor overloading in C++ allows multiple constructors in a class with the same name but different parameter lists. It facilitates the initialization of objects in diverse ways, depending on the context.

---

## **Types of Constructors**

### 1. **Default Constructor**
- A constructor with no arguments.
- Used for default initialization of objects.

#### **Example:**

```cpp
class Example {
public:
    Example() { // Default constructor
        cout << "Default Constructor Called" << endl;
    }
};
Example obj; // Calls Default Constructor
```

---

### 2. **Parameterized Constructor**
- A constructor with one or more parameters.
- Used for initializing objects with specific values.

#### **Example:**

```cpp
class Example {
    int a, b;

public:
    Example(int x, int y) { // Parameterized constructor
        a = x;
        b = y;
        cout << "Parameterized Constructor Called" << endl;
    }
    void display() {
        cout << "a = " << a << ", b = " << b << endl;
    }
};
Example obj(10, 20); // Calls Parameterized Constructor
```

---

### 3. **Single-Parameter Constructor**
- A constructor with a single parameter.
- Often used to create objects with uniform initialization.

#### **Example:**

```cpp
class Example {
    int side;

public:
    Example(int s) { // Single-parameter constructor
        side = s;
        cout << "Single-Parameter Constructor Called: Square Created" << endl;
    }
    void display() {
        cout << "Side = " << side << endl;
    }
};
Example obj(15); // Calls Single-Parameter Constructor
```

---

### 4. **Copy Constructor**
- A constructor that initializes an object using another object of the same class.
- It is used for creating **exact copies** of an existing object.

#### **Syntax:**
```cpp
ClassName(const ClassName &obj);
```

#### **Example:**

```cpp
class Example {
    int a;

public:
    Example(int x) { // Parameterized constructor
        a = x;
    }

    Example(const Example &obj) { // Copy constructor
        a = obj.a;
        cout << "Copy Constructor Called" << endl;
    }

    void display() {
        cout << "a = " << a << endl;
    }
};

Example obj1(50);       // Calls Parameterized Constructor
Example obj2 = obj1;    // Calls Copy Constructor
```

---

## **Complete Example Code**

```cpp
#include <iostream>
using namespace std;

class Rectangle {
    int length, width;

public:
    // Default Constructor
    Rectangle() {
        length = 0;
        width = 0;
        cout << "Default Constructor: Rectangle with 0 dimensions created." << endl;
    }

    // Parameterized Constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
        cout << "Parameterized Constructor: Rectangle with dimensions " 
             << length << " x " << width << " created." << endl;
    }

    // Single Parameter Constructor
    Rectangle(int side) {
        length = width = side;
        cout << "Single-Parameter Constructor: Square with side " 
             << side << " created." << endl;
    }

    // Copy Constructor
    Rectangle(const Rectangle &obj) {
        length = obj.length;
        width = obj.width;
        cout << "Copy Constructor: Rectangle copied." << endl;
    }

    // Display Function
    void display() {
        cout << "Rectangle Dimensions: " << length << " x " << width << endl;
    }
};

int main() {
    Rectangle rect1;             // Default Constructor
    Rectangle rect2(10, 20);     // Parameterized Constructor
    Rectangle rect3(15);         // Single Parameter Constructor
    Rectangle rect4 = rect2;     // Copy Constructor

    rect1.display();
    rect2.display();
    rect3.display();
    rect4.display();

    return 0;
}
```

---

## **Output**

```
Default Constructor: Rectangle with 0 dimensions created.
Parameterized Constructor: Rectangle with dimensions 10 x 20 created.
Single-Parameter Constructor: Square with side 15 created.
Copy Constructor: Rectangle copied.
Rectangle Dimensions: 0 x 0
Rectangle Dimensions: 10 x 20
Rectangle Dimensions: 15 x 15
Rectangle Dimensions: 10 x 20
```

---

## **Key Points**

1. **Default Constructor**: No arguments; used for default initialization.
2. **Parameterized Constructor**: Initializes objects with user-defined values.
3. **Single-Parameter Constructor**: Simplifies creating uniform objects.
4. **Copy Constructor**:
   - Used for duplicating objects.
   - If no explicit copy constructor is defined, C++ provides a default one.
   - Essential in cases of deep copying for dynamic memory allocation.

---

## **Advantages**
- Increases **flexibility** for object initialization.
- Reduces redundancy by allowing multiple initialization styles.
- Copy constructors are critical for handling **dynamic memory** and preventing shallow copies.
