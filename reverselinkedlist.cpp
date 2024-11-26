#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

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

void reverse_linked_list(node **head)
{
    node *current = *head;
    node *next = NULL;
    node *previous = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
}

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        return 1;
    }

    node *head = NULL;
    node *temp = NULL;

    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;

        if (head == NULL)
        {
            head = new node(value);
            temp = head;
        }
        else
        {
            temp->next = new node(value);
            temp = temp->next;
        }
    }

    reverse_linked_list(&head);

    display(head);
    cout << endl;

    return 0;
}