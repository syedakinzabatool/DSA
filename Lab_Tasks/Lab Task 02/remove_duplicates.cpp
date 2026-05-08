#include <iostream>
using namespace std;
int duplicates(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i])
        {--i;        }
    }
}
int main()
{
    int arr[6] = {3, 5, 6, 78, 98};
   
    
        cout << "The number found at index: " << duplicates(arr, 6);
    
   
}