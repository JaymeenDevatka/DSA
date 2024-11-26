#include <iostream>
#include <stack>
#include <algorithm>
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
    string postfix;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (c >= 'a' && c <= 'z')
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

string InfixToPrefix(string str)
{
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }

    string postfix123 = infixtopostfix(str);

    reverse(postfix123.begin(), postfix123.end());

    return postfix123;
}

int main()
{
    string str;
    cin >> str;

    cout << InfixToPrefix(str) << endl;

    return 0;
}