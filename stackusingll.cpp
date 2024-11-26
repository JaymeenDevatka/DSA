#include <iostream>
using namespace std;

// class node
// {
// public:
//     int data;
//     node *next;

//     node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };

class stack
{
public:
    // int size = 5;
    // int s[5];
    stack *top;
    int data;
    stack *next;

    stack()
    {
        next = NULL;
    }
    stack(int x)
    {
        data = x;
        next = NULL;
    }

    void push(int n)
    {
        if (top == NULL)
        {
            top = new stack(n);
            return;
        }
        stack *newNode = new stack(n);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if(top == NULL)
        {
            return;
        }
        else
        {
            stack *temp=top;
            top=top->next;
            delete temp;
        }
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

}