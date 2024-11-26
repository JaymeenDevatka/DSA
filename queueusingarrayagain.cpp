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

    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "queue overflow" << endl;
            return;
        }

        rear++;
        s[rear] = x;
    }

    int dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "queue underflow" << endl;
        }

        int val = s[front];
        front++;

        return val;
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "queue underflow" << endl;
            return -1;
        }

        return s[front];
    }

    bool empty()
    {
        if (front == -1 || front > rear)
        {
            cout << "queue underflow" << endl;
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

    q.empty();

    return 0;
}