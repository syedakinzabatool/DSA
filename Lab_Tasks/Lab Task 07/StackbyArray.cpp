#include <iostream>
using namespace std;
class Stack
{
private:
    int *stack;
    int top;
    int size;

public:
    Stack(int s)
    {
        size = s;
        stack = new int[size];
        top = -1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == size - 1);
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is FULL. No Element Pushed." << endl;
        }
        else
        {
            stack[++top] = x;
            cout << x << " pushed into the stack." << endl;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is EMPTY. No Element Popped." << endl;
            return -1;
        }
        else
        {
            int poppedElement = stack[top--];
            cout << poppedElement << " popped from the stack." << endl;
            return poppedElement;
        }
    }
    int Top()
    {
        if (!isEmpty())
        {
            return stack[top];
        }
        else
        {
            cout << "Stack is EMPTY. No top element." << endl;
            return -1;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is EMPTY. No Element to Display." << endl;
        }
        else
        {
            cout << "Stack elements are: ";
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
    int search(int x)
    {
        for (int i = top; i >= 0; i--)
        {
            if (stack[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    int size, choice, value;
    cout << "Enter the size of the Stack: ";
    cin >> size;
    Stack s(size);
    do
    {
        cout << "1. Push an element onto the stack\n";
        cout << "2. Pop an element from the stack\n";
        cout << "3. Find the top element of the stack\n";
        cout << "4. Display all elements in the stack\n";
        cout << "5. Search for an element in the stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            value = s.Top();
            if (value != -1)
            {
                cout << "Top element is: " << value << endl;
            }
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Enter the element to search for: ";
            cin >> value;
            int position;
            position = s.search(value);
            if (position != -1)
            {
                cout << "Element found at position: " << position << endl;
            }
            else
            {
                cout << "Element not found in the stack." << endl;
            }
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 6);
    return 0;
}
