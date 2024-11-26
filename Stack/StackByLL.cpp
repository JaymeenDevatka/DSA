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

class Stack
{
public:
    node *top;

    Stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        node *newNode = new node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            return;
        }

        top = top->next;
    }

    int peek()
    {
        if (top == nullptr)
        {
            return -1;
        }
        // top = top->next;
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main()
{
    Stack s;

    cout << s.isEmpty() << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.isEmpty() << endl;
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.isEmpty() << endl;

    return 0;
}