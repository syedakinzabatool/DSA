#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10, c = 15;
    int *arr[] = {&a, &b, &c};

    cout << "Values using array of pointers: ";
    for (int i = 0; i < 3; ++i) {
        cout << *arr[i] << " ";
    }
    cout << endl;

    return 0;
}
