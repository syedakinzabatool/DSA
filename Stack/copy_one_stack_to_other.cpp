#include <iostream>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> &original_stack)
{
    stack<int> temp_stack = original_stack; 
    stack<int> resulted_stack;
    while (!temp_stack.empty())
    {
        resulted_stack.push(temp_stack.top()); 
        temp_stack.pop(); 
    }
    return resulted_stack;
}

int main()
{
    stack<int> original_stack;
    original_stack.push(1);
    original_stack.push(2);
    original_stack.push(3);
    original_stack.push(4);

    stack<int> result = copyStack(original_stack); 
    cout << "After moving into the new Stack: " << endl;
    while (!result.empty())
    {
        cout << result.top() << " "; 
        result.pop(); 
    }
    return 0;
}