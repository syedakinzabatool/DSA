#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Class for Linked List
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the list
    void insert(int value) {
        if (head == nullptr) {
            head = new Node(value);
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    // Function to remove duplicates from sorted linked list
    void removeDuplicate() {
    Node *current = head;
    Node *temp = head->next;

    while (temp != nullptr) {
        if (current->data == temp->data) {
            Node *nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
            current->next = temp; // Link current to the new temp
        } else {
            current = current->next;
            temp = temp->next;
        }
    }
}


    // Function to print the linked list
    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free all nodes
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    // Insert nodes in sorted order with duplicates
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(3);
    list.insert(3);
    list.insert(3);
    list.insert(4);

    cout << "Original list: ";
    list.printList();

    // Remove duplicates
    list.removeDuplicate();

    cout << "List after removing duplicates: ";
    list.printList();

    return 0;
}