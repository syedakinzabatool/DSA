#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty. Cannot pop element." << endl;
            return -1;
        }
        int value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return top->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node *temp = top;
        cout << "Stack elements are: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int search(int value)
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        Node *temp = top;
        int position = 1;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }
};
int main()
{
    Stack stack;
    int choice, value;
    do
    {
        cout << "1. Push element onto the stack" << endl;
        cout << "2. Pop element from the stack" << endl;
        cout << "3. Display stack elements" << endl;
        cout << "4. Search for an element in the stack" << endl;
        cout << "5. Check if stack is empty" << endl;
        cout << "6. Display top element" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to push: ";
            cin >> value;
            stack.push(value);
            cout << "Element pushed onto stack." << endl;
            break;
        case 2:
            value = stack.pop();
            if (value != -1)
            {
                cout << "Popped element: " << value << endl;
            }
            break;
        case 3:
            stack.display();
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> value;
            int position;
            position = stack.search(value);
            if (position != -1)
            {
                cout << "Element found at position: " << position << endl;
            }
            else
            {
                cout << "Element not found in the stack." << endl;
            }
            break;
        case 5:
            if (stack.isEmpty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Stack is not empty." << endl;
            }
            break;
        case 6:
            value = stack.Top();
            if (value != -1)
            {
                cout << "Top element: " << value << endl;
            }
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
