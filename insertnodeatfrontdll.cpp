#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *pre;

    node(int x)
    {
        data = x;
        next = NULL;
        pre = NULL;
    }
};

void insert_at_front(node *&head, int value)
{
    node *newNode = new node(value);
    // node *temp = head;

    if (head == NULL)
    {
        head = newNode;
    }
    {
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
    }
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);

    display(head);

    return 0;
}