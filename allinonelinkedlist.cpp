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

void insert_at_last(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void delete_at_front(node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}

void delete_at_last(node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void delete_at_any_point(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == val)
    {
        delete_at_front(head);
        return;
    }
    node *temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Value not found." << endl;
        return;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void delete_all_node(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        node *next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
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
    do
    {
        char choice;
        node *head = NULL;
        cout << "1. Insert node at front." << endl;
        cout << "2. Insert node at last." << endl;
        cout << "3. Delete node at front." << endl;
        cout << "4. Delete node at last." << endl;
        cout << "5. Delete node with specific value." << endl;
        cout << "6. Delete all nodes." << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
            insert_at_front(head, 10);
            insert_at_front(head, 20);
            insert_at_front(head, 30);
            display(head);
            break;

        case '2':
            insert_at_last(head, 10);
            insert_at_last(head, 20);
            insert_at_last(head, 30);
            display(head);
            break;

        case '3':
            insert_at_front(head, 10);
            insert_at_front(head, 20);
            insert_at_front(head, 30);
            display(head);
            delete_at_front(head);
            display(head);
            break;

        case '4':
            insert_at_front(head, 10);
            insert_at_front(head, 20);
            insert_at_front(head, 30);
            display(head);
            delete_at_last(head);
            display(head);
            break;

        case '5':
            insert_at_front(head, 10);
            insert_at_front(head, 20);
            insert_at_front(head, 30);
            display(head);
            delete_at_any_point(head, 20);
            display(head);
            break;

        case '6':
            insert_at_front(head, 10);
            insert_at_front(head, 20);
            insert_at_front(head, 30);
            display(head);
            delete_all_node(head);
            display(head);
            break;

        case '7':
            cout << "Exit Program." << endl;
            delete_all_node(head);
            return 0;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (true);
}