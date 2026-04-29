#include <iostream>
using namespace std;
int main()
{
	
	int min=100;
	int a[]={5,8,89,12,7};
	for(int i=0; i<5; i++)
	{
		if(min>a[i])
		min=a[i];
	}

	cout<<"minimum number is ="<<min<<endl;
    
}