/*1. Write a C++ program that demonstrates a function where arguments are passed by value. 
Show how changes made to the parameters inside the function do not affect the original values.*/

#include <iostream>
using namespace std;
void values(int a, int b) {
    a = 10;
    b = 20;
   cout << "Inside function: a = " << a << ", b = " << b << endl;
}

int main() {
    int a = 5;
    int b = 10;

    cout << "Before function call: a = " << a << ", b = " << b << endl;

    values(a, b);

    cout << "After function call: a = " << a << ", b = " << b << endl;

    return 0;
}