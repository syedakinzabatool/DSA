#include <iostream>
using namespace std;

int main() {
       // Declare variables for dimensions
    int rows, cols;

    // Get dimensions from the user
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Declare the 2D array with user-defined dimensions
    int arr[rows][cols];

    // Input values from the user
    cout << "Enter the elements of the arr:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i << ", " << j  << "): ";
            cin >> arr[i][j];
        }
    }

    int largest = arr[0][0];
    int secondLargest = arr[0][0];

    // Finding the largest element
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > largest) {
                secondLargest = largest;
                largest = arr[i][j];
            } else if (arr[i][j] > secondLargest && arr[i][j] != largest) {
                secondLargest = arr[i][j];
            }
        }
    }

    cout << "The second largest element in the array is: " << secondLargest << endl;

    return 0;
}
