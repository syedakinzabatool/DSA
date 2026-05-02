#include<iostream>
using namespace std;
//self-balancing binary search tree
class node {
public:
    int data, height;
    node* left, * right;
    node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getheight(node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int getbalance(node* root) {
    if (root == NULL){
	 return 0;
	 }
    return getheight(root->left) - getheight(root->right);
}

// Right Rotation
node* rightrotation(node* root) {
    node* child = root->left;
    node* childright = child->right;
    child->right = root;
    root->left = childright;
    
    // Update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    
    return child;
}

// Left Rotation
node* leftrotation(node* root) {
    node* child = root->right; 
    node* childleft = child->left;
    child->left = root;
    root->right = childleft;
    
    // Update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    
    return child;
}

node* insert(node* root, int key) {
    if (!root) {
        return new node(key);
    }
    
    if (key < root->data) { // Left subtree
        root->left = insert(root->left, key);
    }
    else if (key > root->data) { // Right subtree
        root->right = insert(root->right, key);
    }
    else { // Duplicate values are not allowed in AVL
        return root;
    }
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Check balance factor
    int balance = getbalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->data) {
        return rightrotation(root);
    }

    // Right Right Case
    if (balance < -1 && key > root->right->data) {
        return leftrotation(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}