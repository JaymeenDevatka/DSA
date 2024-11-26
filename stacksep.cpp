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
    int top;
    node *front;

    stack()
    {
        top = -1;
        front = nullptr;
    }

    void push(int x)
    {
        node *newNode = new node(x);

        // if (front == nullptr)
        // {
        //     return;
        // }

        newNode->next = front;
        front = newNode;
        // top++;
    }

    void pop()
    {
        if (front == nullptr)
        {
            return;
        }

        node *temp = front;

        front = front->next;

        delete temp;
    }

    int peek()
    {
        if (front == nullptr)
        {
            return -1;
        }

        int x = front->data;

        return x;
    }

    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
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

    cout << s.peek() << endl;
    s.pop();
    cout << s.isEmpty() << endl;

    cout << s.peek() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
}