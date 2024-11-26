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
bool IsPalindrome(node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *second_half = reverse_linked_list(slow);

    node *first = head;
    node *temp_second = second_half;

    while (temp_second != nullptr)
    {
        if (first->data != temp_second->data)
        {
            return false;
        }

        first = first->next;
        temp_second = temp_second->next;
    }

    return true;
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
    insert_at_front(head, 2);
    insert_at_front(head, 1);

    display(head);

    if (IsPalindrome(head))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}