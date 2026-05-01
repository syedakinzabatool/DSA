#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {2, 7, 9, 4};
    cout << "The elements are: " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\nSize: " << v.size() << endl;

    v.push_back(25);
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back(); // to delete
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "After front: ";

    cout << v.front(); // for 1st element

    cout << "After back: ";

    cout << v.back(); // for last element

    vector<int> vector;
    cout << vector.size() << endl;
    vector.push_back(23);
    vector.push_back(45);
    cout << vector.size() << endl;

    vector.push_back(67);
    vector.push_back(77);
    vector.push_back(7);

    cout << vector.size() << endl;
    cout << vector.capacity() << endl;
}