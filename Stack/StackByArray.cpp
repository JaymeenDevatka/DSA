#include <iostream>
using namespace std;

class Stack
{
    int size = 10;
    int array[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            return;
        }

        if (top == -1)
        {
            top = 0;
        }

        array[++top] = x;
    }

    void pop()
    {
        if (top == -1)
        {

            return;
        }

        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int x = array[top];
        return x;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek() << endl;
    s.pop();

    cout << s.peek() << endl;
    s.pop();

    cout << s.peek() << endl;
    s.pop();

    // cout << s.peek() << endl;
}