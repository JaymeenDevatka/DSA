#include <iostream>
using namespace std;

int LongestWordSearch(const string &str)
{
    int n = str.length();
    int res = 0, cur_len = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
            cur_len++;
        else
        {
            res = max(res, cur_len);
            cur_len = 0;
        }
    }
    return max(res, cur_len);
}

int main()
{
    string str;
    cin >> str;

    
}