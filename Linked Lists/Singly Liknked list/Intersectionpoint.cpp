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

int get_length(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

Node *moveheadbyK(Node *head, int k)
{
    Node *temp = head;
    while (k--)
    {
        temp = temp->next;
    }
    return temp;
}

Node *intersection(Node *head1, Node *head2)
{
    // Step 1: Calculate length of both linked lists
    int length_1 = get_length(head1);
    int length_2 = get_length(head2);

    // Step 2: Find the difference b/w 2 linked list and move the linked list by k times which is greater
    if (length_1 > length_2)
    { // 1st limked list is longer
        int k = length_1 - length_2;
        head1 = moveheadbyK(head1, k);
    }
    else
    {
        int k = length_2 - length_1; 
        head2 = moveheadbyK(head2, k);
    }
    // Step 3: Compare head1 and head2 nodes
    while (head1)
    {
        if (head1->value == head2->value)
        {
            return head1; //This'll go and 'll give node in the main()
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
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
    InsertionAtTail(head1, 5);

    print(head1);
    // 1->2->3->4->5->null

    cout << "Second Linked List is: " << endl;
    Node *head2 = new Node(6);
    InsertionAtTail(head2, 7);
    head2->next->next = head1->next->next->next; //INTERSECTION NODE/POINT  [4]
    print(head2);
    // 6->7->4->5->null
    Node *intersection_point = intersection(head1, head2);
    if (intersection_point)
    {
        cout << "Intersection Point is: " << intersection_point->value << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}