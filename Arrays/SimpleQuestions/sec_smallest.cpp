// To find the second smallest element in an array.
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

    int smallest = arr[0];
    int second_smallest = arr[1];

    // Ensure smallest and second_smallest are correctly set initially
    if (second_smallest < smallest) {
        int temp = smallest;
        smallest = second_smallest;
        second_smallest = temp;
    }

    // Iterate through the array to find the smallest and second smallest elements
    for (int i = 2; i < size; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }

    cout << "The second smallest element in the array is: " << second_smallest << endl;

    return 0;
}
