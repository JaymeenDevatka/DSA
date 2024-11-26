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
        next = NULL;
    }
};

class stack
{
public:
    node *top;

    stack()
    {
        top = NULL;
    }

    void push(int n)
    {
        node *newNode = new node(n);

        // if (top == NULL)
        // {
        //     top = newNode;
        //     return;
        // }

        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            return;
        }

        node *temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return;
    }

    int peek()
    {
        if (top == NULL)
        {
            return -1;
        }

        int x = top->data;
        return x;
    }

    bool isEmpty()
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