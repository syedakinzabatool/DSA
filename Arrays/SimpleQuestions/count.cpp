//take an integer and find greater no.s than this and also count them.

#include <iostream>
using namespace std;
int main()
{   int num;
    cout<<"Enter a number for comparison:";
    cin>>num;
    int count=0;
    int x;
    cout << "Enter the number of elements in an Array :";
    cin >> x;
    cout << "-----------------------------------------------" << endl;
    int A[x];
    for (int i = 0; i < x; i++)
    {
        cout << "Enter Number :";
        cin >> A[i];
    }
   
    for (int i = 0; i <x; i++)
    {
        if (A[i]>num){
            count++;}
    }
    cout<<count<<endl; 
    return 0;
}