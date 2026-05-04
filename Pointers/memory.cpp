#include <iostream>
using namespace std;
int main() {
    int *ptr = new int; 
    *ptr = 42; 
  cout << "Value using dynamic memory: " <<*ptr << endl;
   return 0;
}
