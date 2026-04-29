#include <iostream>
using namespace std;

int main() {
    int x;

    // Prompt the user to enter the size and elements of an array
    cout << "Enter the size and elements of an Array : ";
    cin >> x;

    cout << "_" << endl;

    // Declare an array A of size x to store the elements
    int A[x];

    // Input the elements of the array
    for (int i = 0; i < x; i++) {
        cout << "Enter Number : ";
        cin >> A[i];
    }

    // Display the original array
    cout << "The original array is : ";
    for (int i = 0; i < x; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Find and display the leaders in the array
    cout << "Leaders are : ";
    for (int i = 0; i < x; i++) {
        int j;

        // Check if the current element is greater than or equal to
        // all the elements to its right (leadership condition)
        for (j = i + 1; i < x; j++) {
            if (A[i] <= A[j]) {
                break;
            }
        }

        // If the loop completed without breaking, the element is a leader
        if (j == x) {
            cout << A[i] << " ";
        }
    }

    return 0;
}