#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size = 5;
    int array[5];

    Stack()
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

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        array[++top] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1; // Returning a placeholder value
        }
        return array[top];
    }
};

int main()
{
    Stack s;

    cout << s.isEmpty() << endl; // Should print 1 (true)

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.isFull() << endl; // Should print 1 (true)

    cout << s.peek() << endl; // Should print 50
    s.pop();
    cout << s.isEmpty() << endl; // Should print 0 (false)

    cout << s.peek() << endl; // Should print 40
    s.pop();
    cout << s.isEmpty() << endl; // Should print 0 (false)

    cout << s.peek() << endl; // Should print 30
    s.pop();
    cout << s.isEmpty() << endl; // Should print 0 (false)

    cout << s.peek() << endl; // Should print 20
    s.pop();
    cout << s.isEmpty() << endl; // Should print 0 (false)

    cout << s.peek() << endl; // Should print 10
    s.pop();
    cout << s.isEmpty() << endl; // Should print 1 (true)

    return 0;
}