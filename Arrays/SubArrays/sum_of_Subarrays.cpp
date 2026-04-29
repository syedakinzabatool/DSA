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
        cout << "Subarray: " << endl;
         for (int end = start; end < x; end++)
        {
            // print the elements in the range from start to end
            for (int i = start; i <= end; i++)
            {
                cout << A[i] << " ";
                sum += A[i];
            }
            cout << endl;
        }
        cout << "The sum of the subarray is: " << sum << endl;
    }

    return 0;
}