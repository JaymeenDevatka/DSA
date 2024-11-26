#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int *s;
    int top;

public:
    Stack(int sz = 5)
    {
        size = sz;
        s = new int[size];
        top = -1;
    }

    ~Stack()
    {
        delete[] s;
    }

    void push(int n)
    {
        if (top == size - 1)
        {
            // Stack Overflow
            return;
        }
        s[++top] = n;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1; // Stack Underflow
        }
        return s[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            return -1; // No element in Stack
        }
        return s[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    int n;
    cin >> n;

    Stack s;
    while (n--)
    {
        int op;
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int x;
            cin >> x;
            s.push(x);
            break;
        }
        case 2:
        {
            cout << s.pop() << endl;
            break;
        }
        case 3:
        {
            cout << s.peek() << endl;
            break;
        }
        case 4:
        {
            cout << (s.isEmpty() ? 1 : 0) << endl;
            break;
        }
        }
    }

    return 0;
}
