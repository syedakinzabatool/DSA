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

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) //(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << slow->value << "\n";
            return true;
        }
    }
    return false;
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
    head->next->next->next->next->next = head->next->next;

    if (!isCycle(head))
    {
        cout << "There is no cycle." << endl;
    }
    else
    {
        cout << "Cycle Exists." << endl;
    }
}
