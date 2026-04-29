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
        this->next = NULL;
    }
};
void InsertionAtTail(Node *&head, int value)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *new_node = new Node(value);

    temp->next = new_node;
    new_node->next = NULL;
}

void duplicates(Node* &head){
Node* curr_node=head;
while(curr_node!=NULL && curr_node->next!=NULL){
     if(curr_node->value==curr_node->next->value){
            Node* temp =curr_node->next;
            curr_node->next = curr_node->next->next; // Update the next pointer
           delete (temp); // Use delete instead of free
        }
    else{
        curr_node=curr_node->next;
    }
}
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main()
{
    cout << "Insertion: " << endl;
    Node *head = new Node(1);
    InsertionAtTail(head, 2);
    InsertionAtTail(head, 2);
    InsertionAtTail(head, 3);
    InsertionAtTail(head, 3);
    print(head);
    cout<<"After removing duplicates: "<<endl;
    duplicates(head);
    print(head);
    
   
}