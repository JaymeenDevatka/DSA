#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isvalid(string str)
{
    int n = str.length();
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
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

    if (isvalid(str))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}