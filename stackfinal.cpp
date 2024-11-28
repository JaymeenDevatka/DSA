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

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int x)
    {
        node *newNode = new node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        node *temp = top;
        top = top->next;
        delete temp;
    }

    void display()
    {
        node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    cout << s.isEmpty() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    s.pop();

    s.display();

    cout << s.isEmpty() << endl;

    return 0;
}