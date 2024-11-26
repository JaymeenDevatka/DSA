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
        next = nullptr;
    }
};

bool delete_middle_node(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    node *slow = head;
    node *fast = head;
    node *prev = nullptr;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (prev != NULL)
    {
        prev->next = slow->next;
        delete slow;
        return true;
    }

    return false;
}

void print_list(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    print_list(head);

    if (delete_middle_node(head))
    {
        cout << "Middle node deleted.\n";
    }
    else
    {
        cout << "Failed to delete middle node.\n";
    }

    cout << "Modified List: ";
    print_list(head);

    return 0;
}
