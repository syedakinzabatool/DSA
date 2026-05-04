#include <iostream>
using namespace std;

int main() {
    int *ptr = new int;  // Dynamic memory allocation

    *ptr = 10;
    cout << "Value at dynamically allocated memory: " << *ptr << endl;

    delete ptr;  // Deallocate memory

    return 0;
}
