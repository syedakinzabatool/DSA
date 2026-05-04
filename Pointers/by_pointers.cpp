#include <iostream>
using namespace std;
int pass_by_value(int a){
return a=2;
}
int pass_by_reference_using_pointers(int* a){
return *a=2;
}
int pass_by_reference_using_alias(int &a){
return a=2;
}
int main(){
    int a=5;
    cout<<"a by pass by value is: "<<pass_by_value(a)<<endl; 
    cout<<"a by pass by reference using pointers is: "<<pass_by_reference_using_pointers(&a)<<endl;
    cout<<"a by pass by reference by alias method is: "<<pass_by_reference_using_alias(a)<<endl;

}