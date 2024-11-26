#include <iostream>
#include <queue>
using namespace std;

void BinaryGenerator(int n)
{
    queue<string> q;

    q.push("1");

    for (int i = 0; i < n; i++)
    {
        string s1 = q.front();

        q.pop();

        cout << s1 << " ";

        string s2 = s1;

        s1.append("0");
        s2.append("1");

        q.push(s1);
        q.push(s2);
    }
}
int main()
{
    int n;
    cin >> n;

    BinaryGenerator(n);
}