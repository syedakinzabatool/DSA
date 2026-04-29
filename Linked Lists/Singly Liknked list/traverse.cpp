#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};
//void insertionAtStart(int* &head,int value){

//}
void print(Node* &head){
    Node* temp  = head;
    while(temp->next!=NULL){
        cout<<temp->value<<"->";
        temp->next=NULL;
    }
    cout<<"NULL";
}
int main()
{
    Node* head = new Node(5);
    print(head);
}