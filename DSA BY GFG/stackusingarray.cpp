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
    int size = 5;
    int s[5];
    int top;

    stack()
    {
        top = -1;
    }
    void push(int n)
    {
        if (top == size - 1)
        {
            return;
        }
        top++;
        s[top] = n;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }

        int x = s[top--];
        // top--;
        return x;
    }

    int peek()
    {
        if (top == -1)
        {
            return -1;
        }

        int x = s[top];
        // top--;
        return x;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }

        // int x=s[top];
        // top--;
        // return x;
        return false;
    }

    // int Size_Of_Stack()
    // {
    //     int  
    // }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    s.pop();

    cout << s.peek() << endl;
    s.pop();

    cout << s.peek() << endl;
    s.pop();

    cout << s.isEmpty() << endl;

    return 0;
}