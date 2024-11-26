#include <iostream>
using namespace std;

// class node
// {
//     public:
//     int data;
//     node* next;

//     node(int x)
//     {
//         data=x;
//         next=nullptr;
//     }
// };

class stack
{
public:
    int top;
    int size = 5;
    int array[5];

    stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            return;
        }

        top++;
        array[top] = x;
    }

    void pop()
    {
        if (top == - 1)
        {
            return;
        }

        top--;
    }

    int peek()
    {
        if (top == - 1)
        {
            return -1;
        }

        int x = array[top];
        return x;
    }

    bool isEmpty()
    {
        if (top == - 1)
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