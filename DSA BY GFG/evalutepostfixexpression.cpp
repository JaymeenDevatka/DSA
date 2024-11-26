#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int EvalutePostFixExpression(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i] - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            switch (str[i])
            {
            case '+':
                s.push(op1 + op2);
                break;

            case '-':
                s.push(op1 - op2);
                break;

            case '*':
                s.push(op1 * op2);
                break;

            case '/':
                if (op2 == 0)
                {
                    return -1;
                }
                s.push(op1 / op2);
                break;

            case '^':
                s.push(int(pow(op1, op2)));
                break;

            default:
                return -1;
            }
        }
    }

    return s.top();
}

int main()
{
    string str;

    getline(cin, str);

    int n = EvalutePostFixExpression(str);

    cout << n << endl;

    return 0;
}