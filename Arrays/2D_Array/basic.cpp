#include<iostream>
using namespace std;
int main()
{
   int x;
   cout<<"No. of rows:";
   cin>>x;
      int y;
   cout<<"No. of columns:";
   cin>>y;
   int A[x][y];
   for(int i=0;i<x;i++)  //row
   { for(int j=0;j<y;j++) //coloumn
   {
   cout<<"Enter the value:";
   cin>>A[i][j];
   }
}
    
   for(int i=0;i<x;i++)  //row
   { for(int j=0;j<y;j++)  //coloumn
   {
   cout<<A[i][j];
   }
   cout<<endl;
}
}
