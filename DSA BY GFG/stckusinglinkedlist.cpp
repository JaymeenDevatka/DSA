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

class stack
{
private:
    node *top; // Pointer to the top node in the stack

public:
    stack()
    {
        top = NULL; // Initialize top as NULL
    }

    void push(int x)
    {
        node *newNode = new node(x);
        if (top == NULL) // If the stack is empty
        {
            top = newNode;
        }
        else
        {
            newNode->next = top; // Link the new node to the current top
            top = newNode;       // Update top to the new node
        }
    }

    int pop()
    {
        if (top == NULL) // If the stack is empty
        {
            // cout << "Stack underflow" << endl;
            return -1;
        }
        int value = top->data; // Get the data from the top node
        node *temp = top;      // Store the top node to delete it later
        top = top->next;       // Move the top pointer to the next node
        delete temp;           // Delete the old top node
        return value;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data; // Return the data of the top node
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl; // 30
    cout << "Pop: " << s.pop() << endl;          // 30

    cout << "Top element: " << s.peek() << endl; // 20
    cout << "Pop: " << s.pop() << endl;          // 20

    cout << "Top element: " << s.peek() << endl; // 10
    cout << "Pop: " << s.pop() << endl;          // 10

    cout << "Is stack empty? " << s.isEmpty() << endl; // 1 (true)

    return 0;
}
