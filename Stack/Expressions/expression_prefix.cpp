#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Function to get the precedence of an operator
int getPrecedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
    return 0;
}

string infixToPrefix(string s)
{
    stack<char> st;
    string res;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && st.top() != '(' && getPrecedence(st.top()) >= getPrecedence(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout <<"The string after infix to Postfix conversion is: "<<infixToPrefix("(A-B/C)*(A/K-L)") << endl;
    return 0;
}