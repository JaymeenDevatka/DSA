#include <iostream>
using namespace std;

int LongestWordSearch(const string &str)
{
    int n = str.length();
    int res = 0, currr_length = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
            currr_length++;
        else
            res = max(currr_length, res);
        currr_length = 0;
    }

    return max(currr_length, res);
}

int main()
{
    string str;
    cin >> str;

    int lws = LongestWordSearch(str);

    cout << "Longest Word length: " << lws << endl;

    return 0;
}