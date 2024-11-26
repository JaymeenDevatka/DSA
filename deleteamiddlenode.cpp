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

void delete_middle_node(node *&head)
{
    node *slow = head;
    node *fast = head;
    node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {

        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // node *temp = NULL;

    prev->next = slow->next;

    delete slow;
}

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

void print_list(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
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

    cout << "Before Delete: " << endl;
    print_list(head);

    delete_middle_node(head);

    cout << "After Delete: " << endl;
    print_list(head);

    return 0;
}