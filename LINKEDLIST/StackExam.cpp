#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = nullptr;
    }
};

class Stack
{
public:
    Node *top; // Points to the top node

    Stack()
    {
        top = nullptr; // Initially, stack is empty
    }

    void push(int n)
    {
        Node *newNode = new Node(n); // Create a new node
        newNode->next = top;         // Link the new node to the current top
        top = newNode;               // Update top to the new node
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }

        Node *temp = top; // Save the current top node
        top = top->next;  // Move top to the next node
        delete temp;      // Delete the old top node
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty, nothing to peek." << endl;
            return -1; // Return a sentinel value for empty stack
        }

        return top->data; // Return the data of the top node
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    cout << "After popping, top element is: " << s.peek() << endl;

    return 0;
}
