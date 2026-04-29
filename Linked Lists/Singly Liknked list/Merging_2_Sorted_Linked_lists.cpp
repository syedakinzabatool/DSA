// Given 2 sorted linked lists,merge them into 1 singly linked list such that the resulting list is also sorted(not creating the new LL)
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

Node *Two_Sorted_Merged_Linked_List(Node *head1, Node *head2)
{
    Node *Dummy_node = new Node(-1);

    Node *LL_1 = head1;
    Node *LL_2 = head2;
    Node *ptr = Dummy_node;

    while (LL_1 && LL_2)
    {
        if (LL_1->value < LL_2->value)
        {
            ptr->next = LL_1;
            LL_1 = LL_1->next;
        }
        else
        {
            ptr->next = LL_2;
            LL_2 = LL_2->next;
        }

        ptr = ptr->next;
    }
    if (LL_1) // means to say that it still has nodes (not empty) loop will run untill linked list has nodes.
    {
        ptr->next = LL_1;
    }
    else
    {
        ptr->next = LL_2;
    }
    Node *temp = Dummy_node->next;
    delete Dummy_node;
    return temp;
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
    cout << "First Linked List is: " << endl;
    Node *head1 = new Node(1);
    InsertionAtTail(head1, 2);
    InsertionAtTail(head1, 3);
    InsertionAtTail(head1, 4);
    print(head1);

    cout << "Second Linked List is: " << endl;
    Node *head2 = new Node(6);
    InsertionAtTail(head2, 7);

    print(head2);
    cout << "Two Sorted Linked Lists after Merging are: " << endl;
    Node *merged_linked_list = Two_Sorted_Merged_Linked_List(head1, head2);
    print(merged_linked_list); // Print the merged list
}