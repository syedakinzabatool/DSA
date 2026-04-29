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
Node *recursion(Node *&head)
{
    // Base Case: If the list is empty or has only one node, return the head
    if (head == nullptr || head->next == nullptr)
        return head;

    // Recursive Case:
    // Recursively call the function on the rest of the list (excluding the current head)
    Node *new_head = recursion(head->next);

    // After the recursive call returns, 'new_head' is the head of the reversed sublist
    // Now, we need to adjust the links:

    // Make the next node point back to the current node
    head->next->next = head;

    // Set the current node's next to null (it will be the last node in the reversed list)
    head->next = nullptr;

    // Return the new head (which is the last node of the original list)
    return new_head;
}
Node *reverse(Node *&head)
{
    Node *curr_node = head;  // Current node, starting from the head
    Node *prev = nullptr;    // Previous node, initially null
    
    while (curr_node != nullptr)
    {
        // Store the next node before we change curr_node's next
        Node *next = curr_node->next;
        
        // Reverse the link: make current node point to the previous node
        curr_node->next = prev;
        
        // Move prev and curr_node one step forward for the next iteration
        prev = curr_node;
        curr_node = next;
    }
    
    // At this point, prev is pointing to the last node (new head)
    Node *new_head = prev;
    
    // Return the new head of the reversed list
    return new_head;
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
    cout << "Reverse: " << endl;
    head =recursion(head);
    print(head);
}