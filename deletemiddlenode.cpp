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

void insert_at_front(node *&head, int val)
{
    node *newNode = new node(val);
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

// node *middle_node(node *&head)
// {
//     node *fast = head;
//     node *slow = head;

//     while (fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return slow;
// }
void delete_middle_node(node *&head)
{
    node *temp = head;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *fast = head;
    node *slow = head;
    node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;
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

    delete_middle_node(head);

    display(head);

    return 0;
}