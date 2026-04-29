#include <iostream>
using namespace std;

int main() {
    int n; 
    cout<<"Enter rows:";
    cin >> n ;
    int m; 
    cout<<"Enter column:";
    cin >> m;
    int arr[n][m];
    cout<<"enter the elments of array:";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    // Spiral order print
    int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;
    cout<<"Spiral array is:";
    while (row_start <= row_end && col_start <= col_end) {
        // Traverse the top row from left to right
        for (int col = col_start; col <= col_end; col++) {
            cout << arr[row_start][col] << " ";
        }
        row_start++;
        cout<<endl;

        // Traverse the rightmost column from top to bottom
        for (int row = row_start; row <= row_end; row++) {
            cout << arr[row][col_end] << " ";
        }
        col_end--;
cout<<endl;
        // Traverse the bottom row from right to left
        if (row_start <= row_end) {
            for (int col = col_end; col >= col_start; col--) {
                cout << arr[row_end][col] << " ";
            }
            row_end--;
        cout<<endl;
        }

        // Traverse the leftmost column from bottom to top
        if (col_start <= col_end) {
            for (int row = row_end; row >= row_start; row--) {
                cout << arr[row][col_start] << " ";
            }
            col_start++;
        cout<<endl;
        }
    
    }

    return 0;
}
/*
#include <iostream>
using namespace std;

// Function to traverse and print the top row from left to right
void traverseTopRow(int arr[][100], int row_start, int col_start, int col_end) {
    for (int col = col_start; col <= col_end; col++) {
        cout << arr[row_start][col] << " ";
    }
}

// Function to traverse and print the rightmost column from top to bottom
void traverseRightColumn(int arr[][100], int row_start, int row_end, int col_end) {
    for (int row = row_start; row <= row_end; row++) {
        cout << arr[row][col_end] << " ";
    }
}

// Function to traverse and print the bottom row from right to left
void traverseBottomRow(int arr[][100], int row_end, int col_start, int col_end) {
    for (int col = col_end; col >= col_start; col--) {
        cout << arr[row_end][col] << " ";
    }
}

// Function to traverse and print the leftmost column from bottom to top
void traverseLeftColumn(int arr[][100], int row_start, int row_end, int col_start) {
    for (int row = row_end; row >= row_start; row--) {
        cout << arr[row][col_start] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr[100][100]; // Assuming maximum dimensions

    // Input matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;

    while (row_start <= row_end && col_start <= col_end) {
        // Traverse and print top row from left to right
        traverseTopRow(arr, row_start, col_start, col_end);
        row_start++;

        // Traverse and print rightmost column from top to bottom
        traverseRightColumn(arr, row_start, row_end, col_end);
        col_end--;

        // Traverse and print bottom row from right to left
        if (row_start <= row_end) {
            traverseBottomRow(arr, row_end, col_start, col_end);
            row_end--;
        }

        // Traverse and print leftmost column from bottom to top
        if (col_start <= col_end) {
            traverseLeftColumn(arr, row_start, row_end, col_start);
            col_start++;
        }
    }

    return 0;
}
*/
