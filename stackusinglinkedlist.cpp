#include <iostream>
using namespace std;

class stack
{
public:
    int data;
    stack *next;
    stack *top = NULL;

    stack()
    {
        next = NULL;
    }
    stack(int val)
    {
        data = val;
        next = NULL;
    }

    void push(int n)
    {
        if (top == NULL)
        {
            top = new stack(n);
            return;
        }
        else
        {
            stack *newNode = new stack(n);
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        else
        {
            cout << top->data << " ";
            stack *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    stack s;
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.pop();
    return 0;
}