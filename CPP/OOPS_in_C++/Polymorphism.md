### Polymorphism means "many forms", and it occurs when we have many classes that are related to each other by inheritance.
Polymorphism can be achieved in two ways:
Here’s a short recap of **Method Overloading** and **Method Overriding** in Object-Oriented Programming (OOP):  

### **1. Method Overloading**
- **Definition**: Same method name, different parameter lists (number, type, or order of parameters) in the same class.
- **Purpose**: To perform similar tasks with variations in input data.
- **Compile-time** (Static) **Polymorphism**: Resolved during compilation.
- **Example**:
  
```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    // Method with two integer parameters
    int add(int a, int b) {
        return a + b;
    }

    // Method with two double parameters
    double add(double a, double b) {
        return a + b;
    }

    // Method with three integer parameters
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    cout << "Addition of two integers: " << calc.add(5, 3) << endl;          // Calls add(int, int)
    cout << "Addition of two doubles: " << calc.add(5.5, 3.2) << endl;      // Calls add(double, double)
    cout << "Addition of three integers: " << calc.add(1, 2, 3) << endl;    // Calls add(int, int, int)

    return 0;
}
```

**Output**:
```
Addition of two integers: 8
Addition of two doubles: 8.7
Addition of three integers: 6
```
### **2. Method Overriding**
- **Definition**: A subclass provides a specific implementation of a method already defined in its parent class.
- **Purpose**: To change or extend the behavior of a parent class method.
- **Run-time** (Dynamic) **Polymorphism**: Resolved during execution.
- **Rules**:
  - Method name, parameters, and return type must match.
  - Must be marked `@Override` in some languages like Java.
  - Cannot override `final` or `static` methods.
  - 
```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void sound() { // Virtual function for overriding
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void sound() override { // Overriding the base class method
        cout << "Dog barks" << endl;
    }
};

// Another derived class
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animal; // Pointer to the base class

    Dog dog;
    Cat cat;

    // Dynamic polymorphism: the function called depends on the object
    animal = &dog;
    animal->sound(); // Calls Dog's sound()

    animal = &cat;
    animal->sound(); // Calls Cat's sound()

    return 0;
}
```

**Output**:
```
Dog barks
Cat meows
```

---

### **Key Notes**:
1. **Virtual Functions**: In run-time polymorphism, the base class method must be marked as `virtual` to enable overriding.
2. **Dynamic Binding**: The function to be executed is determined at runtime based on the object the base class pointer refers to.
