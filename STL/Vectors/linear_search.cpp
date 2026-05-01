#include <iostream>
#include <vector>
using namespace std;
int linearsearch(vector<int> &v)
{
    int key;
    cout << "Enter a number to search: ";
    cin >> key;
    for (int i : v)
    {
        if (i == key)
        {

            return 1;
        }
    }
}
int main()
{
    vector<int> v = {2, 67, 3, 9, 4};

    if (linearsearch(v) == 1)
    {
        cout << "Number found. " << endl;
    }
    else
    {
        cout << "Not found.";
    };
}
