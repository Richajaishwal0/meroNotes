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
// queue 


#include <iostream>
using namespace std;

class Queue{
  public:
    int front;
    int rear;
    int size;
    int * arr;
    Queue()
    {
        front=-1;
        rear=-1;
        size=1000;
        arr=new int[size];
    }
    void enqueue(int val)
    {
        if (rear==size-1) return;
        if (front==-1) front=0;
        rear++;
        arr[rear]=val;
    }
    void dequeue()
    {
     if (front==-1 || front>rear) return;
     cout<<"=="<<arr[front]<<"\n";
     front++;
    }
    void peek()
    {
       cout<<arr[front];
    }
    int isempty()
    {
         if (front == -1 || front > rear) return 1;
        return 0;;
    }
    int isfull()
    {
        if (rear==size-1) return 1;
        return 0;
    }
    void print()
    {
        for (int i=front;i<=rear;i++)
        {
            cout<<" "<<arr[i]<<"\n";
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.print();
}
