// trans positioning
#include <iostream>
using namespace std;
int main()
{
    const int rows = 3;
    const int cols = 3;

    int A[rows][cols] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {10,3,7}
    };

    int t_A[cols][rows];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            t_A[j][i] = A[i][j];
        }
    }

    cout << "Original Array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transposed Array:" << endl;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << t_A[i][j] << " ";
        }
        cout << endl;
    }

    // Calculate the sum of elements in the first row of the transposed array
    int sum = 0;
    for (int j = 0; j < rows; j++)
    {
        sum += t_A[0][j];
    }
    cout << "Sum of elements in the first row of the transposed array: " << sum << endl;

    return 0;
}