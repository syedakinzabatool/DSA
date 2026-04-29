#include <iostream>
using namespace std;
int main()
{
    int a[10][10], d1sum = 0, d2sum = 0,size, i, j;
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

    cout << "\nThe givensizematrix is :: \n\n";
    for (i = 0; i <size; ++i)
    {
        for (j = 0; j <size; ++j)
        {
            cout << "\t" << a[i][j];
        }
        cout<<endl;
    }

    for (i = 0; i <size; ++i)
    {
        for (j = 0; j <size; ++j)
        {
            if (i == j)
            {
                d1sum += a[i][j];
            }
            if (i + j == (size - 1))
            {
                d2sum += a[i][j];
            }
        }
    }
    cout << "\nSum of 1st diagonal is :: " << d1sum;
    cout << "\nSum of 2nd diagonal is :: " << d2sum;

    return 0;
}