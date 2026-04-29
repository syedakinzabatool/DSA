#include<iostream>
using namespace std;
int main ()
{
int max=0;
 
  int A[3][3]={ {4,8,7},
                {45,50,18},
                {78,21,19} };
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        { 
            if(max<A[i][j])
            max=A[i][j];
        }
        
    }

cout<<max;
return 0;
} 