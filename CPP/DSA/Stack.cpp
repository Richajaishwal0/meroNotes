#include <iostream>
using namespace std;
#define n 100
class stack{
  int * arr;
  int top;
  stack()
  {
    arr=new int[n];
    top=-1;
  }
  void push(int val)
  {
    if (top==n-1)
    {
    cout <<"stack overflow"<<endl;
    return;
    }
    else {
    top++;
    arr[top]=val;
    }
  }
  void pop()
{
    if (top==-1)
    {
        cout <<"stack underflow"<<endl;
        return;
    }
    else {
          cout<<arr[top]<<endl;
          top--;
    }
}
  int topp()
{
  if (top==-1)
    {
        cout <<"stack underflow"<<endl;
        return;
    }
  else 
  {
    return arr[top];
  } 
}
  int empty()
  {
    return (top==-1);
  }
  int full()
  {
    return (top==n-1)
  }
};
int main()
{
  stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  cout<<st.topp()<<endl;
  st.pop();
  cout<<st.topp()<<endl;
  return 0;
}
