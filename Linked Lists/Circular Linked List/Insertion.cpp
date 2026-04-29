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
class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = nullptr;
    }

    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
    }

    void insertionAtStart(int value)
    {
        Node *newNode = new Node(value);

        // If empty
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; //'ll make it circular bcz it'll point toward itself
            return;
        }
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        // Now tail is pointing at the last node
        tail->next = newNode;

        newNode->next = head;
        head = newNode;
        return;
    }

    void insertionAtTail(int value)
    {
        Node *newNode = new Node(value);
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }
    void deletionAtStart()
    {
        Node *tail = head;
        while (tail->next!= head)
        {
            tail = tail->next;
        }
        tail->next=head->next;
        free(head);
        head=head->next;
       
    }
     void deletionAtTail()
    {
        Node *tail = head;
        while (tail->next->next != head)
        {
            tail = tail->next;
        }
        Node* temp=tail->next;
        tail->next=head;
        free(temp);

    }
};
int main()
{
    CircularLinkedList cll;
    cll.insertionAtStart(3);
    // cll.display();
    cll.insertionAtStart(1);

    cout << "\nInsertion at tail: " << endl;
    cll.insertionAtTail(5);
    cll.display();
    cout<<"\nDeletion at tail:"<<endl;
    cll.deletionAtTail();
    cll.display();
    cout<<endl;
    cll.deletionAtStart();
    cll.display();

}