#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int start = low + 1;
    int end = high;

    while (start <= end)
    {
        while (start <= high && start <= pivot)
        {
            start++;
        }
        while (end >= low && end > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(pivot, arr[end]);
    return end;
}
void sorting(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        sorting(arr, low, pivot - 1);
        sorting(arr, pivot + 1, high);
    }
}
