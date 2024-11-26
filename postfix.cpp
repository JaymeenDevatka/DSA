#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '/' || ch == '*') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string str) {
    stack<char> st;
    string result;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            result = result + str[i];
        } else if (str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                result = result + st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        } else {
            while (!st.empty() && prec(st.top()) > prec(str[i])) {
                result = result + st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while (!st.empty()) {
        result = result + st.top();
        st.pop();
    }

    return result;
}

string InfixToPrefix(string str) {
    reverse(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ')') {
            str[i] = '(';
        } else if (str[i] == '(') {
            str[i] = ')';
        }
    }

    string postfix = infixToPostfix(str);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string str;
    cin >> str;

    cout << InfixToPrefix(str) << endl;

    return 0;
}