// find the Target Pair Sum......
#include <iostream>
#include <vector>
using namespace std;
vector<int> pairSum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans; // which is basically a vector.
}
int main()
{
    vector<int> vec = {4, 9, 6, 17, 3};
    int target;
    cout << "Enter a number whose pair sum you want: ";
    cin >> target;

    vector<int> ans = pairSum(vec, target);

    if(ans.empty()){ // Check if the vector is empty
        cout << "No such pair sum exists." << endl;
    } else {
        cout << "The pair sum of the target is: " << ans.at(0) << "," << vec[ans[1]] << "." << endl;//ans[0] ,vec[ans[0]],ans.at(0) are all same bro
    }
    return 0;
}
//Time Complexity =O(n^2)