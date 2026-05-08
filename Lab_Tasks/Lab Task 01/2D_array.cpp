#include <iostream>
using namespace std;

// Function to search for a specific value in the array
bool searchValue(int arr[3][2], int value) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (arr[i][j] == value) {
                return true;
            }
        }
    }
    return false;
}

// Function to display all values in the array that are greater than 5
void displayGreaterThanFive(int arr[3][2]) {
    cout << "Values greater than 5: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (arr[i][j] > 5) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

// Function to calculate and display the sum of all the values in the array
void calculateSum(int arr[3][2]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            sum += arr[i][j];
        }
    }
    cout << "Sum of all values: " << sum << endl;
}

int main() {
    int arr[3][2] = {{1, 2}, {3, 6}, {8, 9}};

    // Search for a specific value
    int value;
    cout << "Enter a value to search: ";
    cin >> value;
    if (searchValue(arr, value)) {
        cout << "Value found in the array." << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    // Display all values greater than 5
    displayGreaterThanFive(arr);

    // Calculate and display the sum of all values
    calculateSum(arr);

    return 0;
}