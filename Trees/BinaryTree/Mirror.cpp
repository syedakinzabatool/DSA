#include <iostream>
#include <algorithm>
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

void mirror(Node *root)
{
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

void printInOrder(Node *root)
{
    if (!root) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Original tree (InOrder): ";
    printInOrder(root);
    cout << endl;

    mirror(root);

    cout << "Mirrored tree (InOrder): ";
    printInOrder(root);
    cout << endl;

    

    return 0;
}