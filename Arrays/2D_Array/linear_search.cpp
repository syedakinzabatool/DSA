#include<iostream>
using namespace std;
int main()
{
	int A[3][4]={1,2,3,4,5,6,7,8,5,4,8,7};
 
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=3;j++)
		{
			cout<<A[i][j];
		}
	
	cout<< endl;
	}
	bool flag=false;
	int x;
	cin>>x;
	
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=3;j++)
		if (A[i][j]==x)
		{
			cout<<i<<" "<<j;
			flag=true;
			 
		}
	
	cout<< endl;
	}
	if(flag==true)
	cout<<"number is found ";
	else
	cout<<"number is not found";
}