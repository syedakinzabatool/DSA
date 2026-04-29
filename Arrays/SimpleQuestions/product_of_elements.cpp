#include <iostream>
using namespace std;
int main() {
    int x;
    cout << "Enter the size and elements of an Array : ";
    cin >> x;
    int count=0;
    cout << "________________________________________" << endl;
    int A[x];
    for (int i = 0; i < x; i++) 
    {
        cout << "Enter Number : ";
        cin >> A[i];
    }
    for( int i=0 ; i<x ; i++ )
    {
       count++;
    }
    for (int i = 0; i < x; i++)
    {
        cout << A[i] << " ";
    }
    cout<<"The size of array is:"<<count;
    cout <<" ";
    return 0;
}