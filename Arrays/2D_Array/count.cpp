#include<iostream>
using namespace std;
int main()
{
 int A[2][4]={1,2,3,8,5,6,7,8};
 int count =0;
 int m=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
		{
			if ( A[i][j]==8)
		 {
		 cout<< "value found at row numb: "<<i+1<<"and Coloum numb: "<<j+1<<endl;
	    count++;
		m++;
		}
        if (m==0){cout<<"No. not found.";}
		
	}
	cout<<"number found=  "<<count<<" times"<<endl;
	return 0;
    
}}