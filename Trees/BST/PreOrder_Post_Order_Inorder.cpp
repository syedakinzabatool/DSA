#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to create a new node
    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";       // Visit root node
    preorderTraversal(root->left);    // Visit left subtree
    preorderTraversal(root->right);   // Visit right subtree
}

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);     // Visit left subtree
    cout << root->data << " ";        // Visit root node
    inorderTraversal(root->right);    // Visit right subtree
}

// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    postorderTraversal(root->left);   // Visit left subtree
    postorderTraversal(root->right);  // Visit right subtree
    cout << root->data << " ";        // Visit root node
}

// Function to insert nodes in the tree
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    
    // Insert nodes into the tree
    
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 15);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
