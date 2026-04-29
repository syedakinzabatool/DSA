//Print binary search
#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter the size of Array:";
    cin >> x;
    int A[x];

    for (int i = 0; i < x; i++) {
        cout << "Enter the Elements of Array: ";
        cin >> A[i];
    }

    // Sorting the array (using selection sorting technique)
    int sortIterations = 0;
    for (int i = 0; i < x - 1; i++) {
        for (int j = i + 1; j < x; j++) {
            sortIterations++; // Increment iteration counter
            if (A[j] < A[i]) {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }

    cout << "The elements in sorted form are:" << endl;
    for (int i = 0; i < x; i++) {
        cout << A[i] << endl;
    }
    cout << endl;

    // Searching for a number
    int low, high, var, mid, key;
    cout << "Enter a number you want to search: ";
    cin >> key;

    low = 0;
    high = x - 1;
    var = -1;
    int searchIterations = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        searchIterations++; // Increment iteration counter
        if (A[mid] == key) {
            var = mid;
            break; // Exit the loop if the element is found
        } else if (key < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (var == -1) {
        cout << "Not found.";
    } else {
        cout << "Found at index " << var<<endl;
    }

    cout << "Number of iterations for sorting: " << sortIterations << endl;
    cout << "Number of iterations for searching: " << searchIterations << endl;

    return 0;
}