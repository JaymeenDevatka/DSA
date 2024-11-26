#include <iostream>
#include <stack>
using namespace std;

bool is_Valid(string str)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
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
    cout << "Enter a string: ";
    cin >> str;

    if (is_Valid(str))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}