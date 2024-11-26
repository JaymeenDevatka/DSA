#include <iostream>
#include <stack>
using namespace std;

// class Stack
// {
//     int size = 5;
//     int s[5];
//     int top = 0;

// public:
//     void push(int n)
//     {
//         if (top == size - 1)
//         {
//             cout << "Overflow" << endl;
//             return;
//         }
//         s[top++] = n;
//     }

//     int pop()
//     {
//         if (top == 0)
//         {
//             cout << "Underflow" << endl;
//             return -1; // or throw an exception
//         }
//         int x = s[--top];
//         cout << x << " ";
//         return x;
//     }
// };

bool is_valid(string str)
{
    int n = str.length();

    stack<char> st;
    bool ans = true;
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