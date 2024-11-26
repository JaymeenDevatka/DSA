#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char ch)
{
    // If the character is a digit then it must
    // be an operand
    return isdigit(ch);
}

double evaluatePrefix(string str)
{
    stack<double> st;

    for (int i = str.size() - 1; i >= 0; i--)
    {

        // Push operand to Stack
        // To convert exprsn[j] to digit subtract
        // '0' from exprsn[j].
        if (isOperand(str[i]))
        {
            st.push(str[i] - '0');
        }

        else
        {

            // Operator encountered
            // Pop two elements from Stack
            double o1 = st.top();
            st.pop();
            double o2 = st.top();
            st.pop();

            // Use switch case to operate on o1
            // and o2 and perform o1 Or o2.
            switch (str[i])
            {
            case '+':
                st.push(o1 + o2);
                break;
            case '-':
                st.push(o1 - o2);
                break;
            case '*':
                st.push(o1 * o2);
                break;
            case '/':
                st.push(o1 / o2);
                break;
            }
        }
    }

    return st.top();
}

// Driver code
int main()
{
    string str;
    cin >> str;
    cout << evaluatePrefix(str) << endl;
    return 0;
}