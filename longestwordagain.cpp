#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    int top;

    node(int x)
    {
        data = x;
        next = nullptr;
        top = -1;
    }
};

class queue
{
public:
    node *front;
    node *rear;
    int size;

    queue()
    {
        front = nullptr;
        rear = nullptr;
        size = -1;
    }

    void enqueue(int x)
    {
        node *newnode = new node(x);
        if (rear == nullptr)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }

        size++;
    }

    void dequeue()
    {
        if (front == nullptr)
        { // If queue is empty
            // cout << "Queue is empty, nothing to DeQueue\n";
            return;
        }

        node *temp = front;
        front = front->next;

        // If front becomes nullptr, set rear to nullptr too
        if (front == nullptr)
        {
            rear = nullptr;
        }

        // cout << temp->data << " removed from the queue\n";
        delete temp;
        size--;
    }
}