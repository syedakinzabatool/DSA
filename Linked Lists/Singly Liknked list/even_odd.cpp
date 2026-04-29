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

Node *Even_Odd_indices_together(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *evenHead = head->next;
    Node *even = head->next;
    Node *odd = head;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    // linking odd indices to the even head
    odd->next = evenHead;
    return head;
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

    Node *indices = Even_Odd_indices_together(head);
    print(indices);
    return 0;
}