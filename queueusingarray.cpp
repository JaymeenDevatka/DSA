#include <iostream>
using namespace std;

class Queue
{
private:
    int size = 5;
    int array[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        rear++;
        array[rear] = x;

        if (front == -1)
        {
            front = 0;
        }
    }

    int dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1; // Return an error value
        }

        int val = array[front];
        front++;
        return val;
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1; // Return an error value
        }

        return array[front];
    }

    bool empty()
    {
        return (front == -1 || front > rear);
    }
};

int main()
{
    Queue q;
    // queue q;
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
