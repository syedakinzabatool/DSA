#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str1 = "kinza";
    string str2 = "Batool";

    if (str1 < str2)
    {
        cout << "Str2 is greater";
    }
    else
    {
        cout << "Str1 is greater"; // Bcz K comes After in abc so,it'll be greater.
    }
    cout << endl;

    /*Can also calculate length of string*/
    cout << "The length of str1 is: " << str1.length();

    string str3;
    cout << "\nEnter a string: " << endl;
    getline(cin, str3);

    for (int i = 0; i < str2.length(); i++)
    {
        cout << str2[i];
    }
    cout << endl;
    // To print
    for (char ch : str1)
    {
        cout << ch;
    }
    // Reverse a charater string
    string reverse_string;
    cout << "\nEnter a string to reverse: " << endl;
    getline(cin, reverse_string);
    int start = 0;
    int end = reverse_string.length() - 1;

    // cout << "Reverse by two pointer approach:\n";

    // while (reverse_string[start] < reverse_string[end])
    // {

    //     swap(reverse_string[start], reverse_string[end]);
    //     start++;
    //     end--;
    // }

    // for (char rs : reverse_string)
    // {
    //     cout << rs;
    // }
    // cout << endl;
    cout << "Reverse of built-in string:\n";

    reverse(reverse_string.begin(), reverse_string.end());
    cout << reverse_string << endl;
    cout << endl;
}
