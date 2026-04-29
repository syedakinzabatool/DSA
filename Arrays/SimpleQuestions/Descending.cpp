//Print elements of index in Decending order ....

#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter the number of elements in an Array :";
    cin >> x;
    cout << "-----------------------------------------------" << endl;
    int A[x];
    for (int i = 0; i < x; i++)
    {
        cout << "Enter Number :";
        cin >> A[i];
    }
    for (int i = 0 ; i < x-1; i++)     //1st index will b compared with the all of the elements by jth loop           
    {
        for (int j = i + 1; j < x; j++)
        {                                        //L<R
            if (A[i] < A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}