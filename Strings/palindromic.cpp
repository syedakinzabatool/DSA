#include <iostream>
#include <string>
using namespace std;

class isPlaindrome
{
public:
    string str;
    isPlaindrome(string str)
    {
        this->str = str;
    }

    bool Alphanumeric(char ch)
    {
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
        {
            return true;
        }
        return false;
    }

    bool check()
    {
        int start = 0;
        int end = str.length() - 1;
        while (start < end)
        {
            if (!Alphanumeric(str[start]))
            {
                start++;
                continue;
            }
            if (!Alphanumeric(str[end]))
            {
                end--;
                continue;
            }
            if (str[start] != str[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
int main()
{
    isPlaindrome obj("MADAM");
    if (!obj.check())
    {
        cout << "Not Palindrome." << endl;
    }
    else
    {
        cout << "Palindrome." << endl;
    }
}