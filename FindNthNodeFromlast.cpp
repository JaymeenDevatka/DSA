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

node *find_nth_node_from_last(node *&head, int val)
{
    if (head->next == NULL)
    {
        return NULL;
    }

    node *temp = head;

    int count = 0;
    while (temp != NULL)
    {

        temp = temp->next;
        count++;
    }

    if (val == count)
    {
        return head->next;
    }
    int IndexToSearch = count - val;
    int i = 0;
    temp = head;
    while (i < IndexToSearch)
    {
        temp = temp->next;
        i++;
    }

    temp->next = temp->next->next;

    return head;

    // cout << "Length of Linked List is: " << count << endl;
}

void Insert_at_front(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

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

int main()
{
    node *head = NULL;

    Insert_at_front(head, 10);
    Insert_at_front(head, 20);
    Insert_at_front(head, 30);

    display(head);

    node *newNode = find_nth_node_from_last(head, 10);

    display(newNode);

    return 0;
}