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
    node *front = NULL;
    node *rear = NULL;

    void enqueue(int n)
    {
        node *newNode = new node(n);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
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
        int x = front->data;
        front = front->next;
        delete todelete;
        // cout << x << endl;
        return x;
    }

    void peek()
    {
        if (front == NULL)
        {
            return;
        }

        cout << front->data << endl;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
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

    q.peek();
    cout << q.isEmpty() << endl;
    q.dequeue();

    q.peek();
    cout << q.isEmpty() << endl;
    q.dequeue();

    q.peek();
    cout << q.isEmpty() << endl;
    q.dequeue();

    cout << q.isEmpty() << endl;

    return 0;
}