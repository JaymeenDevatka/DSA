#include<iostream>
#include<stack>
using namespace std;

int prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '/' || c == '*')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtopostfix(string str)
{
    stack<char> s;
    string res;

    for(int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        // If the character is an operand, add it to the result
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            res += c;
        }
        // If the character is '(', push it to the stack
        else if(c == '(')
        {
            s.push(c);
        }
        // If the character is ')', pop and output from the stack 
        // until an '(' is encountered
        else if(c == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                res += s.top();
                s.pop();
            }
            if(!s.empty() && s.top() == '(')
            {
                s.pop();
            }
        }
        // If an operator is encountered
        else
        {
            while(!s.empty() && prec(s.top()) >= prec(c))
            {
                res += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all the operators from the stack
    while(!s.empty())
    {
        res += s.top();
        s.pop();
    }

    return res;
}

int main()
{
    string str;
    // cout << "Enter infix expression: ";
    cin >> str;

    cout << infixtopostfix(str) << endl;

    return 0;
}
