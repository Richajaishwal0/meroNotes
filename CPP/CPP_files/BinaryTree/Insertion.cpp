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
    // we will use the leverl order traversal to insert in the tree
  Node*insert(Node * root,int data)
   {
      if (root==nullptr)
      {
          root=new Node(data);
          return root;
      }
      queue <Node*> q;
      q.push(root);
      while (!q.empty())
      {
          Node* node=q.front();
          q.pop();
          
          if (node->left==nullptr)
          {
            node->left=new Node(data);
            break;
          }
          else{
              q.push(node->left);
          }
          if (node->right==nullptr)
          {
              node->right=new Node(data);
              break;
          }
          else{
              q.push(node->right);
          }
      }
      return root;
   }
};


int main()
{
    Node * root=nullptr;
    BinaryTree bt;
    root=bt.insert(root,2);
    root=bt.insert(root,3);
    root=bt.insert(root,4);
    bt.inorder(root);
    return 0;
}
// OUTPUT:
// 3 2 4 
