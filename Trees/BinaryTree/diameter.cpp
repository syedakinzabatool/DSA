//Calculate  the diameter of binary tree
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;

        // Recursively find the height of left and right subtrees
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        // Update the diameter if the path through the current node is larger
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
};

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    cout << "Diameter of the binary tree: " << solution.diameterOfBinaryTree(root) << endl;

    // Clean up memory (not shown for brevity)
    return 0;
}