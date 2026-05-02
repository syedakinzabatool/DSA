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

int getheight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(getheight(root->left), getheight(root->right));
}

int getbalance(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

bool checkBalance(Node *root)
{
    if (root == NULL)
    {
        return true; 
    }

    int balance = getbalance(root);
    if (balance < -1 || balance > 1)
    {
        return false; 
    }

    return checkBalance(root->left) && checkBalance(root->right);
}

void printInOrder(Node *root)
{
    if (!root)
        return;
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

    if (checkBalance(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}