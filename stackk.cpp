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
    int size = 5;
    int top1;
    int array[5];

    stack()
    {
        top = nullptr;
        top1 = -1;
    }

    void pusharray(int x)
    {
        if(top1 == -1)
        {
            top1=0;
        }

        array[top1] = x;
    }

    void pushll(int x)
    {
        node* newNode = new node(x);
        newNode->next = top;
        top=
    }
}