 #include<iostream>
 #include<array>
 using namespace std;
 int main(){
    array<int,4> a={1,2,3,4};
    int size;
    cout<<"The size of the array is:"<<a.size();
    //Print the array
    for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
    }
    //using "at" to print array
    cout<<"Element at 2nd Index: "<<a.at(2)<<endl;
    //To check array is empty or not
    cout<<"Empty or not:\nIf empty then  will return 1 otherwise it'll return 0."<<"     " <<a.empty()<<endl;
    //"First  element"
    cout<<"First element: "<<a.front()<<endl;
    cout<<"Last element: "<<a.back()<<endl;




 }