#include <iostream>
using namespace std;
int x;
int y;
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main(){
int x=12;
int y=8;
cout<<x<<" "<<y<<endl;
swap(&x,&y);
cout<<x<<" "<<y<<endl;

}