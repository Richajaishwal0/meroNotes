### In C++, there are three access specifiers:
 - public - members are accessible from outside the class
 - private - members cannot be accessed (or viewed) from outside the class
 - protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.

ex:

Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class MyClass{
	public:
		int x;
	private:
		int y;
	}
	
int main()
{
	MyClass obj;
	obj.x=20;
	obj.y=20;
	return 0;
}
```
Output:
```cmd
error: y is private
```
