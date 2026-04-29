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
    if (head == NULL)
    {
        head = new Node(value);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *new_node = new Node(value);

    temp->next = new_node;
    new_node->next = NULL;
}

Node *Swapping_adjacent_nodes(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // recursive case
    Node *secondNode = head->next;
    head->next = Swapping_adjacent_nodes(secondNode->next);
    secondNode->next = head;
    return secondNode;
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
    Node *head = new Node(1);
    InsertionAtTail(head, 2);
    InsertionAtTail(head, 3);
    InsertionAtTail(head, 4);
    InsertionAtTail(head, 5);
    InsertionAtTail(head, 6);
    print(head);
    cout << "After swapping adjacent nodes: " << endl;
    Node *swap = Swapping_adjacent_nodes(head);
    print(swap);
    return 0;
}