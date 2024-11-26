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

bool is_palindrome(node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    node *fast = head;
    node *slow = head;

    while (fast != nullptr || fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *prev = nullptr;
    node *cur = slow;
    node *next = nullptr;

    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    node *second = prev;

    node *first = head;

    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            return false;
        }

        first = first->next;
        second = second->next;
    }

    return true;
}