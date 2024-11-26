#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }

    else if (c == '/' || c == '*')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

string infixtopostfix(string str)
{
    stack<char> s;
    string res;

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            res = res + str[i];
        }
        else if (s[i] == '(')
        {
        }
    }
}