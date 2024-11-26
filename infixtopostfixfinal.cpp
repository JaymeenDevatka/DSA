#include <iostream>
#include <stack>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
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
    stack<char> st;

    string result;

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            result = result + str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() == '(')
            {
                result = result + st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && prec(st.top()) >= prec(str[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}