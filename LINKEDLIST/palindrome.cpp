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

node *reverse_linked_list(node *head)
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
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    // Find the middle of the linked list
    node *middle = middlenode(head);

    // Reverse the second half of the linked list
    node *second_half = reverse_linked_list(middle->next);

    // Compare the first and second halves
    node *first_half = head;
    node *second_copy = second_half; // Store this to restore the original list

    while (second_half != nullptr)
    {
        if (first_half->data != second_half->data)
        {
            return false; // Not a palindrome
        }

        first_half = first_half->next;
        second_half = second_half->next;
    }

    // Restore the original list structure by reversing the second half back
    middle->next = reverse_linked_list(second_copy);

    return true;
}

int main()
{
    node *head = nullptr;

    Insert_at_front(head, 1);
    Insert_at_front(head, 2);
    Insert_at_front(head, 2);
    Insert_at_front(head, 1);

    display(head);

    if (!isPalindrome(head))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // Display the list again to confirm it hasn't been altered
    display(head);

    return 0;
}
