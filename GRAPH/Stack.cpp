#include <iostream>
using namespace std;

class Stack
{
    int size = 5;
    int array[5];
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

        top++;
        array[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }

        int x = array[top];
        top--;
        return x;
    }

    int peek()
    {
        if (top == -1)
        {
            return -1;
        }

        int x = array[top];
        return x;
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
}