#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int value;
    Node *prev;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class Doubly_Linked_List
{
public:
    Node *head;
    Node *tail;
    Doubly_Linked_List()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertionAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse()
    {
        Node *currPtr = head;
        while (currPtr)
        {
            Node *nextPtr = currPtr->next;
            currPtr->next = currPtr->prev;
            currPtr->prev = currPtr;
            currPtr = nextPtr;
        }
        swap(head, tail);
        return;
    }
    void deleteSameNeighbourNodes()
    {
        Node *currNode = tail->prev; // second last node
        while (currNode != head)
        {
            Node *prevNode = currNode->prev;
            Node *nextNode = currNode->next;
            if (prevNode->value == nextNode->value)
            {
                // i need to delete the current node
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                free(currNode);
            }
            currNode = prevNode;
        }
    }
};
bool isPalindrome(Doubly_Linked_List dll)
{
    Node *headPtr = dll.head;
    Node *tailPtr = dll.tail;
    while (headPtr != tailPtr && headPtr->prev != tailPtr)
    {
        if (headPtr->value != tailPtr->value)
        {
            return false;
        }
        else
        {
            headPtr = headPtr->next;
            tailPtr = tailPtr->prev;
        }
    }
    return true;
}

int main()
{

    Doubly_Linked_List dll;
    dll.insertionAtTail(1);
    dll.insertionAtTail(1);
    dll.insertionAtTail(1);
    dll.insertionAtTail(1);
    dll.insertionAtTail(2);
    dll.insertionAtTail(1);
    dll.display();

    // cout << "Reverse: " << endl;
    // dll.reverse();
    // dll.display();

    // cout << "Check Palindrome: " << endl;
    // cout << (isPalindrome(dll) ? "True" : "False") << endl;

    dll.deleteSameNeighbourNodes();
    dll.display();
    return 0;
}
