Welcome to Haskell! 😊

In Haskell, `main ::` is part of the **type signature** that defines the **type of the `main` function**.

### **What does `main ::` mean?**

- **`main`** is the entry point of a Haskell program, similar to the `main` function in C, C++, or Java. It's where the program starts executing.
- **`::`** is the **type annotation operator**. It indicates that you're about to declare the **type of something**.
- After the `::`, we specify the **type** of `main`.   

### **Understanding the `main` function type signature**

In Haskell, the type signature for `main` looks like this:
```haskell
main :: IO ()
```

- **`main`** is the name of the function.
- **`::`** indicates that we're specifying the type of the `main` function.
- **`IO ()`** is the type of `main`. Let’s break this down:
  - **`IO`** is a **monad** in Haskell. The `IO` type is used for actions that interact with the outside world, like printing to the screen, reading input, or writing to a file. It means **side-effecting actions**.
  - **`()`, also known as `unit`**, is similar to `void` in other languages like C, C++, or Java. It represents **no meaningful result** or **nothing**. So, when you write `IO ()`, it means the `main` function performs **IO actions** but **doesn’t return any value**.

### **Example of `main` with `IO ()`**
```haskell
main :: IO ()
main = putStrLn "Hello, World!"
```
Here’s what’s happening:
- **`main`**: The starting point of the program.
- **`:: IO ()`**: `main` is performing an **IO action** and **doesn't return anything** (`()`).
- **`putStrLn "Hello, World!"`**: This is an **IO action** that prints the string to the console.

### **Another Example with `main` and `IO`**
```haskell
main :: IO ()
main = do
    let x = 5
    let y = 10
    print (x + y)
```
- **`do` block**: This is a way to sequence multiple **IO actions**. You can think of it like a block of code where each line performs a side-effecting operation.
- **`print`**: This is an IO function that prints the result to the console.

### **Why is `main :: IO ()` important?**
In Haskell, because of the **pure functional nature** of the language, code that performs **side effects** (like printing to the screen, reading from files, etc.) is handled using the **IO monad**. The `main` function’s type being `IO ()` tells the compiler that `main` performs such side effects and doesn't return any meaningful result.

---

- **`main`** is the starting point of your Haskell program.
- **`::`** is used to specify the **type** of something.
- **`IO ()`** means that `main` performs IO operations and does not return anything of value.

### **Example: Getting Input and Printing Output**

```haskell
main :: IO ()
main = do
    -- Ask the user for their name
    putStrLn "What is your name?"
    
    -- Get the user's name as input
    name <- getLine
    
    -- Greet the user with their name
    putStrLn ("Hello, " ++ name ++ "!")
```

### **Explanation**
- **`putStrLn "What is your name?"`**: This prints the prompt asking for the user's name.
- **`name <- getLine`**: This reads a line of input from the user (the name).
  - The `<-` syntax is used to extract the value from the IO action (`getLine`).
- **`putStrLn ("Hello, " ++ name ++ "!")`**: This prints the greeting message using the name the user provided.

### **Sample Input and Output**
When you run this program, you'll see the following interaction in the terminal:

#### **Input**
```
What is your name?
Alice
```

#### **Output**
```
Hello, Alice!
```

---

### **Summary**
This example shows how to get user input (`getLine`) and then print a personalized message (`putStrLn`) using a `do` block inside the `main` function. The `do` block allows you to sequence actions, ensuring they happen in order.

