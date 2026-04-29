#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choosing the first element as the pivot
    int start = low + 1; // Start from the next element
    int end = high; // End starts from the last element

    while (start <= end) // Change to <= to include the end
    {
        // Increment start until we find an element greater than the pivot
        while (start <= high && arr[start] <= pivot)
            start++;
        // Decrement end until we find an element less than or equal to the pivot
        while (end >= low && arr[end] > pivot)
            end--;
        
        // If there is an element on the left that is greater than the pivot
        // and an element on the right that is less than or equal to the pivot
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    // Place the pivot in the correct position
    swap(arr[low], arr[end]);
    return end; // Return the index of the pivot
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partitioning index

        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}