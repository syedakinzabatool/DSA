// Print elements of index in Ascending order ....
#include <iostream>
#include <algorithm>

using namespace std;
void selectionSort(int A[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
            }
        }
    }
}
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
    selectionSort(A, x);
    for (int i = 0; i < x; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
