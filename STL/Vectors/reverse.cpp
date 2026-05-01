#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverse(vector<int> &v)
{
    int start = 0;
    int end = v.size() - 1;

    while(start < end){
        swap(v[start], v[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> v = {2, 67, 3, 9, 4};

    reverse(v);

    for (int i : v) {
        cout << i << "  ";
    }

    return 0;
}