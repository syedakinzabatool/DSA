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
        this->next = nullptr;
    }
};

void insertion(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
    return;
}

bool isPalindrome(Node *head)
{
    // Find the end of the first half and the start of the second half
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    Node *prev = nullptr;
    Node *curr = slow;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare the first half and the reversed second half
    Node *_2nd_portion_head = prev;
    while (head && _2nd_portion_head)
    {
        if (head->value != _2nd_portion_head->value)
        {
            return false;
        }
        else
        {
            head = head->next;
            _2nd_portion_head = _2nd_portion_head->next;
        }
    }

    return true;
}

int main()
{
    Node *head = nullptr;
    insertion(head, 1);
    insertion(head, 2);
    insertion(head, 9);
    insertion(head, 4);
    insertion(head, 9);
    insertion(head, 2);
    insertion(head, 1);


    if (!isPalindrome(head))
    {
        cout << "Not Palindrome." << endl;
    }
    else
    {
        cout << "Palindrome." << endl;
    }
    return 0;
}