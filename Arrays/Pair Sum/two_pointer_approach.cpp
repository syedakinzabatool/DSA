// find the Target Pair Sum.
//Optimised Approach having linear Time Complexity
#include <iostream>
#include <vector>
using namespace std;
vector<int> pairSum(vector<int> nums, int target)
{
    vector<int> ans;
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        int pairSum = nums[start] + nums[end];
        if (pairSum > target)
        {
            end--;
        }
        else if (pairSum < target)
        {
            start++;
        }
        else
        {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {4, 6, 9, 17};
    int target;
    cout << "Enter a number whose pair sum you want: ";
    cin >> target;

    vector<int> ans = pairSum(vec, target);

    if (ans.empty())
    { 
        cout << "No such pair sum exists." << endl;
    }
    else
    {
        cout << "The pair sum of the target is: " << ans.at(0) << "," << ans.at(1) << "." << endl; // ans[0] ,vec[ans[0]],ans.at(0) are all same bro
    }
    return 0;
}
// Time Complexity =O(n)