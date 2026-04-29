//rotation of array
#include <iostream>
using namespace std; 
void rotateArray(int arr[], int n, int k) {
    // If rotation count is zero or the array is empty
    if (k == 0 || n == 0)
        return;

    // Normalize the rotation count to be within array length
    k = k % n;

    // Create a temporary array to store elements to be rotated
    int temp[k];

    // Store the last k elements in temp array
    for (int i = 0; i < k; ++i) {
        temp[i] = arr[n - k + i];
    }

    // Shift elements of arr[] to the right by k positions
    for (int i = n - 1; i >= k; --i) {
        arr[i] = arr[i - k];
    }

    // Copy back the elements from temp array to arr[]
    for (int i = 0; i < k; ++i) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rotateArray(arr, n, k);

    cout << "Array rotated to the right by " << k << " positions: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
