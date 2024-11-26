#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int front;
    int rear;
    int *array;
    int size;

public:
    CircularQueue(int n)
    {
        front = -1;
        rear = -1;
        array = new int[n];
        this->size = n;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void Enqueue(int n)
    {
        if (isFull())
        {
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % size;

        array[rear] = n;
    }

    int deQueue()
    {
        if (isEmpty())
        {
            return -1;
        }

        front = (front + 1) % size;

        return array[front];
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }

        return array[front];
    }
};

int main()
{
    CircularQueue cq(5);

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);

    cout << "Dequeued: " << cq.deQueue() << endl; // Output: Dequeued: 10
    cout << "Peek: " << cq.peek() << endl;        // Output: Peek: 20

    cq.Enqueue(40);
    cq.Enqueue(50);

    cout << "Dequeued: " << cq.deQueue() << endl; // Output: Dequeued: 20
    cout << "Peek: " << cq.peek() << endl;        // Output: Peek: 30
}