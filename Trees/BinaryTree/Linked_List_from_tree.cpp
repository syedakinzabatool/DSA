#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *linked_list_conversion(Node *root)
{
    if (!root)
    {
        return nullptr;
    }
    else
    {
        while (root)
        {
            if (!root->left)
            {
                root = root->right;
            }
            else
            {
                Node *curr = root->left;
                while (curr->right)
                {
                    curr = curr->right;
                }
                curr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    cout << "Tree:" << endl;
    inorder(root);
    cout << "\nLinked list:" << endl;
    Node *linkedListHead = linked_list_conversion(root);
    inorder(root);
    
    return 0;
}