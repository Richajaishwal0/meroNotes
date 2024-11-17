### We can inherit the class from the base class in c++ using inheritance concept.
In inheritance there are two classes they are:
 - derived class: The child class that is being created from the parent class.
 - base class: The parent class that inherit the child class.
**:** is used to inherit the base class
Types of inheritance in c++

![image](https://github.com/user-attachments/assets/0df4a113-7823-48ec-9a7c-7d73c6439f05)


1. Single inheritance
   
   ![image](https://github.com/user-attachments/assets/f7ff6cbd-516d-42e6-b4e0-6fdbc33cb569)
   
2. Multiple inheritance
   
   ![image](https://github.com/user-attachments/assets/c803dc86-6574-4a9f-b2fc-7ade8a94f454)

3. Hierechal inheritance

   ![image](https://github.com/user-attachments/assets/5c597b20-467d-4769-9b4a-daf7316f1dd8)

4. Multilevel inheritance
   
   ![image](https://github.com/user-attachments/assets/95d8a515-0807-48f5-bae7-2c6d837df05c)

5. Hybrid Inheritance
   
   ![image](https://github.com/user-attachments/assets/97dc3e7d-c1c2-413b-8097-1a6fff46c0fe)

ex:
   	
1. Single inheritance
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class Vehicle{
	public:
		string brand="Ford";
	void honk()
	{
		cout<<"Tuut Tuut\n";
	}
};
class Car: public Vehicle{
	public:
		string name="Mustang";
};
int main()
{
	Car obj;
	obj.honk();
	cout<<obj.name<<"\n"<<obj.brand<<" ";
	return 0;
}
```
Output:
```cmd
Tuut Tuut
Mustang
Ford
```
2. Multiple inheritance
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class Father{
	public:
		string fatherName="ram";
};
class Mother{
	public:
		string motherName="manju";
};

class child: public Father, public Mother{
	public:
		string name="hari";
};
int main()
{
	child obj;
	cout<<obj.name<<endl;
	cout << obj.fatherName<<endl;
	cout << obj.motherName <<endl;
	return 0;
}
```
Output:
```cmd
hari
ram
manju
```
   
4. Hierechal inheritance
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class Vehicle{
	public:
		string brand="Ford";
		void honk()
		{
			cout<<"tut tut\n";
		}
};
class bus:public Vehicle{
	public:
		string name="bus\n";
};

class car: public Vehicle{
	public:
		string name="car\n";
};
int main()
{
	car objc;
	bus objb;
	objc.name;
	objc.honk();
	objb.name;
	objb.honk();
	return 0;
}
```
Output:
```cmd
tut tut
tut tut
```
5. Multilevel Inheritance
 
**Note**: The **diamond problem** in C++ occurs in multiple inheritance when a derived class inherits from two base classes that share a common ancestor, leading to ambiguity and duplicate instances of the ancestor. To solve this, use **virtual inheritance** in the intermediate base classes to ensure only a single shared instance of the common ancestor exists. The most derived class should explicitly initialize the shared base class in its constructor. Virtual inheritance eliminates ambiguity, ensures efficient memory usage, and simplifies member access.
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class GrandFather{
	public:
		string GfatherName="ram";
};
class Father: public GrandFather{
	public:
		string FatherName="ramu";
};

class child: public Father{
	public:
		string name="hari";
};
int main()
{
	child obj;
	cout<<obj.name<<endl;
	cout << obj.FatherName<<endl;
	cout << obj.GfatherName <<endl;
	return 0;
}
```
Output:
```cmd
hari
ramu
ram
```
5. Hybrid inheritance
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class A{
	public:
		int a=4;
};
class B: virtual public A{
	public:
		int b=5;
};

class C: virtual public A{
	public:
		int c=6;
};
class D: public B, public C {
	public:
		int d=6;
};
int main()
{
	D obj;
	cout<<obj.a<<endl;
	cout<<obj.b<<endl;
	cout<<obj.c<<endl;
	cout<<obj.d<<endl;
	return 0;
}
```
Output:
```cmd
4
5
6
6
```
