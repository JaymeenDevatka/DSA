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
        if (front == -1)
        {
            front = 0; 
        }
        rear++;
        s[rear] = x;
    }

    int dequeue()
    {
        if (front == -1 || front > rear)
        {
            return -1;
        }

        int x = s[front];
        front++;
        if (front > rear) 
        {
            front = rear = -1;
        }
        return x;
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            return -1;
        }

        return s[front];
    }

    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl; 
    q.dequeue();

    cout << q.peek() << endl; 
    q.dequeue();

    cout << q.peek() << endl;  
    q.dequeue();

    cout << q.isEmpty() << endl; 

    return 0;
}
