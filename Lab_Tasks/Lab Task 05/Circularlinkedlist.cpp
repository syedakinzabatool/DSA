/*Circular Linked list
Implement the Circular LinkedList code with following Functions:
•	InsertAtFront (int Value): Insert a node with the given value at the front of the linked list.
•	RemoveFromFront (): Remove the node at the front of the linked list.
•	Display (): Display the data of linked list.
•	FindMiddleNode (): Find and return the value of the middle node in the linked list. If the list has an even number of nodes, return the second middle node.
•	RemoveSpecificValue (int Value): Search for a specific value and remove it.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void RemoveFromFront() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void Display() {
        Node* temp = head;
        while (true) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head) {
                break;
            }
        }
        cout << endl;
    }

    int FindMiddleNode() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void RemoveSpecificValue(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != head && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next != head) {
            Node* nodeToRemove = temp->next;
            temp->next = temp->next->next;
            delete nodeToRemove;
        } else {
            cout << "Value not found" << endl;
        }
    }
};

int main() {
    CircularLinkedList cll;

    cll.InsertAtFront(10);
    cll.InsertAtFront(20);
    cll.InsertAtFront(30);
    cll.InsertAtFront(40);
    cll.InsertAtFront(50);

    cll.Display(); // Output: 50 40 30 20 10
    cout << "Middle node: " << cll.FindMiddleNode() << endl; // Output: Middle node: 30

    cll.RemoveFromFront();
    cll.Display(); // Output: 40 30 20 10

    cll.RemoveSpecificValue(20);
    cll.Display(); // Output: 40 30 10

    return 0;
}
