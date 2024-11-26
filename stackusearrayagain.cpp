#include <iostream>
using namespace std;

class stack
{
public:
    int size = 5;
    int array[10];
    int top;

    stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        top == -1;
    }

    bool isFull()
    {
        top == size - 1;
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

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        // int x = array[top];
        top--;
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

    return 0;
}