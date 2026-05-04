#include<iostream>
using namespace std;
int main()
{
   int s=10;
   int *p; //starric means that the variable is a pointer and it holds memory (address)
    //staric p will print "5" that the value at the pointer

   p=&s;  //&s will print  //p will print address.
  cout<<s<<endl;
   cout<<"Address:"<<p<<endl;
   cout<<"Address"<<&s<<endl;
   cout<<*p;

   *p=*p-5;
}   