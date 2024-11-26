# String Case Conversion and Alphanumeric Check in Python and C++

| **Functionality**        | **Python**                | **C++**                            |
|--------------------------|---------------------------|-------------------------------------|
| **Convert to Lowercase** | `str.lower()`             | `std::tolower(char)` (single char) |
|                          |                           | `std::transform` (entire string)   |
| **Convert to Uppercase** | `str.upper()`             | `std::toupper(char)` (single char) |
|                          |                           | `std::transform` (entire string)   |
| **Check Alphanumeric**   | `char.isalnum()`          | `std::isalnum(char)`               |

---

## **Code Examples**

### Python
```python
text = "Hello, World! 123"

# Convert to lowercase
print(text.lower())  # Output: "hello, world! 123"

# Convert to uppercase
print(text.upper())  # Output: "HELLO, WORLD! 123"

# Check if a character is alphanumeric
print('H'.isalnum())  # Output: True
print('!'.isalnum())  # Output: False
```

### C++
```cpp
#include <iostream>
#include <string>
#include <algorithm>  // For std::transform
#include <cctype>     // For std::tolower, std::toupper, and std::isalnum

int main() {
    std::string text = "Hello, World! 123";

    // Convert to lowercase
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::cout << text << std::endl;  // Output: "hello, world! 123"

    // Convert to uppercase
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    std::cout << text << std::endl;  // Output: "HELLO, WORLD! 123"

    // Check if a character is alphanumeric
    char ch = 'H';
    std::cout << std::isalnum(ch) << std::endl;  // Output: 1 (true)
    ch = '!';
    std::cout << std::isalnum(ch) << std::endl;  // Output: 0 (false)

    return 0;
}
```
