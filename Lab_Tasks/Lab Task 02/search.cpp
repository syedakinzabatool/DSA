#include <iostream>
using namespace std;
int search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }

    return -1;
}
int main()
{
    int arr[6] = {3, 5, 6, 78, 98};
    int key;
    cout << "Enter the number to search: ";
    cin >> key;
    if (search(arr, 6, key) != -1)
    {
        cout << "The number found at index: " << search(arr, 6, key);
    }
    else
    {
        cout << "Element not found in array." << endl;
    }
}