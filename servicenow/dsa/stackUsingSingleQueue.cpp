#include <iostream>
#include <queue>
using namespace std;

class Stack{
  
  public:
  queue <int> q1;
  void push(int val)
    {
        q1.push(val);
        int size=q1.size();
        for (int i=0;i<size-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
        cout<<q1.front()<<"\n";
    }
    int pop()
    {
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    int top()
    {
        return q1.front();
    }
    bool empty()
    {
        return q1.empty();
    }
};
int main()
{
    
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<< s.pop();
    cout<< s.top();
    cout<<s.empty();
    return 0;
}
