#include <iostream>
using namespace std;

class stack
{
    int size = 3;
    int array[3];
    int top;

public:
    stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void push(int n)
    {
        if (isFull())
        {
            return;
        }

        top++;
        array[top] = n;
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }

        int x = array[top];

        top--;
        return x;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }

        int x = array[top];
        return x;
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
    cout << s.isFull() << endl;

    cout << s.peek() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;

    cout << s.peek() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;

    return 0;
}