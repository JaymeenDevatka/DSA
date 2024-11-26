#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class queue
{
public:
    node *front;
    node *rear;

    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x)
    {
        node *n = new node(x);

        if (front == NULL)
        {
            rear = n;
            front = n;
            return;
        }

        rear->next = n;
        rear = n;
    }

    int dequeue()
    {
        if (front == NULL)
        {
            return -1;
        }

        node *todelete = front;
        int val = front->data;
        front = front->next;
        delete todelete;
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
        {
            int x;
            cin >> x;
            q.enqueue(x);
            break;
        }

        case '2':
        {
            int val = q.dequeue();
            if (val != -1)
            {
                pop[i++] = val;
            }
            break;
        }

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
