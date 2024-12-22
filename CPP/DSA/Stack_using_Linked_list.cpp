#include <iostream>
using namespace std;
class Node{
    
    public:
    int data;
    Node*  next;
    Node (int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

class stack{
    Node * head;
    public:
    stack()
    {
    this->head=nullptr;
    }
    int empty()
    {
      return (head==nullptr);
      
    }
    // int full()
    // {
    //   Node * newnode= new Node(data) 
    // }
    void push(int data)
    {
        Node * newnode= new Node(data);
        if (!newnode)
        {
            cout<<"stack overflow"<<endl;
        }
        newnode->next=head;
        head=newnode;
    }
    void pop()
    {
        if (empty())
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        Node * temp=head;
        head=head->next;
        delete temp;
    }
    void peek()
    {
        cout<<head->data<<endl;
    }
    void print()
    {   Node * temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main()
{
    stack a;
    a.push(2);
     a.push(3);
      a.push(4);
       a.push(5);
       a.print();
       a.peek();
    return 0;
}
