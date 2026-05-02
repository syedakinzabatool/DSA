#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int count_leaves(Node* root){
    if(!root)  return 0;

    if(root->left==nullptr && root->right==nullptr){
        return 1;
    }
    return count_leaves(root->left)+count_leaves(root->right);
}
int main(){
  Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);


    cout<<"Number of leaf nodes are: "<<count_leaves(root)<<endl;
  
}
