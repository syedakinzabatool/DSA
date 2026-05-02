#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode *root;

    BinaryTree() : root(nullptr) {}
    int countNodes(TreeNode *node) {
        if (!node)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void buildAndCount() {
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        cout << "Total nodes in the tree: " << countNodes(root) << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.buildAndCount();
    return 0;
}