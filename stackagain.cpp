#include <iostream>
using namespace std;

class stack
{

    int data;
    stack *next;
    stack *top;

public:
    stack()
    {
        next = NULL;
        top = NULL;
    }

    stack(int x)
    {
        data = x;
        next = NULL;
    }

    void push(int x)
    {
        if (top == NULL)
        {
            top = new stack(x);
            return;
        }

        else
        {
            stack *NewNode = new stack(x);
            NewNode->next = top;
            top = NewNode;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            // cout << "Stack Underflow" << endl;
            return;
        }

        else
        {
            cout << top->data << " " << endl;
            stack *temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() const
    {
        if (top == NULL)
        {
            // cout << "Stack Underflow" << endl;
            return -1;
        }

        else
        {
            int top1 = top->data;
            return top1;
        }
    }

    bool empty() const
    {
        if (top == NULL)
        {
            return true;
        }

        return false;
    }
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

    s.empty();

    return 0;
}