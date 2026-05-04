#include <iostream>
using namespace std;

int main() {
    const int y = 10;
    const int *ptr = &y;

    // *ptr = 20; // Error: Cannot modify value through a pointer to a const

    cout << "Value of y using pointer to const: " << *ptr << endl;

    return 0;
}
