#include <iostream>
using namespace std;
int main()
{
  int x;
  cout << "Enter the size of an Array :";
  cin >> x;

  int A[x];
  for (int i = 0; i < x; i++)
  {
    cout << "Enter Number :";
    cin >> A[i];
  }
  int key;
  cout << "Enter no. for search:";
  cin >> key;

  bool found = false;  // Add this line before the search loop

  for (int i = 0; i < x; i++)
  {
    if (key == A[i])
    {
      cout << "No. found at index :" << i << endl;
      found = true;  // Set flag to true if number is found
      break;
    }
  }
  
  if (!found)  // Add this condition after the loop
  {
    cout << "No. not found in array" << endl;
  }
}