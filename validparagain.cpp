#include <iostream>
#include <stack>
using namespace std;

bool ValidParenthese(string str)
{
    int n = str.length();
    bool ans = true;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (str[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (str[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }

    if (!st.empty())
    {
        return false;
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;

    if (ValidParenthese(str))
    {
        cout << "true" << endl;
    }

    else
    {
        cout << "false" << endl;
    }
}