//Right_Diagonal Sum in a Square Matrix
#include <iostream>
using namespace std;

int r_d_sum(int A[100][100], int n) {
     cout << "The sum of the elements on the right diagonal is: ";
    int d_sum = 0;                  
    for (int i = 0; i < n; i++) {
        d_sum += A[i][n - 1 - i];
    }

    return d_sum;               
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int A[100][100];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout<< r_d_sum(A, n);
 

    return 0;
}
