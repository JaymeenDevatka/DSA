#include <iostream>
#include <stack>
using namespace std;

int evalute(string str)
{
    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            st.push(str[i] - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            switch (str[i])
            {
            case '+':
                st.push(b + a);
                break;

            case '-':
                st.push(b - a);
                break;

            case '*':
                st.push(b * a);
                break;

            case '/':
                st.push(b / a);
                break;

            default:
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string str = "231*+9-";

    cout << evalute(str) << endl;

    return 0;
}