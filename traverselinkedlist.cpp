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

void traverse(node *&head)
{
    node *temp = head;

    int count = 0;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        count++;
    }

    cout << "NULL" << endl;
    cout << "Total Nodes: " << count << endl;
}

void insert_at_front(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

void delete_at_front(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void display(node *&head)
{
    node *temp = head;

    // int count = 0;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        // count++;
    }

    cout << "NULL" << endl;
    // cout << "Total Nodes: " << count << endl;
}
int main()
{
    node *head = NULL;
    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);
    insert_at_front(head, 40);
    insert_at_front(head, 50);

    traverse(head);

    delete_at_front(head);

    display(head);

    delete_at_front(head);

    display(head);

    delete_at_front(head);

    display(head);

    delete_at_front(head);

    display(head);

    delete_at_front(head);

    display(head);

    // delete_at_front(head);

    // display(head);

    return 0;
}