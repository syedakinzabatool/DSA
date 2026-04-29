#include <iostream>
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
};
int main()
{
    Node *new_node = new Node(5);
    Doubly_Linked_List dll;
    dll.head = new_node;
    dll.tail = new_node;
    cout << dll.head->value << " ";
}