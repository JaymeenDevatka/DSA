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

int FindNumberOfNodes(node *&head)
{
    if (head == NULL)
    {
        return -1;
    }

    node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void Insert_at_front(node *&head, int y)
{
    node *newNode = new node(y);
    newNode->next = head;
    head = newNode;
}

void display(node *&head)
{
    node *temp = head;

    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    Insert_at_front(head, 10);
    Insert_at_front(head, 20);
    Insert_at_front(head, 30);
    Insert_at_front(head, 40);
    Insert_at_front(head, 50);

    cout << FindNumberOfNodes(head) << endl;

    return 0;
}