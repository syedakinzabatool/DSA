//rotate 2nd element of array
#include <iostream>
using namespace std;
void Rotate_Right(int arr[], int size, int positions) {
    for (int i = 0; i < positions; ++i) {
        int temp = arr[size - 1];

        for (int j = size - 1; j > 0; --j) {
            arr[j] = arr[j - 1];
        }

        arr[0] = temp;
    }
}

void Print_Array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    const int size = 6;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int positions = 2;
    cout << "Original array: ";
    Print_Array(arr, size);
    Rotate_Right(arr, size, positions);
    cout << "Array after rotating to the right by " << positions << " positions: ";
    Print_Array(arr, size);
    return 0;
}
