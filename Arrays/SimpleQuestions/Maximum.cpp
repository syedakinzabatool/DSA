#include <iostream>
using namespace std;
int main()
{

	int max = 0;
	int a[] = {5, 8, 2, 68, 7};
	for (int i = 0; i < 5; i++)
	{
		if (max < a[i])
			max = a[i];
	}

	cout << "Greater number is = " << max << endl;
}