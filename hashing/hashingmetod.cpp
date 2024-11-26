#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Function to check if a number is primen
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Function to find the next prime number greater than the specified size
int nextPrime(int size)
{
    while (!isPrime(size))
        size++;
    return size;
}

class HybridHashTable
{
private:
    vector<list<pair<int, int>>> chainTable; // For separate chaining
    vector<int> linearTable;                 // For linear probing (ID)
    vector<int> linearScoreTable;            // For linear probing (Score)
    int capacity;

public:
    HybridHashTable(int initialSize)
    {
        capacity = nextPrime(initialSize);
        chainTable.resize(capacity);
        linearTable.resize(capacity, -1); // -1 indicates empty slot
        linearScoreTable.resize(capacity, -1);
    }

    // Hash function using modulo
    int hashFunction(int key)
    {
        return key % capacity;
    }

    // Insert a record using separate chaining
    void insertChaining(int studentID, int score)
    {
        int index = hashFunction(studentID);
        chainTable[index].push_back({studentID, score});
    }

    // Insert a record using linear probing
    void insertProbing(int studentID, int score)
    {
        int index = hashFunction(studentID);
        int startIndex = index;
        while (linearTable[index] != -1)
        {
            index = (index + 1) % capacity;
            if (index == startIndex)
            {
                cout << "Hash table is full" << endl;
                return;
            }
        }
        linearTable[index] = studentID;
        linearScoreTable[index] = score;
    }

    // Delete a record using separate chaining
    void deleteChaining(int studentID)
    {
        int index = hashFunction(studentID);
        for (auto it = chainTable[index].begin(); it != chainTable[index].end(); ++it)
        {
            if (it->first == studentID)
            {
                chainTable[index].erase(it);
                cout << "Student ID " << studentID << " deleted from chaining method." << endl;
                return;
            }
        }
        cout << "Student ID " << studentID << " not found in chaining method." << endl;
    }

    // Delete a record using linear probing
    void deleteProbing(int studentID)
    {
        int index = hashFunction(studentID);
        int startIndex = index;
        while (linearTable[index] != studentID)
        {
            index = (index + 1) % capacity;
            if (index == startIndex || linearTable[index] == -1)
            {
                cout << "Student ID " << studentID << " not found in probing method." << endl;
                return;
            }
        }
        linearTable[index] = -1;
        linearScoreTable[index] = -1;
        cout << "Student ID " << studentID << " deleted from probing method." << endl;
    }

    // Display the hash table for separate chaining
    void displayChaining()
    {
        cout << "Separate Chaining Hash Table:" << endl;
        for (int i = 0; i < capacity; i++)
        {
            cout << "Index " << i << ": ";
            for (auto &record : chainTable[i])
            {
                cout << "(" << record.first << ", " << record.second << ") --> ";
            }
            cout << "NULL" << endl;
        }
    }

    // Display the hash table for linear probing
    void displayProbing()
    {
        cout << "Linear Probing Hash Table:" << endl;
        for (int i = 0; i < capacity; i++)
        {
            if (linearTable[i] != -1)
                cout << "Index " << i << ": (" << linearTable[i] << ", " << linearScoreTable[i] << ")" << endl;
            else
                cout << "Index " << i << ": Empty" << endl;
        }
    }
};

// Main function demonstrating both methods
int main()
{
    int initialSize = 6;
    HybridHashTable hashTable(initialSize);

    // Insert records using separate chaining
    hashTable.insertChaining(231, 123);
    hashTable.insertChaining(326, 432);
    hashTable.insertChaining(212, 523);
    hashTable.insertChaining(321, 43);
    hashTable.insertChaining(433, 423);
    hashTable.insertChaining(262, 111);

    // Display the hash table with separate chaining
    hashTable.displayChaining();

    // Delete a record
    hashTable.deleteChaining(212);

    // Display the hash table after deletion
    hashTable.displayChaining();

    cout << endl;

    // Insert records using linear probing
    hashTable.insertProbing(231, 123);
    hashTable.insertProbing(326, 432);
    hashTable.insertProbing(212, 523);
    hashTable.insertProbing(321, 43);
    hashTable.insertProbing(433, 423);
    hashTable.insertProbing(262, 111);

    // Display the hash table with linear probing
    hashTable.displayProbing();

    // Delete a record
    hashTable.deleteProbing(212);

    // Display the hash table after deletion
    hashTable.displayProbing();

    cout << endl;

    cout << "Jaymeen Devatka 23CE023" << endl;
    return 0;
}