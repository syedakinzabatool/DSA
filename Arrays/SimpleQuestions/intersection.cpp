//intersection of 2 arrays
#include <iostream>
using namespace std;
void find_Common_Elements(int arr_1[], int size_1, int arr_2[], int size_2) {

    cout << "Common elements: ";
    for (int i = 0; i < size_1; ++i) {      //1st_array outer loop will compare the i with the all ELEMENTS of the j
        for (int j = 0; j < size_2; ++j) { //2nd_array
            if (arr_1[i] == arr_2[j]) {
                cout << arr_1[i] << " ";
                break;
            }
        }
    }

    cout << endl;
}
int main() {
    const int size_1 = 5;
    const int size_2 = 7;

    int arr_1[size_1] = {1, 2, 3, 4, 5};
    int arr_2[size_2] = {3, 4, 5, 6, 7, 8, 9};

    find_Common_Elements(arr_1, size_1, arr_2, size_2);

    return 0;
}
