#include <iostream>
using namespace std;

class queue
{
public:
    int front;
    int rear;
    int size;
    int array[10];

    queue(int x)
    {
        size = x;
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    bool isEmpty()
    {
        return front = -1 || rear > front;
    }

    void push(int x)
    {
        if (isFull())
        {
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        array[rear] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        int x = array[front];
        front++;
    }

    int peek()
    {
        if(isEmpty())
        {
            return;
        }


    }
};

