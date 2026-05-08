/*8. Write a function that takes a sorted array as input and counts
// the occurrence of each unique element in the array. The function should then display each element alongside its occurrence count.*/
#include<iostream>
using namespace std;
void count_occurrences(int *array, int size) {
    int current_element = array[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (array[i] == current_element) {
            count++;
        } else {
            cout << "Element " << current_element << " occurs " << count << " time(s)." << endl;
            current_element = array[i];
            count = 1;
        }
    }

    cout << "Element " << current_element << " occurs " << count << " time(s)." << endl;
}
void selection_sort(int *array,int size){
    for(int i=0;i<size;i++){
        int smallest_index=i;
        for(int j=i+1;j<size;j++){
            if(array[smallest_index]>array[j]){
                smallest_index=j;               
            }
        }
        int temp=array[i];
        array[i]=array[smallest_index];
        array[smallest_index]=temp;

        cout<<endl;
    }

    cout<<"Sorted Array is:"<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int array[6]={5,9,3,7,3,6};

    selection_sort(array,6);

    count_occurrences(array, 6);
    return 0;
}