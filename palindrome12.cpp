#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

bool reverse_string(string &str)
{

    string name2 = str;

    reverse(str.begin(), str.end());

    return str == name2;
}
int main()
{
    string name;

    cin >> name;

    if (reverse_string(name))
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "not a palindrome" << endl;
    }
}