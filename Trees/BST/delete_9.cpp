#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a key into the BST
TreeNode *insert(TreeNode *root, int key)
{
    if (!root)
        return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    return root;
}
// Function to find the minimum value node in the BST
TreeNode *findMin(TreeNode *root)
{
    while (root->left)
        root = root->left;
    return root;
}

// Function to delete a node from the BST
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with only one child or no child
        if (!root->left)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        TreeNode *temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}
// Function to display the BST structure for clarity
void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main()
{
    TreeNode *root = NULL;
    int keys[] = {4, 2, 7, 3, 1, 9, 12, 17, 3, 9, 6, 15, 0, 3};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, keys[i]);
    }

    cout << "Inorder Traversal of BST before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 9);

    cout << "Inorder Traversal of BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
