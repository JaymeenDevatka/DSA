#include<iostream>
#include<queue>

using namespace std;

int BinaryNumberGenerator(int n)
{
    queue<string> q;
    q.push('1');

    for(int i=0;i<n;i++)
    {
        string front = q.front();
        q.pop();
        cout << front << endl;

        string s1 = 
    }
}