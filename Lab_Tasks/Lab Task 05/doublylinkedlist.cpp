/*Question # 1:
Implement the Double LinkedList code with following Functions:
•	InsertAtFront (int Value): Insert a node with the given value at the front of the linked list.
•	RemoveFromFront (): Remove the node at the front of the linked list.
•	Display (): Display the data of linked list.
•	Display_Reverse (): Display the data of linkedList in the reverse order.
•	SearchValue (int key): Search for a node with the given value in the linked list.
•	InsertAtTail (int Value): Insert a node with the given value at the Tail of the linked list.
•	RemoveFromTail (): Remove the node at the Tail of the linked list.
•	RemoveSpecificValue (int Value): Search for a specific value and remove it. */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void RemoveFromFront() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Display_Reverse() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    bool SearchValue(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void InsertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void RemoveFromTail() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void RemoveSpecificValue(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found" << endl;
    }
};

int main() {
    DoubleLinkedList dll;

    dll.InsertAtFront(10);
    dll.InsertAtFront(20);
    dll.InsertAtFront(30);
    dll.InsertAtTail(40);
    dll.InsertAtTail(50);

    dll.Display(); // Output: 30 20 10 40 50
    dll.Display_Reverse(); // Output: 50 40 10 20 30

    dll.RemoveFromFront();
    dll.Display(); // Output: 20 10 40 50

    dll.RemoveFromTail();
    dll.Display(); // Output: 20 10 40

    dll.SearchValue(10) ? cout << "Value found" << endl : cout << "Value not found" << endl; // Output: Value found
    dll.SearchValue(60) ? cout << "Value found" << endl : cout << "Value not found" << endl; // Output: Value not found

    dll.RemoveSpecificValue(10);
    dll.Display(); // Output: 20 40

    return 0;
}