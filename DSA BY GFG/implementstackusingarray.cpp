#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class stack
{
public:
    int size = 10;
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

    int peek()
    {
        if (top == -1)
        {
            return -1;
        }

        int x = s[top];
        return x;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }

        // int x = s[top];
        // return x;

        return false;
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek() << endl;
    s.pop();
    cout << s.isEmpty() << endl;

    cout << s.peek() << endl;
    s.pop();
    cout << s.isEmpty() << endl;

    cout << s.peek() << endl;
    s.pop();
    // cout << s.isEmpty() << endl;

    // cout << s.peek() << endl;
    // s.pop();
    cout << s.isEmpty() << endl;

    return 0;
}