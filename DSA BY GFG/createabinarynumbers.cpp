#include <iostream>
#include <queue>
using namespace std;

// class node
// {
// public:
//     int data;
//     node *next;

//     node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };

// class queue
// {
// private:
//     node *top;

//     queue()
//     {
//         top = NULL;
//     }

//     // for(int i=0;)
// };

void BinaryGenerator(int n)
{
    queue<string> q;

    q.push("1");

    for (int i = 0; i < n; i++)
    {
        string cur = q.front();

        q.pop();

        cout << cur << " ";

        q.push(cur + "0");
        q.push(cur + "1");
    }

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    BinaryGenerator(n);

    return 0;
}