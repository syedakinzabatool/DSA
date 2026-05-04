#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int *p = &a;
    int **q = &p;

    cout << "*p= " << *p << "\n";
    cout << "&a= " << &a << "\n";
    cout << "**q= " << **q << "\n";
    cout << "p= " << p << "\n";
    cout << "*q= " << *q << "\n";
}