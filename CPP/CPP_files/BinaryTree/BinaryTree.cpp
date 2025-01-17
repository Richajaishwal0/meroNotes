#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node * left, * right;
    Node(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
    
};
class BinaryTree{
    public:
    // DFS
    void inorder(Node * root)
    {
      if (root==nullptr) return;
      inorder(root->left); 
      cout<<root->data<<" ";
      inorder(root->right);
    }
    // DFS
    void preorder(Node *root)
    {
        if (root==nullptr) return ;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    // DFS
    void postorder(Node *root)
    {
        if (root==nullptr) return ;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    //  BFS
    void levelorder(Node *root)
    {
        if (root==nullptr) return ;
        queue<Node*>q;
        q.push(root);
        while (!q.empty())
        {
           Node* node=q.front();
        q.pop();
        cout<<node->data<<" ";
        if (node->left!=nullptr) q.push(node->left);
        if (node->right!=nullptr) q.push(node->right);  
        }
       
    }
};

int main()
{
    Node * root= new Node(2);
    Node * sec=new Node(3);
    Node * third=new Node(4);
    Node * fourth=new Node(5);
    root->left=sec;
    root->right=third;
    sec->left=fourth;
    BinaryTree bt;
     cout<<"Preorder: "<<endl;
    bt.preorder(root);
     cout<<endl;
    cout<<"Inorder: "<<endl;
    bt.inorder(root);
     cout<<endl;
     cout<<"Postorder: "<<endl;
    bt.postorder(root);
     cout<<endl;
     cout<<"levelorder: "<<endl;
    bt.levelorder(root);
    
}

// Output

// Preorder: 
// 2 3 5 4 
// Inorder: 
// 5 3 2 4 
// Postorder: 
// 5 3 4 2 
// levelorder: 
// 2 3 4 5 
