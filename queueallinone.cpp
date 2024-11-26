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
            return;
        }

        // front++;
        rear++;
        s[rear] = x;

        if (front == -1)
        {
            front = 0;
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            return -1;
        }

        int x = s[front];
        front++;
        return x;
    }

    int peek()
    {
        if (front == -1)
        {
            return -1;
        }

        int y = s[front];
        cout << y << endl;
    }

    bool isEmpty()
    {
        if (front == -1)
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
}
