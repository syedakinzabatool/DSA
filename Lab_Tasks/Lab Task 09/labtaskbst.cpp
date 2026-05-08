#include <iostream>
using namespace std;
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    void insert(TreeNode*& node, int a) {
        if (node == nullptr) {
            node = new TreeNode(a);
        } else if (a < node->value) {
            insert(node->left, a);
        } else {
            insert(node->right, a);
        }
    }

    bool search(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == key) {
            return true;
        } else if (key < node->value) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->value) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->value) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }
        BinarySearchTree() : root(nullptr) {}

    void insert(int a) {
        insert(root, a);
    }

    bool search(int key) {
        return search(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void display() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Display the BST
    cout << "In-order traversal: ";
    bst.display();

    // Search for a key
    int key = 40;
    cout << "Searching for " << key << ": " << (bst.search(key) ? "Found" : "Not Found") << endl;

    // Delete a key
    bst.deleteNode(20);
    cout << "In-order traversal after deleting 20: ";
    bst.display();

    bst.deleteNode(30);
    cout << "In-order traversal after deleting 30: ";
    bst.display();

    bst.deleteNode(50);
    cout << "In-order traversal after deleting 50: ";
    bst.display();

    return 0;
}