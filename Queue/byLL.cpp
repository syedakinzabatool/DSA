#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;  
    Node* rear;   

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to the queue." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return -1;
        }
        int dequeuedValue = front->value;
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
        }
        delete temp;
        cout << dequeuedValue << " dequeued from the queue." << endl;
        return dequeuedValue;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int search(int value) {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        Node* temp = front;
        int position = 1;
        while (temp != NULL) {
            if (temp->value == value) {
                return position; 
            }
            temp = temp->next;
            position++;
        }
        return -1; 
    }
};

int main() {
    Queue q; 
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.display();

    int position = q.search(30);
    if (position != -1)
        cout << "Element 30 found at position: " << position << endl;
    else
        cout << "Element not found in the queue." << endl;

    return 0;
}