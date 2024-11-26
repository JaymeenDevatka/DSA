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
    node *front;
    node *rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            rear = n;
            front = n;
            return;
        }

        rear->next = n;
        rear = n;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            // rear=n;
            // front=n;
            return;
        }

        node *todelete = front;
        front = front->next;

        delete todelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            // rear=n;
            // front=n;
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {
            // rear=n;
            // front=n;
            return true;
        }

        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.empty() << endl;

    return 0;
}