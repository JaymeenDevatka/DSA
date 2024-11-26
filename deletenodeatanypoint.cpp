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

void insert_at_front(node *&head, int y)
{
    // if (head == NULL)
    // {
    //     return;
    // }

    node *newNode = new node(y);
    newNode->next = head;
    head = newNode;
}

void delete_node_at_any_point(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete_at_head(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void delete_at_head(node *&head)
{
    node *temp = head;
    head = head->next;

    delete temp;
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
    insert_at_front(head, 40);
    insert_at_front(head, 50);

    display(head);

    delete_at_head(head);

    display(head);

    delete_at_head(head);

    display(head);

    delete_at_head(head);

    display(head);

    delete_at_head(head);

    display(head);

    delete_at_head(head);

    display(head);

    return 0;
}