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

void insert_at_first(node *&head, int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
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

int find_middle_node(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main()
{
    node *head = NULL;
    insert_at_first(head, 10);
    insert_at_first(head, 20);
    insert_at_first(head, 30);
    insert_at_first(head, 40);

    insert_at_first(head, 50);

    display(head);

    cout << find_middle_node(head) << endl;

    return 0;
}