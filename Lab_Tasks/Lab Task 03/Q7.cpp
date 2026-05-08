//7. Write a function that takes a sorted array and a specific value as inputs. The function should first search for the
// value in the array and return its index if found, or indicate that the value is not present (e.g., by returning -1). If the value is found, the function should then calculate the sum of all elements in the array up to (and including) that value and return the sum.
#include <iostream>
using namespace std;
int binarySearchAndSum(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            result = mid;
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // If value is found, calculate sum
    if (result != -1) {
        int sum = 0;
        for (int i = 0; i <= result; i++) {
            sum += arr[i];
        }
     cout << "Sum of elements up to the value: " << sum << endl;
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 5;

    int index = binarySearchAndSum(arr, size, value);

    if (index != -1) {
     cout << "Value found at index: " << index << endl;
    } else {
     cout << "Value not found in the array." << endl;
    }

    return 0;
}