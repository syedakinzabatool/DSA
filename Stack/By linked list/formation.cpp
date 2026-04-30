#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* head;
    int capacity;
    int curr_size;

public:
    Stack(int c) {
        this->capacity = c;   // what size user'll give of it's own choice
        this->curr_size = 0;  // Initially
        this->head = nullptr; // Initially
    }

    bool isEmpty() {
        return head == nullptr;
    }

    bool isFull() {
        return curr_size == capacity;
    }

    void push(int value) {
        //Insertion at head
        if (isFull()) {
            cout << " OVERFLOW!!! There is no empty space.\n";
            return;
        }
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
        curr_size++;
        return;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow!! Stack is empty.";
            return INT_MIN;
        }
        //Deletion at head
        Node* temp = head;
        head = head->next;
        int value_of_popped_Node = temp->value;
        delete temp;
        curr_size--;
        return value_of_popped_Node;
    }

    int size() {
        return curr_size;
    }

    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty!!";
            return INT_MIN;
        }

        return head->value;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    cout << "Size:" << s.size() << endl;
    cout << s.pop() << endl;
    cout<<s.Top();
    s.pop();
    s.pop();
    cout<<"\nSize:" <<s.size()<<endl;
    cout<<"Top:"<<s.Top()<<endl;
    return 0;
}