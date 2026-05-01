#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    cout << "Capacity:  " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity:  " << v.capacity() << endl;

    v.push_back(4);
    cout << "Capacity:  " << v.capacity() << endl;
    // Ot shpwing that it doubles it's memory
    v.push_back(6);
    cout << "Capacity:  " << v.capacity() << endl;
    cout << "Size: " << v.size();
    cout << "1st element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    cout << "2nd element: " << v.at(1) << endl;

    cout<<"Before pop: ";
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"After pop: ";
    v.pop_back();
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
//When we clear vector it's size became 0 not it's capacity and capacity is basically the assigned memory while size mean that how many elements are placed in the vector etc.
cout<<"Before clearing the size is: "<<v.size()<<"\n";
v.clear();
cout<<"After clearing the size is: "<<v.size();


}