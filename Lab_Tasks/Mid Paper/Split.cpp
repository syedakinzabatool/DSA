#include <iostream>

struct Node {
    int value;
    Node* prv;
    Node* next;

    Node(int val) : value(val), prv(nullptr), next(nullptr) {}
};

void splitList(Node* tail, int n, Node*& listOne, Node*& listTwo) {
    if (tail == nullptr || n < 2) {
        listOne = tail;
        listTwo = nullptr;
        return;
    }

    Node* head = tail->next;  // Since it's circular, tail->next is the head.
    Node* mid = head;

    // Traverse to the midpoint
    int midPos = (n + 1) / 2;
    for (int i = 1; i < midPos; ++i) {
        mid = mid->next;
    }

    // Set up listOne and listTwo heads
    listOne = head;
    listTwo = mid->next;

    // Break the list into two halves
    mid->next = listOne;           // End the first list
    listOne->prv = mid;             // Make it circular

    tail->next = listTwo;           // End the second list
    listTwo->prv = tail;            // Make it circular
}

// Helper function to print a circular doubly linked list
void printList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        std::cout << temp->value << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

// Function to create a circular doubly linked list with n nodes
Node* createCircularDoublyList(int n) {
    if (n <= 0) return nullptr;

    Node* head = new Node(1);
    Node* last = head;

    for (int i = 2; i <= n; ++i) {
        Node* newNode = new Node(i);
        last->next = newNode;
        newNode->prv = last;
        last = newNode;
    }

    // Connect last node to head to make it circular
    last->next = head;
    head->prv = last;

    return last;  // Return the tail node
}

int main() {
    int n = 6;  // You can change n to test with different values
    Node* tail = createCircularDoublyList(n);

    Node* listOne = nullptr;
    Node* listTwo = nullptr;

    splitList(tail, n, listOne, listTwo);

    std::cout << "List One: ";
    printList(listOne);

    std::cout << "List Two: ";
    printList(listTwo);

    return 0;
}
