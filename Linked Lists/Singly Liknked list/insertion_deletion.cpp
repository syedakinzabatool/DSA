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
void InsertionAtStart(Node *&head, int value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
    return;
}
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
void InsertionAtPosition(Node *&head, int position, int value)
{
    Node *temp = head;
    int current_position = 0;
    if (position == 0)
    {
        InsertionAtStart(head, value);
        return;
    }
    while (temp != NULL && current_position != position)
    {
        temp = temp->next;
        current_position++;
    }
    if (temp == NULL)
    {
        InsertionAtTail(head, value);
        return;
    }
    else
    {
        Node *new_node = new Node(value);

        new_node->next = temp->next;
        temp->next = new_node;
        return;
    }
}
void DeletionAtStart(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty:" << endl;
        return;
    }
    Node *temp = head;

    head = head->next;
    free(temp);
    return;
}
void DeletionAtTail(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *to_delete = temp->next;
    temp->next = nullptr;
    free(to_delete);
}
/*while (temp != NULL): This line means that the loop will keep executing as long as temp points to a valid node or memory location.
If temp becomes NULL, the loop will stop.*/
void DeletionAtPosition(Node *&head, int position)
{
    Node *temp = head;
    int current_position = 0;
    if (position == 0)
    {
        DeletionAtStart(head);
        return;
    }
    while (current_position != position - 1)
    {
        temp = temp->next;
        current_position++;
    }
    //Now the node is pointing to node at pos-1

        Node *to_delete = temp->next; //node to be deleted
        temp->next = temp->next->next;
        delete to_delete;
        return;
    }

void updationAtPosition(Node* &head, int position, int value)
{
    Node *temp = head;
    int current_position = 0;

    while(current_position != position)
    {
        temp = temp->next;
        current_position++;
    }
    temp->value = value;
    return;
}
void deletionatalternateposition(Node* &head)
{
    
    Node *curr_node = head;
    while (curr_node!= NULL && curr_node->next != NULL)
    {
        Node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
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
    Node *head = new Node(9);
    cout << "Insertion: " << endl;
    InsertionAtStart(head, 7);
    print(head);
    InsertionAtStart(head,5);
    print(head);

    InsertionAtTail(head, 11);
    print(head);

    InsertionAtPosition(head, 2, 3);
    print(head);

    cout <<"Updation:\n ";
    updationAtPosition(head, 2, 25);
    print(head);

    cout <<"Deletion: " << endl;
    DeletionAtStart(head);
    print(head);

    DeletionAtTail(head);
    print(head);

    DeletionAtPosition(head, 2);
    print(head);

    cout << "Deletion At Alternative Position:\n ";
    InsertionAtStart(head, 50);
    print(head);
    InsertionAtStart(head, 100);
    print(head);
    deletionatalternateposition(head);
    print(head);
}