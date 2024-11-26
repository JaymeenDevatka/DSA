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

class queue
{
public:
    node *front;
    node *rear;

    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(node *&head, int value)
    {
        node *newNode = new node(value);

        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            // newNode=head;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int dequeue()
    {
        if (front == NULL)
        {
            return -1;
        }

        node *todelete = front;
        int val = front->data;
        front = front->next;
        delete todelete;
        return val;
    }
};
