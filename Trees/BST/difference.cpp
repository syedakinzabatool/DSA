#include <iostream>
using namespace std;

// Define the structure for a Binary Tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to find the node with the given value and calculate the sum of its child nodes
void Calculate_Parent_to_Child_Nodes(TreeNode* root, int value) {
    if (!root) return;

    // Check if the current node matches the given value
    if (root->value == value) {
        int childSum = 0;
        if (root->left) childSum += root->left->value;
        if (root->right) childSum += root->right->value;

        cout << "Parent Node Value: " << root->value << endl;
        cout << "Sum of Child Nodes: " << childSum << endl;
        cout << "Difference (Child Sum - Parent Value): " << (childSum - root->value) << endl;
        return;
    }

    // Recur for left and right subtrees
    Calculate_Parent_to_Child_Nodes(root->left, value);
    Calculate_Parent_to_Child_Nodes(root->right, value);
}

// Helper function to build the sample tree
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    return root;
}

int main() {
    // Build the sample tree
    TreeNode* root = buildSampleTree();

    // Test the function with a specific parent node value
    int parentValue = 3;
    Calculate_Parent_to_Child_Nodes(root, parentValue);

    return 0;
}