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
        next = nullptr;
    }
};

class Queue
{
public:
    node *front;
    node *rear;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void push(int x)
    {
        node *newNode = new node(x);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        node *temp = front;
        front = front->next;
        delete temp;
        if(front == nullptr)
        {
            rear = nullptr;
        }
    }

    void display()
    {
        node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue s;

    cout << s.isEmpty() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    s.pop();

    s.display();

    cout << s.isEmpty() << endl;

    return 0;
}