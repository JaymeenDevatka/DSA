#include <iostream>
using namespace std;

class stack
{
public:
    int top;
    int size = 5;
    int array[5];

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
        array[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            return;
        }

        int x = array[top];
        top--;
    }

    bool isEmpty()
    {
        return top == -1;
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
    cout << s.isEmpty() << endl;

    s.pop();

    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;

    s.pop();

    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;

    s.pop();

    cout << s.isEmpty() << endl;

    return 0;
}