#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter the size of an Array :";
    cin >> x;
     int A[x];
       cout << "Enter Numbers :";
    for (int i = 0; i < x; i++)
    {
      
        cin >> A[i];
       
    }
    cout<<"The elements of array are:";
     for (int i=0; i<x; i++ ){
      cout<<A[i]<<" ";
     }
      cout<<endl;

      int even_count=0;
      int even_elements;
      cout<<"The even elements are:";
      for (int i = 0; i < x; i++)
    {
        if(A[i]%2==0)
        {
            even_elements=A[i];
             cout<<even_elements<<" ";
            even_count++;
        }
    
    }
     cout<<endl;
     int odd_count=0;
      int odd_elements;
      cout<<"The odd elements are:";
    for (int i = 0; i < x; i++)
    {
        if(A[i]%2!=0)
        {
            odd_elements=A[i];
            cout<<odd_elements<<" ";
            odd_count++;
        }
    }
         cout<<endl;
        cout<< "The total even_elments are :"<<even_count<<"\n"<<"The total odd elements are :"<<odd_count<<"\n"; 
}
