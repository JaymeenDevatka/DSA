#include <iostream>
using namespace std;

class stack
{
public:
    int size = 5;
    int s[5];
    int top;

    stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            // cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        s[top] = x;
    }

    int pop()
    {

        if (top == -1)
        {
            // cout << "Stack Underflow" << endl;
            return -1;
        }
        int x = s[--top];
        // top--;
        return x;
    }

    int peek()
    {
        if (top == 0)
        {
            // cout << "Stack Underflow" << endl;
            return -1;
        }

        int x = s[top];

        return x;
    }

    bool isEmpty()
    {
        if (top == 0)
        {
            // cout << "Stack Underflow" << endl;
            return true;
        }

        return false;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    // s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}