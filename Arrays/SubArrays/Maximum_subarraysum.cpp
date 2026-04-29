// find the Maximum Subarray Sum by Brute Force Approach
#include <iostream>
#include <climits>
#include <algorithm>


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
            int sum = 0;
            int maximum_sum=INT_MIN;

    for (int start = 0; start < x; start++)
    {
        for (int end = start; end < x; end++)
        {
            sum += A[end];
            maximum_sum=max(maximum_sum,sum);

        }
        cout << "Sum of the subarray is: " << sum << endl;
    }
    //    maximum_sum=max(maximum_sum,sum);

    cout<<"The maximum sum is: "<<maximum_sum<<endl;

    return 0;
}