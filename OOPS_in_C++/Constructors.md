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
Constructor can also be used by passing the parameter.
Here is the example of constructor with parameters.
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class MyClass{
	public:
		string name;
		string grade;
		int rollno;
	 MyClass(string a, string b, int c)
	{
		name=a;
		grade=b;
		rollno=c;
	}
};

int main()
{
	MyClass obj("ram","third",1);
	cout <<obj.name<<" "<<obj.grade<<" "<<obj.rollno;
	return 0;
}
```
Output:
```cmd
ram third 1
```
Just like functions, constructors can also be defined outside the class. First, declare the constructor inside the class, and then define it outside of the class by specifying the name of the class, followed by the scope resolution :: operator, followed by the name of the constructor (which is the same as the class):

Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class MyClass{
	public:
		string name;
		string grade;
		int rollno;
	 MyClass(string a, string b, int c);
};

 MyClass::MyClass(string a, string b, int c)
	{
		name=a;
		grade=b;
		rollno=c;
	}
	
int main()
{
	MyClass obj("ram","third",1);
	cout <<obj.name<<" "<<obj.grade<<" "<<obj.rollno;
	return 0;
}
```
Output:
```cmd
ram third 1
```
