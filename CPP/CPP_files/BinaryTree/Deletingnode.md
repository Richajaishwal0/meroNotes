### Logic
The idea is to traverse the tree in level order manner. To perform the Deletion in a Binary Tree follow below:
- Starting at the root, find the deepest and rightmost node in the binary tree and the node which we want to delete. 
- Replace the deepest rightmost node’s data with the node to be deleted. 
- Then delete the deepest rightmost node.
  ![image](https://github.com/user-attachments/assets/34d31c21-6807-4fe8-9edb-fba6ba6e4eb7)
  
Code
```cpp
#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

class BinaryTree{
    public:
    void delDeepest(Node * root, Node * delnode)
    {
        queue<Node *>q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr=q.front();
            q.pop();
            if (curr==delnode)
            {
                curr=nullptr;
                delete(delnode);
                return;
            }
            if (curr->right)
            {
                if (curr->right==delnode)
                {
                    curr->right=nullptr;
                    delete(delnode);
                    return;
                }
                q.push(curr->right);
            }
            if (curr->left)
            {
                if (curr->left==delnode)
                {
                    curr->left=nullptr;
                    delete(delnode);
                    return;
                }
                q.push(curr->left);
            }
        }
    }
  Node* deletion(Node *root, int  dnode)
    {
        if (root==nullptr) return nullptr;
        
        if (root->left==nullptr && root->right==nullptr){
        
        if (root->data==dnode)
        {
            return nullptr;
        }
        else{
            return root;
        }
        }
        
        queue <Node*>q;
        q.push(root);
        Node* keynode=nullptr;
        Node*curr;
        while(!q.empty())
        {
          curr=q.front();
            q.pop();
            
            if (curr->data==dnode)
            {
               keynode=curr; 
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        
        if (keynode)
        {
            int x=curr->data;
            keynode->data=x;
            delDeepest(root,curr);
        }
        return root;
        
    }
    void inorder(Node* curr) {
    if (!curr)
        return;
    inorder(curr->left);        
    cout << curr->data << " ";  
    inorder(curr->right);     
}

};


int main() {
  
    // Construct the binary tree
    //       10         
      //      /  \       
      //    11    9
      //   / \   / \     
      //  7  12 15  8     

    Node* root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    BinaryTree b;
    int key = 11;
    root = b.deletion(root, key); 

    b.inorder(root);
    return 0;
}
```
Output
```
7 8 12 10 15 9 
```
