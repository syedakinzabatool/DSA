// find the subarray
#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter the size and elements of an Array : ";
    cin >> x;
    cout << "________________________________________" << endl;
    int A[x];
    for (int i = 0; i < x; i++)
    {
        cout << "Enter Number : ";
        cin >> A[i];
    }
    // printing subarray
    for (int start = 0; start < x; start++)
    {
        int sum = 0;
        for (int end = start; end < x; end++)
        {
            sum += A[end];
        }
        cout << "Sum of the subarray is: " << sum << endl;
    }

    return 0;
}