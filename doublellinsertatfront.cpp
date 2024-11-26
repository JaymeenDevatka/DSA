#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *pre;
    node *next;

    node(int x)
    {
        data = x;
        pre = nullptr;
        next = nullptr;
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

void insert_at_last(node *head, int x)
{
    node *newNode = new node(x);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->pre = temp;

    newNode->next = NULL;
}

void insert_at_any_point(node *&head, int x, int position)
{
    node *temp = head;

    if (position == 1)
    {
        insert_at_front(head, x);
        return;
    }

    node *temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr) // If position is out of bounds
    {
        cout << "Position out of bounds." << endl;
        return;
    }

    node *newNode = new node(x);

    newNode->next = temp->next; // Link the new node to the node after the position
    if (temp->next != nullptr)
    {
        temp->next->pre = newNode; // Update the previous pointer of the next node if it exists
    }

    temp->next = newNode; // Link the current node to the new node
    newNode->pre = temp;
}
void delete_at_front(node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    node *temp = head;
    head = head->next;

    delete temp;
}

void delete_at_last(node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}
void display(node *head)
{
    node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
int main()
{
    node *head = nullptr;

    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);

    display(head);

    // insert_at_last(head, 40);
    // insert_at_last(head, 50);
    // insert_at_last(head, 60);

    // display(head);

    delete_at_front(head);

    // delete_at_last(head);

    display(head);

    return 0;
}