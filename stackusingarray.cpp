#include <iostream>
using namespace std;

class Stack
{
    int size = 5;
    int s[5];
    int top = 0;

public:
    void push(int n)
    {
        if (top == size - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        s[top++] = n;
    }

    int pop()
    {
        if (top == 0)
        {
            cout << "Underflow" << endl;
            return -1; // or throw an exception
        }
        int x = s[--top];
        cout << x << " ";
        return x;
    }
};

int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.pop();

    return 0;
}