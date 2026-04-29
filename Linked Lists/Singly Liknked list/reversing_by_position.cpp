// Given the head of the linked list, reverse the nodes of the linked list K at a time ,and return the modified list.
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

Node *reversingkll(Node *&head, int k)
{
    Node *curr_node = head;
    Node *prev = nullptr;

    int counter = 0; // for counting first k nodes
    while (curr_node != nullptr && counter < k)
    {
        Node *next = curr_node->next;
        curr_node->next = prev;
        prev = curr_node;
        curr_node = next;
        counter++;
    }
    if (curr_node != nullptr)
    {
        Node *new_head = reversingkll(curr_node, k);
        head->next = new_head;
    }

    return prev;
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
    cout << "Reversing K nodes : " << endl;
    head = reversingkll(head, 2);
    print(head);
}