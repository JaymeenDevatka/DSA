#include<iostream>
#include<stack>
using namespace std;

int prec(char ch)
{
    if(ch == '^')
    {
        return 3;
    }
    else if(ch == '/' || ch == '*')
    {
        return 2;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }

    else 
    {
        return -1;
    }
}

bool InfixToPostfix(string str)
{
    stack<char> st;
    string postfix;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            postfix = postfix + str[i];
        }
        else if(str[i] == '(')
        {
            st.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(st.top() == '(' && !st.empty())
            
        }
    }
}