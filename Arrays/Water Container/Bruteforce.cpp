#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height)
{            int maxWater = 0; //ans

    for (int i = 0; i < height.size(); i++)
    {

        for (int j = i + 1; j < height.size(); j++)
        {
            int width = j - i;
            int minH = min(height[i], height[j]);
            int currwater = minH * width;
            int maxWater = max(maxWater, currwater);
        }

    }
    return maxWater;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result =maxArea(height);

    cout << "The maximum water that could be stored in the container is: "<<result;
}
/*
==> The issue with the code is that it has a time complexity of O(n^2) due to the nested loops, which can be inefficient for large inputs. 
Also, the approach is not optimal as it calculates the area for every possible pair of lines, which is not necessary.
==> A more efficient approach would be to use two pointers, one starting from the left and one from the right, and move them towards each other.
The area between the two lines is calculated at each step, and the maximum area is updated according.
bcz it has a time complexity of O(n^2). 
*/