#include <iostream>
using namespace std;

class node
{
public:
    static int data;
    static node *next;
    
    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class stack
{
public:
    static node *top;

    stack()
    {
        top = nullptr;
    }

    static void push(int x)
    {
        node *newNode = new node(x);
        newNode->next = top;
        top = newNode;
    }

    static void pop()
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }

    static void display()
    {
        node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    push(1);
    push(2);
    push(3);

    s.display();

    s.pop();

    s.display();

    s.pop();

    s.display();

    s.pop();

    s.display();
    return 0;
}