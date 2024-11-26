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

node *middle_node_find(node *&head)
{
    node *temp = head;
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *reverse_linked_list(node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *pre = NULL;
    node *temp = head;
    node *nextN;

    while (temp != NULL)
    {
        nextN = temp->next;
        temp->next = pre;

        pre = temp;

        temp = nextN;
    }

    return pre;
}

bool isPalindrome(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    node *middle = middle_node_find(head);
    node *SecondHalfStart = reverse_linked_list(middle->next);

    node *FirstHalfStart = head;

    while (SecondHalfStart != NULL)
    {
        if (FirstHalfStart->data != SecondHalfStart->data)
        {
            return false;
        }

        FirstHalfStart = FirstHalfStart->next;
        SecondHalfStart = SecondHalfStart->next;
    }

    return true;
}

void insert_at_front(node *&head, int value)
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
int main()
{
    node *head = NULL;

    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);
    insert_at_front(head, 20);
    insert_at_front(head, 10);

    display(head);

    if (isPalindrome(head))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}