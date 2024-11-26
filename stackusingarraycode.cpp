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
        if (rear == size - 1) // Corrected to equality check
        {
            // cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0; // Set front to 0 when the first element is enqueued
        }

        rear++;
        s[rear] = x;
    }

    int dequeue()
    {
        if (front == -1 || front > rear) // Check for queue underflow
        {
            // cout << "Queue Underflow" << endl;
            return -1;
        }

        int val = s[front];
        front++;
        return val;
    }
};

int main()
{
    queue q;
    int n;
    cin >> n;

    int pop[n];
    int i = 0;

    while (n--)
    {
        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
            int x;
            cin >> x;
            q.enqueue(x); // Corrected to enqueue the input value x
            break;

        case '2':
        {
            int val = q.dequeue();
            if (val != -1)
            {
                pop[i++] = val;
                // cout << val << endl;
            }
        }
        break;

        default:
            cout << "Invalid Choice!" << endl;
        }
    }


    // cout << "Dequeued elements: ";
    for (int j = 0; j < i; j++)
    {
        cout << pop[j] << " ";
    }
    cout << endl;

    return 0;
}
