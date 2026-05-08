#include<iostream>
using namespace std;

void insertion(int ar[], int n){
    for(int i=1; i<n; i++){
        int temp=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>temp){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=temp;
    }
}

void printArray(int ar[], int n){
    for(int i=0; i<n; i++) 
        cout << ar[i] << " ";
    cout << endl;
}

int main(){
    int arr[6]={12,13,2,6,3,9};
    insertion(arr, 6);
    cout << "The sorted array in ascending order is: ";
    printArray(arr, 6);
    return 0;
}

