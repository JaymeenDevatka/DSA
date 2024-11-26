#include <iostream>
#include <stack>
using namespace std;

bool is_valid(string &str)
{
    int n = str.length();

    stack<char> st;
    bool ans = true;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (st.top() == '{' && !st.empty())
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
            if (st.top() == '(' && !st.empty())
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
            if (st.top() == '[' && !st.empty())
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

    return ans;
}

int main()
{
    string str;
    cin >> str;

    if (is_valid(str))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}