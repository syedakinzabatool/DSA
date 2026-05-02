#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int val)
{
    if (!root)
    {
        Node *temp = new Node(val);
        return temp;
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

bool searching(Node *root, int key)
{
    if (root == nullptr) 
    {
        return false; 
    }
    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return searching(root->left, key);
    }
    else 
    {
        return searching(root->right, key);
    }
}

Node *deletion(Node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (key < root->data)
    {
        root->left = deletion(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else
    {
        // Leaf Node deletion
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        // One child
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Two children exist
        Node *child = root->left;
        Node *parent = root;
        // Approaching the rightmost node on the left side of the node to be deleted
        while (child->right)
        {
            parent = child;
            child = child->right;
        }

        if (root != parent)
        {
            parent->right = child->left;
            child->right = root->right;
            child->left = root->left;
            delete root;
            return child;
        }
        else
        {
            child->right = root->right;
            delete root;
            return child;
        }
    }
    return root;
}

void display(Node *root)
{
    if (root == nullptr)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main()
{
    //Insertion
    Node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "BST elements in sorted order: ";
    display(root);
    cout << endl;

    // Searching
    if (!searching(root, 40))
    {
        cout << "Value does not exist.\n";
    }
    else
    {
        cout << "Value exists.\n";
    }
    // Deletion
    int x;
    cout << "Enter the value to delete: ";
    cin>>x;
    root = deletion(root, x);
    cout << "After deletion:\n ";
    display(root);
    cout << endl;

    return 0;
}