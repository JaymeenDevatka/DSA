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

class Queue
{
public:
    node *front;
    node *rear;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void EnQueue(int x)
    {
        node *newNode = new node(x);
        if (front == nullptr)
        {
            rear = newNode;
            front = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void deQueue()
    {
        if (front == nullptr)
        {
            return;
        }

        node *todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()  
    {
        if (front == nullptr)
        {
            return -1;
        }

        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue q;
    cout << q.isEmpty() << endl;
    q.EnQueue(10);

    q.EnQueue(20);

    q.EnQueue(30);

    cout << q.isEmpty() << endl;

    cout << q.peek() << endl;
    q.deQueue();

    cout << q.peek() << endl;
    q.deQueue();

    cout << q.peek() << endl;
    q.deQueue();

    cout << q.isEmpty() << endl;
}