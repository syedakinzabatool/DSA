/*2. Develop a function to reorder an array of integers in descending order using the Bubble Sort technique.*/
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = n-1; i > 0; --i) { 
        for (int j = 0; j < n-1 ; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] ={14,100,5,2,89};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: \n";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: \n";
    printArray(arr, n);
    
    return 0;
}