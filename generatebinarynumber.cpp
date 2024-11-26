#include <iostream>
#include <queue>
using namespace std;

void GenerateBinaryNumber(int n)
{
    queue<string> qu;
    qu.push("1");

    for (int i = 0; i < n; i++)
    {
        string f = qu.front();
        qu.pop();
        cout << f << " ";

        string x = f;
        string y = f;

        qu.push(x.append("0"));
        qu.push(y.append("1"));
    }
}

int main()
{
    int n;
    cin >> n;

    GenerateBinaryNumber(n);

    return 0;
}