#include <iostream>
using namespace std;
int main()
{
    int size = 5;
    int a[size][size];
    int row, col;
    cout << "Please Enter elements in array of size " << size << "x" << size << endl<< endl;
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            cin >> a[row][col];
        }
    }
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
    for (row = 0; row < size; row++)
    {
        int row_sum = 0;
        for (col = 0; col < size; col++)
        {
            row_sum = row_sum + a[row][col];
        }
        cout << "Sum of elements of Row: " << row + 1 << " is " << row_sum << endl;
    }
    for (col = 0; col < size; col++)
    {
        int col_sum = 0;
        for (row = 0; row < size; row++)
        {
            col_sum += a[row][col];
        }
        cout << "Sum of elements of Column: " << col + 1 << " is " << col_sum << endl;
    }
}