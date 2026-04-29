#include<iostream>
using namespace std;
int main ()
{ 
  int A[3][3]={ {4,8,7},
                {45,50,18},
                {78,21,19} };
int sum=0;
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        { 
            if(i!=j)
            sum=sum-A[i][j];
        }
        
    }

cout<<sum;

return 0;} 