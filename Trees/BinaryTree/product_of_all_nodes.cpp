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
int product(Node* root){
    if(!root)  return 1;
    return root->data*(product(root->left)*product(root->right));
}
int main(){
  Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Product: "<<product(root)<<endl;
  
}
