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

node *reverse_linked_list(node *&head)
{
    node *pre = NULL;

    node *cur = head;
    node *nextptr;

    while (cur != NULL)
    {
        nextptr = cur->next;
        cur->next = pre;

        pre = cur;
        cur = nextptr;
    }

    return pre;
}

node *middlenode(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
bool isPalindrome(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    node *middle = middlenode(head);
    node *secondhalfstart = reverse_linked_list(middle->next);

    node *firsthalfstart = head;

    while (secondhalfstart != NULL)
    {
        if (firsthalfstart->data != secondhalfstart->data)
        {
            return false;
        }

        firsthalfstart = firsthalfstart->next;
        secondhalfstart = secondhalfstart->next;
    }

    return true;
}

int main()
{
    node *head = NULL;
    Insert_at_front(head, 10);
    Insert_at_front(head, 20);
    Insert_at_front(head, 30);
    Insert_at_front(head, 20);
    Insert_at_front(head, 10);

    display(head);

    if (isPalindrome(head) == 1)
    {
        cout << "true" << endl;
    }

    else
    {
        cout << "false" << endl;
    }

    return 0;
}