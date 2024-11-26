#include <iostream>
using namespace std;

class queue
{
public:
    int size = 5;
    int s[5];
    int front;
    int rear;

    queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int y)
    {
        if (rear = size - 1)
        {
            // cout << "Queue Overflow" << endl;
            return;
        }

        rear++;
        s[rear] = y;

        if (front = -1)
        {
            front = 0;
        }
    }

    int dequeue()
    {
        if (front == -1 || front > rear)
        {
            // cout << "Queue Underflow" << endl;
            return -1;
        }

        int x = s[front];
        front++;
        return x;
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            // cout << "Queue Underflow" << endl;
            return -1;
        }

        int y = s[front];
        return y;
    }

    bool Isempty()
    {
        if (front == -1 || front > rear)
        {
            // cout << "Queue Underflow" << endl;
            return true;
        }

        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    cout << q.peek() << endl;

    q.dequeue();
    cout << q.peek() << endl;

    q.dequeue();
    cout << q.peek() << endl;

    q.Isempty();

    return 0;
}