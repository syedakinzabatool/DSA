#include<iostream>
using namespace std;
int main ()
{
  int A[3][3]={ {3,8,7},
                {45,4,18},
                {78,21,19} };
    int min=100;
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        { 
            if(min>A[i][j])
           min=A[i][j];
        } 
    }

cout<<min;
return 0;
} 