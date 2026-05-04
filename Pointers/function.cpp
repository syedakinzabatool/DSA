#include <iostream>
using namespace std;
/*In this code, ptr is a pointer to a function. Specifically, 
it's a pointer to a function that takes two int arguments and returns an int.*/
int add(int a, int b) {
    return a + b;
}

int main() {
    int (*ptr)(int, int) = add;

    cout << "Sum: " << ptr(5, 7) << endl;

    return 0;
}
