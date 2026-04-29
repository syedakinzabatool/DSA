/* Write the definition of the function setInStock that prompts the user
to input the elements for the first column of inStock. The function
should then set the elements in the remaining columns to two times the
corresponding element in the previous column, minus the corresponding element in delta */
#include <iostream>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 3;

void setInStock(int inStock[][MAX_COLS], int delta[]) {
    int numRows;

    cout << "Enter the number of rows for inStock: ";
    cin >> numRows;

    if (numRows > MAX_ROWS) {
        cerr << "Error: Number of rows exceeds the maximum limit.\n";
        return;
    }

    cout << "Enter elements for the first column of inStock:\n";
    for (int i = 0; i < numRows; ++i) {
        cin >> inStock[i][0];
    }

    // Set the elements in the remaining columns
    for (int i = 0; i < numRows; ++i) {
        for (int j = 1; j < MAX_COLS; ++j) {
            inStock[i][j] = 2 * inStock[i][j - 1] - delta[j - 1];
        }
    }
}

int main() {
    int inStock[MAX_ROWS][MAX_COLS];
    int delta[MAX_COLS - 1];

    // Call setInStock to set the values in inStock based on user input
    setInStock(inStock, delta);

    // Display the resulting inStock array
    cout << "\nResulting inStock array:\n";
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << inStock[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}