#include <iostream>
#include <stack>

using namespace std;

bool validparenthese(string str)
{
    int n = str.length();

    stack<char> s;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (s.top() == '{')
            {
                s.pop();
                // break;
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                // break;
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (str[i] == ']')
        {
            if (s.top() == '[')
            {
                s.pop();
                // break;
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

    if (validparenthese(str))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}