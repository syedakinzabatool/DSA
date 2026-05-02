#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function to check if two trees are identical.
bool isIdentical(Node *r1, Node *r2)
{
    // base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if ((r1 == NULL && r2 != NULL)||(r1 != NULL && r2 == NULL))
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(){
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    root1->left->left->left = new Node(8);
    root1->left->left->right = new Node(9);
    root1->left->right->left = new Node(10);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    root2->left->left->left = new Node(8);
    root2->left->left->right = new Node(9);
    root2->left->right->left = new Node(10);
  

if((!isIdentical(root1 ,root2))){
    cout<<"Not Identical."<<endl;
}
else{
    cout<<"Identical."<<endl;
}

}