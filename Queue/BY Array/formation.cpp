#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int n)
    {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear == size - 1);
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full." << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return -1; // Return a sentinel value to indicate empty
        }
        else if (rear == front)
        {
            x = arr[front];
            rear = -1;
            front = -1;
        }
        else
        {
            x = arr[front];
            front++;
        }
        return x;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main()
{
    Queue obj(5);
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
        obj.enqueue(5);

    cout << "Elements are: ";
    obj.display();
    return 0;
}