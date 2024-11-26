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
    newNode->pre = nullptr;
    head = newNode;
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

    temp->next = nullptr;
}

void delete_all_node(node *&head)
{

    while (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}
void display(node *&head)
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

    // delete_at_last(head);

    // display(head);

    delete_all_node(head);

    display(head);

    return 0;
}