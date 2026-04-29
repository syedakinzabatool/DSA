#include <iostream>
using namespace std;
int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int even_sum = 0;
    int odd_sum = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) { // Even index
            even_sum += arr[i];
        } else { // Odd index
            odd_sum += arr[i];
        }
    }

    cout << "Sum of elements at even indices: " << even_sum << endl;
    cout << "Sum of elements at odd indices: " << odd_sum << endl;

    return 0;
}
