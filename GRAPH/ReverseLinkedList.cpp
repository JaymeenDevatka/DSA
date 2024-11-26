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
        next = nullptr;
    }
};

void insert_at_front(node *&head, int x)
{

    // if (head == nullptr)
    // {
    //     head = new node(x);
    // }

    node *newNode = new node(x);
    newNode->next = head;
    head = newNode;
}

// void insert_at_last(node *&head, int x)
// {
//     node *newNode = new node(x);
//     node *temp = head;

//     if (head == nullptr)
//     {
//         head = newNode;
//         return;
//     }
//     while (temp->next != nullptr)
//     {
//         temp = temp->next;
//     }

//     temp->next = newNode;
//     // newNode = head;
// }

// void delete_from_front(node *&head)
// {
//     if (head == nullptr)
//     {
//         return;
//     }

//     node *temp = head;
//     head = head->next;
//     delete temp;
// }

// void delete_from_last(node *&head)
// {
//     if (head == nullptr)
//     {
//         return;
//     }

//     if (head->next == nullptr)
//     {
//         delete head;
//         head = nullptr;
//         return;
//     }

//     node *temp = head;

//     while (temp->next->next != nullptr)
//     {
//         temp = temp->next;
//     }

//     delete temp->next;
//     temp->next = nullptr;
// }

node *reverse_linked_list(node *&head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    node *cur = head;
    node *prev = nullptr;
    node *next = nullptr;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}
void display(node *&head)
{
    node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << " " << endl;
}
int main()
{
    node *head = nullptr;

    insert_at_front(head, 1);
    insert_at_front(head, 2);
    insert_at_front(head, 3);
    insert_at_front(head, 4);
    insert_at_front(head, 5);

    display(head);

    // insert_at_last(head, 10);
    // insert_at_last(head, 20);
    // insert_at_last(head, 30);

    // display(head);

    // delete_from_front(head);

    // display(head);

    // delete_from_last(head);

    // display(head);

    // delete_from_last(head);

    // display(head);

    // delete_from_last(head);

    // display(head);

    node *rever = reverse_linked_list(head);

    display(rever);
    return 0;
}