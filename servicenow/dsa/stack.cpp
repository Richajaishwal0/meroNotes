#include <iostream>
using namespace std;


class Stack{
  public:
  int size;
  int *arr;
  int top;
    Stack()
    {
        size=1000;
        top=-1;
        arr= new int[size];
    }
    void push(int val)
    {
        if (top!=size-1)
        {
            top++;
            arr[top]=val;
        }
       else  return ;
    }
    void pop()
    {
        if (top==-1) return;
        cout<< arr[top]<<"\n";
        top--;
        
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
     return top+1;   
    }
  
  void print()
  {
     for (int i=0;i<=top;i++)
     {
         cout<<arr[i]<<" ";
     }
  }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout<<"\n" << s.Top()<<"\n";
    return 0;
}
