// Given the head of the linked list,remove the Kth node of the linked list from the end.
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

// Assuming k is always less than length of linked list
void remove_Kth_Node_from_End(Node *head, int k)
{
    Node *ptr1 = head;
    Node *ptr2 = head;

    // Move ptr2 by K steps ahead
    int steps = k;
    while (steps--)
    { // untill step became 0
        ptr2 = ptr2->next;
    }
    if (ptr2 == nullptr)
    { // If kth node is equal to the length of the linked list
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // Now ptr2 is k steps ahead pf ptr1
    // when ptr2 is at null(end of the list ) ptr1 will be at the kth node
    while (ptr2->next != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // Now ptr1 ia pointing to the node before kth node from end
    // node to be deleted is ptr->next
    Node *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;
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
    InsertionAtTail(head, 3);
    InsertionAtTail(head, 4);
    InsertionAtTail(head, 5);
    print(head);

    cout << "Updated Linked List is: " << endl;
    remove_Kth_Node_from_End(head, 3);
    print(head);
    return 0;
}