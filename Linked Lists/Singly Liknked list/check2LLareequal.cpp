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
bool checkEqual(Node* head1,Node* head2){
while(head1!=NULL && head2!=NULL){
    if(head1->value!=head2->value){
        return false;
    }
    head1=head1->next;
    head2=head2->next;
}
//At this point either head1 is null,or head2 is null or both are null
return(head1==NULL && head2==NULL);

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
    cout<<"First Linked List is: "<<endl;
    Node *head1 = new Node(1);
    InsertionAtTail(head1, 2);
    InsertionAtTail(head1, 3);
    InsertionAtTail(head1, 4);
    print(head1);
    
    cout<<"Second Linked List is: "<<endl;
    Node *head2 = new Node(1);
    InsertionAtTail(head2, 2);
    InsertionAtTail(head2, 3);
    InsertionAtTail(head2, 4);
    print(head2);

    if(!checkEqual(head1,head2)){
    cout<<"\nNot Equal."<<endl;
    }
    else{
        cout<<"\nEqual."<<endl;
    }
}