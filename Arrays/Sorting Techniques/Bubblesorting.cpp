//Take an input from a user 
#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter the size and elements of an Array :";
    cin >> x;
    cout << "__________________________________________________" << endl;
    int A[x];
     cout << "Enter Numbers :";
    for (int i = 0; i < x; i++)
    {
      cin >> A[i];
    }
    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        cout << A[i] << " ";
    }
    cout << " ";
    return 0;
}
/*
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = n-1; i > 0; --i) { 
        for (int j = 0; j < n-1 ; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: \n";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: \n";
    printArray(arr, n);
    
    return 0;
}
*/