#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *pre;

    // public:
    node(int x)
    {
        data = x;
        next = nullptr;
        pre = nullptr;
    }
};

void insert_at_front(node *&head, int x)
{
    if (head == nullptr)
    {
        return;
    }

    node *newNode = new node(x);
    
}