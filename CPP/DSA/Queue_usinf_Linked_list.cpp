#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

class Queue{
    Node* front;
    Node* rear;
    public:
    Queue()
    {
        this->front=nullptr;
        this->rear=nullptr;
    }
    
    int empty()
    {
        if (front==nullptr && rear==nullptr)
        {
            return 1;
        }
        return 0;
    }
    void enqueue(int data)
    {
        Node * newnode=new Node(data);
        if(empty())
        {
            front=rear=newnode;
        }
        rear->next=newnode;
        rear=newnode;
    }
    void dequeue()
    {
        if (empty())
        {
            cout<<"queue underflow cant delete the element";
            return;
        }
        Node * temp=front;
        front=front->next;
        
        delete temp;
        
        
    }
    
    void getfront()
    {   if (!empty())
    {
          cout<<"\n"<<front->data<<"\n";
    }
      
    }
    void getrear()
    {
        cout<<rear->data<<"\n";
    }
    void print()
    {
        Node * temp=front;
        while (temp!=rear->next)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    
};

int  main()
{
    Queue a;
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    a.getfront();
    a.getrear();
  a.dequeue();
    a.print();
      
    //   a.print();
   return 0; 

}
