#include <iostream>
using namespace std;

class Queue
{
    int size = 10;
    int front;
    int rear;
    int array[10];

    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int x)
    {
        if ()
    }
}