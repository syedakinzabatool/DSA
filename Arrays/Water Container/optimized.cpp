#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Time Complexity =O(n)
float maxArea(vector<int> &height)
{
    int maxWater = 0; // ans
    int lp = 0, rp = height.size() - 1;
    while (lp < rp)
    {
        {
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currwater = ht * w;
            maxWater = max(maxWater, currwater);
            //Ternary statement
            height[lp] < height[rp] ? lp++ : rp--; //if cond. is true then implement[cout] (?)==>else(:) the statement after [:]
        }
    }
    return maxWater;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);

    cout << "The maximum water that could be stored in the container is: " << result;
}
