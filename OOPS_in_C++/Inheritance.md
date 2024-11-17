### We can inherit the class from the base class in c++ using inheritance concept.
In inheritance there are two classes they are:
 - derived class: The child class that is being created from the parent class.
 - base class: The parent class that inherit the child class.
**:** is used to inherit the base class
Types of inheritance in c++
1. Single inheritance
2. Multiple inheritance
3. Hierechal inheritance
4. Multilevel inheritance
5. Hybrid Inheritance 
ex:
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
