#include <iostream>
#include <stack>
using namespace std;

int EvalutePostfix(string &str)
{
    int n = str.length();

    stack<char> s;
    // bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 0 && str[i] <= 9)
        {
            s.push(str[i] - '0');
        }
        else
        {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();

            switch (str[i])
            {
            case '+':
                s.push(B + A);
                break;

            case '-':
                s.push(B - A);
                break;

            case '*':
                s.push(B * A);
                break;

            case '/':
                s.push(B / A);
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    string str;
    cin >> str;

    cout << EvalutePostfix(str) << endl;

    return 0;
}