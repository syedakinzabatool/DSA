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

    void insertionAtStart(int value)
    {
        Node *new_node = new Node(value);

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    void insertionAtTail(int value)
    {
        Node *new_node = new Node(value);

        // Check empty or not
        if (head == nullptr)
        { // can also write that tail==nullptr in cond. bcz both'll work smae
            head = new_node;
            tail = new_node;
            return;
        }
        // As tail is given to us so why not it's better to do with O(1)
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
        
    }

    void insertionAtPosition(int position, int value)
    {

        if (position == 0)
        {
            insertionAtStart(value);
            return;
        }

        Node *new_node = new Node(value);
        int count = 1;
        Node *temp = head;

        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        // This is standing now at the (k-1)th position
        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;
    }
    void deletionAtStart()
    {
        Node *temp = head;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        else
            head->prev = nullptr;
        free(temp);
        return;
    }
    void deletionAtTail()
    {
        Node *temp = tail;
        tail->prev->next = nullptr;
        if (tail == nullptr)
        {
            head = nullptr;
        }
        else
            tail = tail->prev;
        free(temp);
        return;
    }
    void deletionAtPosition(int position)
    {
        // Assuming that k is less than or equal to the length of the dll
        int count = 1;
        Node *temp = head;
        while (count < position)
        {
            temp = temp->next;
            count++;
        }
        // This is standing now at the node of the desired position
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
};
int main()
{
    Node *new_node = new Node(9);
    Doubly_Linked_List dll;
    dll.head = new_node;
    dll.tail = new_node;

    dll.insertionAtStart(7);
    dll.insertionAtStart(5);
    dll.display();
    cout << "Insertion at tail: " << endl;
    dll.insertionAtTail(11);
    dll.insertionAtTail(13);

    dll.display();
    cout << "Insertion at an arbitrary position: " << endl;
    dll.insertionAtPosition(4, 15);
    dll.display();
    cout << "Deletion: " << endl;
    dll.deletionAtStart();
    dll.display();
    dll.deletionAtTail();
    dll.display();
    cout << "Deletion at an arbitrary position: " << endl;
    dll.deletionAtPosition(2);
    dll.display();
}