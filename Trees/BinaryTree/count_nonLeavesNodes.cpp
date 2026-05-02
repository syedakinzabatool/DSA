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
int count_nonLeaf_Nodes(Node* root){
    if(!root)  return 0;

    if(root->left==nullptr && root->right==nullptr){
        return 0;
    }
    return 1+ count_nonLeaf_Nodes(root->left)+count_nonLeaf_Nodes(root->right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);


    cout<<"Number of Non-leaf nodes are: "<<count_nonLeaf_Nodes(root)<<endl;
  
}
