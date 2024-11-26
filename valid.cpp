#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (st.empty())
            {
                cout << "false" << endl;
                return 0;
            }

            char ch = st.top();

            if ((str[i] == ')' && ch == '(') ||
                (str[i] == ']' && ch == '[') ||
                (str[i] == '}' && ch == '{'))
            {
                st.pop();
            }
            else
            {
                cout << "false" << endl;
                return 0;
            }
        }
    }

    // If the stack is empty after processing, all parentheses are matched
    if (st.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
