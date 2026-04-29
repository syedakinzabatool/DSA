// Write a program that inserts a value in a specific location in an array.
#include <iostream>
using namespace std;

void insertAtIndex(int arr[], int& size, int index, int value) {
    if (index < 0 || index > size) {
        cout << "Invalid index. Insertion failed." << endl;
        return;
    }

    // Increase the size of the array
    size++;

    // Shift elements to the right starting from the index to insert
    for (int i = size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified index
    arr[index] = value;

    cout << "Element " << value << " inserted at index " << index << " successfully." << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int index;
    cout << "Enter the index where you want to insert the element: ";
    cin >> index;

    int value;
    cout << "Enter the value to insert: ";
    cin >> value;

    insertAtIndex(arr, size, index, value);

    cout << "Array after insertion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}