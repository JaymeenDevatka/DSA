#include <iostream>
using namespace std;

class Queue
{
    int size = 10;
    int front;
    int rear;
    int array[10];

public:
    // Constructor
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull()
    {
        return rear == size - 1;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    // Insert an element into the queue (enqueue)
    void push(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0; // If the queue was empty, set front to 0
        }

        rear++;
        array[rear] = x;
    }

    // Remove an element from the queue (dequeue)
    int pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int element = array[front];
        front++;

        // If all elements are dequeued, reset the queue
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }

        return element;
    }

    // Peek the front element
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return array[front];
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;           // Output: 10
    cout << "Pop element: " << q.pop() << endl;              // Output: 10
    cout << "Front element after pop: " << q.peek() << endl; // Output: 20

    return 0;
}
