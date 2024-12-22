#include <iostream>
using namespace std;
#define max_size 5

class Queue
{
public:
    int front;
    int rear;
    int arr[max_size];

    Queue(): front(-1),rear(-1){}
    
    int isempty()
    {
      return (front==-1 && rear==-1);
    }
    int isfull()
    {   
        // int length = sizeof(arr) / sizeof(arr[0]);
        return (rear==max_size-1);
    }
    void enqueue(int val)
    {
      if (isempty())
        {   
        front=0;
        }
        if (!isfull())
        {
            rear++;
            arr[rear]=val;
        }
    }
    void dequeue()
    {
        if (!isempty())
        {
            front++;
        }
        if (isempty())
        {
            front=rear=-1;
        }
    }
    void afront()
    {
        cout<<"\n"<<arr[front];
    }
    
    void  print()
    {
        for (int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    
};
int main()
{
    Queue a;
    a.enqueue(2);
     a.enqueue(3); 
     a.enqueue(4); 
     a.enqueue(5);
     a.dequeue();
     a.dequeue();
     a.dequeue();
     a.dequeue();
     a.print();
    //  a.afront();

    return 0;
}
