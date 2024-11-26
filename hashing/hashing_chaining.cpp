#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to find the next prime number greater than a given number
int nextPrime(int n)
{
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}

// HashTable using separate chaining
class HashTableChaining
{
    vector<list<pair<int, int>>> table;
    int size;

public:
    HashTableChaining(int initialSize)
    {
        size = nextPrime(initialSize);
        table.resize(size);
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insertItem(int key, int score)
    {
        int index = hashFunction(key);
        table[index].push_back({key, score});
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                cout << "Record with Student ID " << key << " deleted.\n";
                return;
            }
        }
        cout << "Student ID " << key << " not found.\n";
    }

    void displayHash()
    {
        cout << "Hash Table (Separate Chaining):\n";
        for (int i = 0; i < size; ++i)
        {
            cout << "Index " << i << ": ";
            for (auto &pair : table[i])
            {
                cout << "[ID: " << pair.first << ", Score: " << pair.second << "] -> ";
            }
            cout << "NULL\n";
        }
    }
};

// HashTable using linear probing
class HashTableLinearProbing
{
    vector<pair<int, int>> table;
    int size;
    int EMPTY = -1;

public:
    HashTableLinearProbing(int initialSize)
    {
        size = nextPrime(initialSize);
        table.resize(size, {EMPTY, EMPTY});
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insertItem(int key, int score)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        while (table[index].first != EMPTY)
        {
            index = (index + 1) % size;
            if (index == originalIndex)
            {
                cout << "Hash Table is full. Cannot insert more records.\n";
                return;
            }
        }
        table[index] = {key, score};
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        while (table[index].first != EMPTY)
        {
            if (table[index].first == key)
            {
                table[index] = {EMPTY, EMPTY};
                cout << "Record with Student ID " << key << " deleted.\n";
                return;
            }
            index = (index + 1) % size;
            if (index == originalIndex)
            {
                break;
            }
        }
        cout << "Student ID " << key << " not found.\n";
    }

    void displayHash()
    {
        cout << "Hash Table (Linear Probing):\n";
        for (int i = 0; i < size; ++i)
        {
            if (table[i].first != EMPTY)
            {
                cout << "Index " << i << ": [ID: " << table[i].first << ", Score: " << table[i].second << "]\n";
            }
            else
            {
                cout << "Index " << i << ": NULL\n";
            }
        }
    }
};

// Main function to test the program
int main()
{
    int initialSize, choice, studentID, score, methodChoice;

    cout << "Enter initial size of hash table: ";
    cin >> initialSize;

    HashTableChaining chainingTable(initialSize);
    HashTableLinearProbing probingTable(initialSize);

    cout << "Choose collision handling method:\n";
    cout << "1. Separate Chaining\n";
    cout << "2. Linear Probing\n";
    cin >> methodChoice;

    do
    {
        cout << "\n1. Insert Student Record\n2. Delete Student Record\n3. Display Hash Table\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Score: ";
            cin >> score;
            if (methodChoice == 1)
                chainingTable.insertItem(studentID, score);
            else
                probingTable.insertItem(studentID, score);
            break;

        case 2:
            cout << "Enter Student ID to delete: ";
            cin >> studentID;
            if (methodChoice == 1)
                chainingTable.deleteItem(studentID);
            else
                probingTable.deleteItem(studentID);
            break;

        case 3:
            if (methodChoice == 1)
                chainingTable.displayHash();
            else
                probingTable.displayHash();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    cout << "\nprepared by 23CE019 Dedaniya" << endl;
    return 0;
}