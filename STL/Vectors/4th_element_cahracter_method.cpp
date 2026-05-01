#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v(3,13);
    cout << "The elements of the vector are:";
    display(v);
    vector<int>v1(v);
    cout<<"The vector made from v is:";
    display(v1);
    cout<<"The size of the vector is:";
    cout<<v1.size();
    cout<<"The maximum no. of elements that a vector can hold is:";
    cout<<v1.max_size();

}