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
        next = nullptr;
        pre = nullptr;
    }
};

void insert_at_front(node *&head, int x)
{
    node *newNode = new node(x);
    newNode->next = head;

    if (head != nullptr)
    {
        head->pre = newNode;
    }
    head = newNode;
}

void insert_at_last(node *&head, int x)
{
    node *newNode = new node(x);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->pre = temp;
}

void insert_at_position(node *&head, int pos, int x)
{
    if (pos == 1)
    {
        insert_at_front(head, x); // Insert at the front
        return;
    }

    node *newNode = new node(x);
    node *temp = head;
    int count = 1;

    while (temp != nullptr && count < pos - 1) // Traverse to the (pos-1)th node
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) // Insert at the end if position is beyond the last node
    {
        insert_at_last(head, x);
    }
    else
    {
        // Inserting between two nodes
        newNode->next = temp->next;
        newNode->pre = temp;

        if (temp->next != nullptr)
        {
            temp->next->pre = newNode; // Update the previous pointer of the next node
        }

        temp->next = newNode;
    }
}

void display(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    node *head = nullptr;
    // insert_at_front(head, 10);
    // insert_at_front(head, 20);
    // insert_at_front(head, 30);

    insert_at_last(head, 10);
    insert_at_last(head, 20);
    insert_at_last(head, 30);

    display(head);

    return 0;
}