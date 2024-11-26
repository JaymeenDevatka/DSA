#include <iostream>
using namespace std;

class stack
{
public:
    int size = 5;
    int s[5];
    int top = -1;

    void push(int x)
    {
        if (top == size - 1)
        {
            return;
        }

        top++;
        s[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }

        int x = s[top];
        top--;
        return x;
    }

    void peek()
    {
        if (top == -1)
        {
            return;
        }

        int x = s[top];
        cout << x << endl;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
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

    s.peek();

    s.pop();
    s.peek();

    s.pop();
    s.peek();

    s.pop();

    s.peek();

    s.isEmpty();
}