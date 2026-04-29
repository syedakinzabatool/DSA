#include <iostream>
using namespace std;
int main() {
    int x;
    cout << "Enter the size and elements of an Array : ";
    cin >> x;
    int sum=0;
    int count=0;
    float average=0.0;
    cout << "_________________________________________" << endl;
    int A[x];
    for (int i = 0; i < x; i++) 
    {
        cout << "Enter Number : ";
        cin >> A[i];
    }
    // for( int i=0 ; i<x ; i++ )
    // {
      //    sum+=A[i];
      //  average=float(sum)/x;
    // }
    for (int i = 0; i < x; i++)
    {
         sum+=A[i];
        average=float(sum)/x;
        cout << A[i] << " ";
    }
    cout<<"The sum of elements is: "<<sum<<endl<<"The average of element is: "<<average;
    cout << " ";
    return 0;
}