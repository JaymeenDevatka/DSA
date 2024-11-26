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
        next = nullptr;
    }
};

class stack
{
public:
    node *top;

    stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        node *newNode = new node(x);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }

        node *temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.isEmpty() << endl;

    s.pop();
    s.pop();
    s.pop();

    cout << s.isEmpty() << endl;
}