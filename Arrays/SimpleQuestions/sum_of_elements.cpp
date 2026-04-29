//sum of all the elements of array
#include <iostream>
using namespace std;
int main() {
    int x;
    cout << "Enter the size and elements of an Array : ";
    cin >> x;
    int sum=0;
    cout << "_________________________________________" << endl;
    int A[x];
    for (int i = 0; i < x; i++) 
    {
        cout << "Enter Number : ";
        cin >> A[i];
    }
    for( int i=0 ; i<x ; i++ )
    {
        sum+=A[i];
    }
    for (int i = 0; i < x; i++)
    {
        cout << A[i] << " ";
    }
    cout<<"The sum of elements is:"<<sum;
    cout << " ";
    return 0;
}
// #include <iostream>
// using namespace std;
// int main() {
//     int arr[]={56,8,9,21,1,63};
//     int n=sizeof(arr)/4;
    
//INT_MIN is the most smallest number that this data type can store. } 