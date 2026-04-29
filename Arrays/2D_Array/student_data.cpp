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
    int matrix[rows][cols];

    // Input values from the user
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }

    // Display the entered matrix
    cout << "\nThe entered matrix is:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
