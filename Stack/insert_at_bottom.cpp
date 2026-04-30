#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &original_stack, int value) {
    // Create a temporary stack to hold the elements
    stack<int> temp;

    // Move all elements from the original stack to the temporary stack
    while (!original_stack.empty()) {
        temp.push(original_stack.top());
        original_stack.pop();
    }

    // Push the new value at the bottom of the original stack
    original_stack.push(value);

    // Move all elements back from the temporary stack to the original stack
    while (!temp.empty()) {
        original_stack.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> original_stack;
    original_stack.push(1);
    original_stack.push(2);
    original_stack.push(3);
    original_stack.push(4);

    // Insert 100 at the bottom of the stack
    insertAtBottom(original_stack, 100);
    
    cout << "After adding element at the bottom: " << endl;

    // Print the stack
    while (!original_stack.empty()) {
        cout << original_stack.top() << " ";
        original_stack.pop();
    }
    return 0;
}