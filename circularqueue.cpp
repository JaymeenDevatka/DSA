#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *array;
    int size;
    int rear;
    int front;

public:
    CircularQueue(int n)
    {
        array = new int[n];
        this->size = n;
        rear = -1;
        front = -1;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void enQueue(int n)
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

        int result = array[front];

        if (front == rear)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        return result;
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

    cq.enQueue(10);
    cq.enQueue(20);
    cq.enQueue(30);

    cout << "Dequeued: " << cq.deQueue() << endl; // Output: Dequeued: 10
    cout << "Peek: " << cq.peek() << endl;        // Output: Peek: 20

    cq.enQueue(40);
    cq.enQueue(50);

    cout << "Dequeued: " << cq.deQueue() << endl; // Output: Dequeued: 20
    cout << "Peek: " << cq.peek() << endl;        // Output: Peek: 30
}