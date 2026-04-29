#include <iostream>

  int main() {
  int size;
  {
    int a[][10], d1sum = 0, d2sum = 0,size, i, j;
    cout << "Enter size of matrix :: ";
    cin >>size;
    cout << "\nEnter Elements to size matrix Below :: \n";

    for (i = 0; i <size; i++)
    {
        for (j = 0; j <size; ++j)
        {
            cout << "\nEnter a[" << i << "][" << j << "] Element :: ";
            cin >> a[i][j];
        }
    }

    int leftDiagonalSum = 0;

    for (int i = 0; i < N; ++i) {
        leftDiagonalSum += matrix[i][i];
    }

    std::cout << "Sum of elements along the left diagonal: " << leftDiagonalSum << std::endl;

    return 0;
}
