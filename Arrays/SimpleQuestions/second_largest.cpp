//  Write a C++ program to find the second-largest element in an array of integers.
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

  
    int arr[size];
    cout << "Enter " << size << " integers for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    int secondMax = 0; // Assume second largest is the same as the largest initially

    // Find the largest element
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            secondMax = max; // Update secondMax to previous max
            max = arr[i];    // Update max to the new maximum value
        } else if (arr[i] > secondMax && arr[i] != max) {
            secondMax = arr[i]; // Update secondMax if arr[i] is greater than current secondMax and not equal to max
        }
    }

    cout << "The second-largest element in the array is: " << secondMax << endl;

    return 0;
}


          



