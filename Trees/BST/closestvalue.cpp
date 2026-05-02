#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a key into the BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    return root;
}

// Function to find the closest value in BST
int findClosestValue(TreeNode* root, double target) {
    int closest = root->val;

    while (root) {
        if (abs(root->val - target) < abs(closest - target) ||
            (abs(root->val - target) == abs(closest - target) && root->val < closest)) {
            closest = root->val;
        }

        if (target < root->val)
            root = root->left;
        else
            root = root->right;
    }

    return closest;
}

// Function to display the BST structure for clarity
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    int keys[] = {4, 2, 7, 3, 1, 9, 12, 17, 3, 9, 6, 15, 0, 3};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    double target = 3.714286;
    cout << "Closest value to " << target << " is: " << findClosestValue(root, target) << endl;

    return 0;
}
