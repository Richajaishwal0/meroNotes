### A constructor in C++ is a special method that is automatically called when an object of a class is created.
Constructor is created using the same name of the class followed by the paranthethis as ():
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class MyClass{
	public:
	 MyClass()
	{
		cout<<"Hello world";
	}
};

int main()
{
	MyClass obj;
	return 0;
}
```
Output:
```cmd
Hello world
```
