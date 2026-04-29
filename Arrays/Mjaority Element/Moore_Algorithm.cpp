#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int> &vec)
{
    int n = vec.size();
    sort(vec.begin(), vec.end());
    int freq = 0;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (freq == 0)
        {
            ans = vec[i];
        }
        if (ans == vec[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    //Suppose if we take input from user and no majority element exists.
    int count = 0;
    for (int val : vec)
    {
        if (val == ans)
        {
            count++;
        }
    }
        if (count > n / 2)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }

int main()
{
    vector<int> vec = {1,1,2,2,1};
    int result = majorityElement(vec);
    if (result != -1)
    {
        cout << "The Majority element is: " << result << endl;
    }
    else
    {
        cout << "No majority element found." << endl;
    }
    return 0;
}