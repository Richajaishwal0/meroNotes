### The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users. To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class). If you want others to read or modify the value of a private member, you can provide public get and set methods.
ex:
Code:
```c++
#include <iostream>
#include <string>
using namespace std;
class MyClass{
	private:
		int x;
	public:
	void set(int a)
	{
		x=a;
	}
	int get()
	{
		return x;
	}
	
};
int main()
{
	MyClass obj;
	int num;
	cout<<"Enter the value of any number";
	cin>>num;
	obj.set(num);
	cout<<obj.get();
	return 0;
}
```
Output:
```cmd
Enter the value of any number4
4
```
