//6. Write a function to sort an array of integers in descending order using the Quick Sort technique.
#include<iostream>
using namespace std;

void Quick_sort(int *a,int start_index,int end_index){
    if(start_index>=end_index){
        return;
    }
    int i = start_index-1;
    for(int j=start_index;j<end_index;j++){
        if(a[j] > a[end_index]){
            i++;
            int swap=a[i];
            a[i]=a[j];
            a[j]=swap;
        }
    }
    int swap=a[i+1];
    a[i+1]=a[end_index];
    a[end_index]=swap;
    Quick_sort(a, start_index , i);
    Quick_sort(a, i+2 , end_index);

}
int main(){
    int a[5]={5,2,7,1,4};
    int start_index=0;
    int end_index=4;
    Quick_sort(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;

}