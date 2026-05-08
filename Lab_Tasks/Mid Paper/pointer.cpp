// Find the errors in the following code. Do not write the question in your answer sheet. Only write the line having error, and re-write the line to correct the error. If you do not find any errors in the code, calculate the output of the program in rough work and write down only the output in your answer.

#include <iostream>

using namespace std;

int main()
{

    int a, b, c, d, e;

    int *p1, *p2, *p3, *p4;

    p1 = &a;  *p1 = 3;  //last digit of roll no
    p2 = &b;  *p2 = 4;  //last digit of date

    p3 = &c;
    *p3 = *p1 + *p2;

    p4 = &d;
    *p4 = 5;
    int *tempPtr = p1;

    *tempPtr = (*p1 + *p2) * (*p3 - *p4);

    tempPtr = p2;

    //*tempPtr = (*p1 + *p2) * (*p3 / *p1); // Error: Division by zero if *p1 is 0
    *tempPtr = (*p1 + *p2) * (*p3 / (*p1 + 1)); 
    tempPtr = p3;

    *tempPtr += *p4 - (*p2 % *p1);
    tempPtr = p4;

    *tempPtr = (*p1 + *p2) * (*p3 / *p1);
    *p1 = (*p2 + *p3) % *p4;

    *p2 = (*p3 + *p1) * (*p4 - *p1) / *p2;

    cout << " a " << a << endl;
    cout << " b " << b << endl;
    cout << " c " << c << endl;
    cout << " d " << d << endl;
    cout << " e " << e << endl;

    return 0;
}