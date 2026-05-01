#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
       // cout << v[i] << " ";   //Both performs the same function
        cout<<v.at(i)<<" ";
    }
    cout << endl;
}
int main()
{
    vector<int> v;
    int elements, size;
    cout << "Enter the limit of the vector:";
    cin >> size;
    cout << "Enter the elements of the vector:";
    for (int i = 0; i < size; i++)
    {
        cin >> elements;
        v.push_back(elements);
    }
    cout << "The elements of the vector are:";
    display(v);
    //we made a new vector having iterator named as iter and here we want to point at the first index that's why we used begin modifier.
    vector<int>::iterator iter=v.end();
    //in this it'll use "iter" which'll point at the position where we defined at the top and then it'll add 5 times 45 at that position.
    //v.insert(iter,5,45);
    //display(v);

}