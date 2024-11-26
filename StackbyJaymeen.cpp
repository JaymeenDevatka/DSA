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
            return -1;
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
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.isEmpty() << endl;

    s.pop();
    cout << s.isEmpty() << endl;

    s.pop();
    cout << s.isEmpty() << endl;

    s.pop();
    cout << s.isEmpty() << endl;
}