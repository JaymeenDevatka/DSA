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

    void enqueue(int x)
    {
        node *newNode = new node(x);
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
        // node* temp=head;
        if (front == NULL)
        {
            return -1;
        }

        node *todelete = front;
        int y = front->data;
        front = front->next;
        delete todelete;
        return y;
    }

    int peek()
    {
        if (front == NULL)
        {
            return -1;
        }

        int x = front->data;
        return x;
    }

    bool isEmpty()
    {
        if (front == NULL)
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
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // q.dequeue();
    cout << q.isEmpty() << endl;
    cout << q.peek() << endl;

    cout << q.isEmpty() << endl;
    q.dequeue();
    cout << q.peek() << endl;

    cout << q.isEmpty() << endl;
    q.dequeue();
    cout << q.peek() << endl;

    cout << q.isEmpty() << endl;

    return 0;
}