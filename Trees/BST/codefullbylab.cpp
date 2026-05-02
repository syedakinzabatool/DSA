#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        Node* new_node = new Node(val);
        if (root == NULL) {
            root = new_node;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (val < parent->data) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }

    void search(int key) {
        if (root == NULL) {
            return;
        }

        Node* current = root;
        int check = 0;
        while (current != NULL) {
            if (current->data == key) {
                cout << "Value " << key << " is present in the tree" << endl;
                check++;
                break; // Stop searching after finding the key
            }

            if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (check == 0) {
            cout << "Value " << key << " not found in the tree" << endl;
        }
    }

    int remove(int val) {
        Node* current = root;
        Node* parent = NULL;

        while (current != NULL && current->data != val) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (current == NULL) {
            cout << "Node with value " << val << " not found in bst." << endl;
            return -1;
        }

  int deletedValue = current->data;
//Case:01     Node to be deleted have zero or one child node
            if(current->left==NULL || current->right==NULL){
                Node* child = NULL;
                if(current->left!=NULL){
                    child=current->left;
                }
                else{
                    child = current->right;
                }

                if(parent == NULL){
                    root = child;
                }
                else if(parent->left == current){
                    parent->left=child;
                }
                else{
                    parent->right = child;
                }

                delete current;
            }

            else{
                Node* successor = current->right;
                parent = current;
                while(successor->left!=NULL){
                    parent = successor;
                    successor = successor->left;
                }

                current->data = successor->data;

                if(parent->left == successor){
                    parent->left = successor->right;
                }
                else{
                    parent->right = successor->right;
                }
                delete successor;
            }

            return deletedValue;    
        }

};



int main() { // Corrected 'mian' to 'main'
    BST tree1;
    tree1.insert(10);
    tree1.insert(20);
    tree1.insert(30);
    tree1.insert(40);

    tree1.search(20); // Search for a value in the tree
    tree1.search(25); // Search for a value not in the tree

    tree1.remove(20); // Remove a node
    tree1.search(20); // Search for the removed node

    return 0;
}