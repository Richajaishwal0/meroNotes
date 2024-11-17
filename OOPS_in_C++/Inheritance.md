### We can inherit the class from the base class in c++ using inheritance concept.
In inheritance there are two classes they are:
 - derived class: The child class that is being created from the parent class.
 - base class: The parent class that inherit the child class.
**:** is used to inherit the base class
Types of inheritance in c++

![image](https://github.com/user-attachments/assets/0df4a113-7823-48ec-9a7c-7d73c6439f05)


1. Single inheritance
   
   ![image](https://github.com/user-attachments/assets/f7ff6cbd-516d-42e6-b4e0-6fdbc33cb569)
   
3. Multiple inheritance
   
   ![image](https://github.com/user-attachments/assets/c803dc86-6574-4a9f-b2fc-7ade8a94f454)

5. Hierechal inheritance

   ![image](https://github.com/user-attachments/assets/5c597b20-467d-4769-9b4a-daf7316f1dd8)

7. Multilevel inheritance
   
   ![image](https://github.com/user-attachments/assets/95d8a515-0807-48f5-bae7-2c6d837df05c)

8. Hybrid Inheritance
   
   ![image](https://github.com/user-attachments/assets/97dc3e7d-c1c2-413b-8097-1a6fff46c0fe)

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

