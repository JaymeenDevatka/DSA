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

bool HasCycle(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "false" << endl;
        return false;
    }

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "true" << endl;
            return true;
        }
    }

    // cout << "false" << endl;
    return false;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void insert_at_front(node *&head, int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

int main()
{
    node *head = NULL;

    insert_at_front(head, 1);
    insert_at_front(head, 2);
    insert_at_front(head, 3);
    insert_at_front(head, 4);

    insert_at_front(head, 5 );

    display(head);

    head->next->next->next->next->next = head->next->next;

    HasCycle(head);

    return 0;
}