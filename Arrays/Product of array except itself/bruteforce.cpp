// find the Target Pair Sum......
#include <iostream>
#include <vector>
using namespace std;
vector<int> product(vector<int> vec)
{
    vector<int> ans(vec.size(),1);
    for (int i = 0; i <vec.size(); i++) {
        for (int j = 0; j <vec.size(); j++)
        {
            if (i != j ) {
             ans[i]*=vec[j];

        }
    }
    return ans; // which is basically a vector.
}}
int main()
{
    vector<int> vec = {4, 9, 6, 17, 3};
    vector<int> ans = product(vec);
    cout<<"The product of the array except the itself indices is: "<< ans.at(0);

   
}
//Time Complexity =O(n^2)