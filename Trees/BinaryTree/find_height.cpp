#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node *root)
{
    if (root == nullptr)
        return 0; // Empty tree has height 0

    return 1 + max(height(root->left), height(root->right)); // 1 for the current node
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    int treeHeight = height(root);
    cout << "Height of the binary tree: " << treeHeight << endl; // Output: 3
    return 0;
}