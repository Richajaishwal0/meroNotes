#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

class DLinkedList {
    Node* head;
public:
    DLinkedList () {
        head=NULL;
    }
    void insertB(int val)
    {
        Node* newnode= new Node();
        newnode->value=val;
        newnode->prev=NULL;
        newnode->next=head;
        head=newnode;
    }
    void insertE(int val)
    {
       if (head==NULL)
       {
           insertB(val);
       }
       else
       {
           Node* newnode=new Node();
           Node* temp=head;
           while (temp->next!=NULL)
           {
               temp=temp->next;
           }
           temp->next=newnode;
           newnode->prev=temp;
           newnode->value=val;
           newnode->next=NULL;
           
       }
    }
        void insertP (int val, int po)
        {
            if (po<0)
            {
                cout<<"Invalid position";
                return;
            }
            else if (po==0) //assuming the zero indexed list
            {
                insertB(val);
                return;
            }
            int index=0;
            Node * temp=head;
            Node* newnode= new Node();
            while (index<po-1)
            {
                temp=temp->next;
                index++;
            }
            if (!temp)
            {
                cout<<"index out of range"<<endl;
                return;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->value=val;
            
        }
        void deleteB()
        {
            if (!head)
            {
                cout<<"Empty list"<<endl;
            }
            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
            
        }
        void deleteE()
        {
            if (!head)
            {
                cout<<"list is empty";
                return;
            }
            else if (head->next==NULL)
            {
                deleteB();
            }
            Node * temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->prev->next=NULL;
        }
        
        void deletep(int po)
        {
            if (po==0)
            {
                deleteB();
            }
            else if (po<0)
            {
                cout<<"invalid position"<<endl;
                return;
            }
            else
            {
                Node* temp=head;
                int index=0;
                while (temp->next!=NULL)
                {
                    index++;
                    temp=temp->next;
                }
                if (po>index)
                {
                    cout<<"out of range"<<endl;
                    return;
                }
                index=0;
                temp=head;
                Node* q=temp;
                while (index<po-1)
                {
                    temp=temp->next;
                    q=temp->next;
                    index++;
                }
                temp->next=q->next;
                temp->next->prev=temp;
                delete q;
            }
        }
        
        
    void print()
    {
        if (!head)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            Node* temp=head;
            while (temp!=NULL)
            {
                cout<<temp->value<<" ";
                temp=temp->next;
            }
        }
    }

};

int main()
{
    DLinkedList list1;
    list1.insertB(10);
    list1.insertB(20);
    list1.insertB(30);
    list1.insertE(40);
    list1.insertE(50);
    list1.insertP(0,2);
    list1.deleteB();
     list1.deleteE();
     list1.deletep(2);
    list1.print();
    return 0;
}
