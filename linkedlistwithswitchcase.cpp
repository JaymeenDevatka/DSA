#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() : head(NULL) {}

    void InsertAtFront(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void InsertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void DeleteAtFirst()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    void DeleteAtLast()
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
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void DeleteNthFromEnd(int n)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *first = head;
        Node *second = head;
        for (int i = 0; i < n; i++)
        {
            if (first == NULL)
            {
                cout << "Position is greater than the length of the list." << endl;
                return;
            }
            first = first->next;
        }
        if (first == NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        while (first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        Node *temp = second->next;
        second->next = second->next->next;
        delete temp;
    }

    void DeleteAllNodes()
    {
        Node *temp = head;
        Node *next;
        while (temp != NULL)
        {
            next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
    }

    void Display() const
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLinkedList list;
    int choice;

    do
    {
        cout << "Enter 1 for Insert at first" << endl;
        cout << "Enter 2 for Insert at Last" << endl;
        cout << "Enter 3 for Delete at first" << endl;
        cout << "Enter 4 for Delete at last" << endl;
        cout << "Enter 5 for Delete Nth node from end" << endl;
        cout << "Enter 6 for Delete full node" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int n1, n2, n3;
            cout << "Enter three numbers = ";
            cin >> n1 >> n2 >> n3;
            list.InsertAtFront(n1);
            list.InsertAtFront(n2);
            list.InsertAtFront(n3);
            list.Display();
            break;
        }
        case 2:
        {
            int n4;
            cout << "Enter a number = ";
            cin >> n4;
            list.InsertAtTail(n4);
            list.Display();
            break;
        }
        case 3:
        {
            list.DeleteAtFirst();
            list.Display();
            break;
        }
        case 4:
        {
            list.DeleteAtLast();
            list.Display();
            break;
        }
        case 5:
        {
            int n;
            cout << "Enter position from end = ";
            cin >> n;
            list.DeleteNthFromEnd(n);
            list.Display();
            break;
        }
        case 6:
        {
            list.DeleteAllNodes();
            list.Display();
            break;
        }
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

        cout << "Prepared by 23CE023 Jaymeen Devatka." << endl;
    } while (true);

    return 0;
}