// Write a program that delete value in a specific location in an array.
#include <iostream>
using namespace std;
void deleteAtIndex(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index. Deletion failed." << endl;
        return;
    }

    // Shift elements to the left starting from the index to delete
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    size--;

    cout << "Element at index " << index << " deleted successfully." << endl;
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
    cout << "Enter the index of the element to delete: ";
    cin >> index;

    deleteAtIndex(arr, size, index);

    cout << "Array after deletion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
