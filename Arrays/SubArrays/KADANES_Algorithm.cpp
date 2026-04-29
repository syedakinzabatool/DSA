// find the Maximum Subarray Sum with O(n) time complexity......
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubArraySum(vector<int> &vec)
{
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int val : vec)
    {
        currentSum += val;
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
        {
            currentSum = 0;   //This'll prefer to set the sum to 0 rather than taking it in -ve...that's the core of the KADANE'S Algorithm
        }
    }
    return maxSum;
}
int main()
{
    vector<int> vec = {-1, 0, 5, 8, -9, 7};
    cout << "The Maximum Subarray sum is: " << maxSubArraySum(vec) << endl;
    return 0;
}
