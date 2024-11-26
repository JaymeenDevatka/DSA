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
    void enqueue(int n)
    {
        node *newNode = new node(n);
        if (rear == NULL)
        {
            front = rear = newNode;
        }

        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // int dequeue()
    // {
    int dequeue()
    {
        if (front == NULL)
        {
            // cout << "Queue underflow" << endl;
            return -1;
        }
        int value = front->data;
        node *temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
        return value;
    }
    // }
};
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}