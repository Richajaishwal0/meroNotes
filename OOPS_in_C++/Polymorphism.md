### Polymorphism means "many forms", and it occurs when we have many classes that are related to each other by inheritance.
Polymorphism can be achieved in two ways:
Here’s a short recap of **Method Overloading** and **Method Overriding** in Object-Oriented Programming (OOP):  

### **1. Method Overloading**
- **Definition**: Same method name, different parameter lists (number, type, or order of parameters) in the same class.
- **Purpose**: To perform similar tasks with variations in input data.
- **Compile-time** (Static) **Polymorphism**: Resolved during compilation.
- **Example** (in Java):  
  ```java
  class Calculator {
      int add(int a, int b) {
          return a + b;
      }
      double add(double a, double b) {
          return a + b;
      }
  }
  ```

---

### **2. Method Overriding**
- **Definition**: A subclass provides a specific implementation of a method already defined in its parent class.
- **Purpose**: To change or extend the behavior of a parent class method.
- **Run-time** (Dynamic) **Polymorphism**: Resolved during execution.
- **Rules**:
  - Method name, parameters, and return type must match.
  - Must be marked `@Override` in some languages like Java.
  - Cannot override `final` or `static` methods.
- **Example** (in Java):  
  ```java
  class Animal {
      void sound() {
          System.out.println("Animal makes a sound");
      }
  }
  class Dog extends Animal {
      @Override
      void sound() {
          System.out.println("Dog barks");
      }
  }
  ```

Let me know if you'd like further clarification! 😊
