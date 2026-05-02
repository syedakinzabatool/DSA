#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int value;
    Node *left, *right;
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
    }
    };

Node* formation(Node* & root){
   cout << "Enter value: ";
    int value;
    cin >> value;
    root = new Node(value);
    if (value == -1)
    {
        return nullptr;
    }
    cout << "Enter value for left: " << endl;
    root->left = formation(root->left);
    cout << "Enter value for right: " << endl;
    root->right = formation(root->right);
    return root;
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> value << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
int main(){
Node* root=nullptr;
formation(root);
cout << "Printing the level order tracersal output " << endl;
levelOrderTraversal(root);
}