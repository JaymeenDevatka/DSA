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

bool is_palindrom(node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return true;

    node *slow = *head;
    node *fast = *head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *prev = NULL;
    node *current = slow;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    node *second_half = prev;

    node *first_half = *head;

    while (second_half != NULL)
    {
        if (first_half->data != second_half->data)
            return false;
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return true;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
    cout << "->NULL" << endl;
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
    if (is_palindrom(&head))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}