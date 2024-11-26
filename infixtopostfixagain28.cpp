#include <iostream>
#include <stack>

using namespace std;

int prec(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '/' || ch == '*')
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
        char c = str[i];

        if (c >= 'a' && c <= 'z') // Operand
        {
            result += c;
        }
        else if (c == '(') // Left Parenthesis
        {
            st.push(c);
        }
        else if (c == ')') // Right Parenthesis
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
            {
                st.pop(); // Pop the '(' from the stack
            }
        }
        else // Operator
        {
            while (!st.empty() && prec(st.top()) >= prec(c))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string str;
    cin >> str;

    cout << infixtopostfix(str) << endl;

    return 0;
}