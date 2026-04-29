//if index is odd then multiply with 2 and if is even that add 10 to it.

#include <iostream>
using namespace std;

int main()
{
   int A[]={1,2,3,4,5,6};
   
    for (int i = 0; i <6; i++)
    {
        if (A[i] % 2 != 0){
            cout <<"odd index elements are:" <<A[i]*2 <<endl;
           }
        else{
            cout<<"Even index elemnts are:"<<A[i]+10<<endl;
        }
    }
    cout<<endl; 
    return 0;
}