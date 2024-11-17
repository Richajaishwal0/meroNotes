Here is a simple  example of the class with its attributes and methods.

Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class MyClass{
	public:
		int num;
		string name;
		void method()
		{
			cout<<"Hello world\n";
		}
};
int main()
{
	MyClass obj;
	obj.num=23;
	obj.name="ram";
	obj.method();
	cout<<obj.name<<"\n"<<obj.num;
	return 0;
}
```
Output:
```cmd
Hello world
ram
23
```
In C++ methods can also be defined outside the class. To define a function outside the class definition, you have to declare it inside the class and then define it outside of the class. This is done by specifiying the name of the class, followed the scope resolution :: operator, followed by the name of the function:
ex:

Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class MyClass{
	public:
		int num;
		string name;
		void method();
};
void MyClass::method()
{
	cout<<"Hello world\n";
}
int main()
{
	MyClass obj;
	obj.num=23;
	obj.name="ram";
	obj.method();
	cout<<obj.name<<"\n"<<obj.num;
	return 0;
}
```
Output:
```cmd
Hello world
ram
23
```
