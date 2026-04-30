#include <iostream>
#include <stack>
using namespace std;

stack<int> insertAtPosition(stack<int> &st, int value, int position) {
    if (position < 0) {
        cout << "Invalid position" << endl;
        return st;
    }

    stack<int> resulted_Stack;
    int count = 0;

    // Move elements from original stack to resulted stack until we reach the desired position
    while (!st.empty() && count < position) {
        resulted_Stack.push(st.top());
        st.pop();
        count++;
    }
    // Insert the new element at the desired position
    st.push(value);

    // Move elements back from resulting stack to original stack
    while (!resulted_Stack.empty()) {
        st.push(resulted_Stack.top());
        resulted_Stack.pop();
    }

    return st;
}

int main() {
    stack<int> original_stack;
    original_stack.push(1);
    original_stack.push(2);
    original_stack.push(3);
    original_stack.push(4);

    stack<int> result = insertAtPosition(original_stack, 100, 2);
    cout << "After adding element at position 2: " << endl;

    while (!result.empty()) {
        cout<< result.top()<<" ";
        result.pop();
    }
    return 0;
}