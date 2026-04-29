//delete the 
#include <iostream>
using namespace std; 
void removeDuplicates(int arr[], int &size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                // Shift elements to the left to remove the duplicate
                for (int k = j; k < size - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                // Decrease the size of the array
                --size;
                // Since we shifted elements, check the same index again
                --j;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
       cout << arr[i] << " ";
    }
   cout <<endl;
}

int main() {
    const int maxSize = 10;
    int arr[maxSize] = {1, 2, 3, 2, 4, 5, 3, 6, 7, 7};
    int size = 10;

   cout << "Original array: ";
    printArray(arr, size);

    removeDuplicates(arr, size);

   cout << "Array after removing duplicates: ";
    printArray(arr, size);

    return 0;
}
