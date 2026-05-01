#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int> &v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 1, 2, 4};
    cout << singleNumber(v);
}
