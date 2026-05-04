#include<iostream>
using namespace std;
int main()
{
   int s=10;
   int* p;
   p=&s;

   cout<<"Address:"<<*p<<endl; // * value at address
   cout<<"Address"<<&s<<endl;
   cout<<*p;
}