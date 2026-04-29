// #include <iostream>
// using namespace std;
// int main(){
//     int size;
//     cout<<"Enter the size of arrays:  ";
//     cin>>size;
//     int Array_1[size],Array_2[size],Sum[size];
//     cout<<"Enter the elements of the First Array:";

//     for(int i=0;i<size;i++){
//         cin>>Array_1[i];
//     }
  
//     cout<<"Enter the elements of the Second Array:";
    
//     for(int i=0;i<size;i++){
//         cin>>Array_2[i];
//     }
//       cout<<"The sum of both arrays is:";
//     for(int i=0;i<size;i++){
//        Sum[i]=Array_1[i]+Array_2[i];
//         cout<< Sum[i];

//     }
// }






 #include <iostream>
using namespace std;
// Function to calculate the sum of corresponding elements of two arrays
void sumArrays(const int arr1[], const int arr2[], int result[], int size) {
    for (int i = 0; i < size; ++i) {
        result[i] = arr1[i] + arr2[i];
    }
}

// Function to display the elements of an array
void displayArray(const int result[], int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << result[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    const int size = 5; // Size of the arrays

    int arr1[size], arr2[size], result[size];

    // Input for first array
    cout << "Enter elements for first array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout<<"Elements:";
        cin >> arr1[i];
    }

    // Input for second array
    cout << "Enter elements for second array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout<<"Elements:";
        cin >> arr2[i];
    }

    // Calculate sum of arrays
    sumArrays(arr1, arr2, result, size);

    // Displaying the result
    cout << "Sum of corresponding elements:" << endl;
    displayArray(result, size);

    return 0;
}
