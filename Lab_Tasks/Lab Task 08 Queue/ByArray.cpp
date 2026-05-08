#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, maxSize;
    int* queue;

public:
    Queue(int size) {
        maxSize = size;
        queue = new int[maxSize];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void Enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % maxSize;
        queue[rear] = value;
    }

    int Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return an invalid value
        }
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % maxSize) {
            cout << queue[i] << " ";
        }
        cout << queue[rear] << endl;
    }

    int search(int value) {
        if (isEmpty()) {
            return -1; // Not found
        }
        for (int i = front; i != rear; i = (i + 1) % maxSize) {
            if (queue[i] == value) {
                return i; // Return the position
            }
        }
        if (queue[rear] == value) {
            return rear; // Check the rear element
        }
        return -1; // Not found
    }
};

int main() {
    Queue q(5); // Create a Queue of size 5

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.display();

    cout << "Dequeued: " << q.Dequeue() << endl;
    q.display();

    cout << "Searching for 30: Position " << q.search(30) << endl;
    cout << "Searching for 50: Position " << q.search(50) << endl;

    return 0;
}