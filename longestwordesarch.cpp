#include <iostream>
using namespace std;

int LongestWordSearch(const string &str)
{
    int n = str.length();
    int res = 0, cur_length = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
        {
            cur_length++;
        }
        else
        {
            res = max(cur_length, res);
            cur_length = 0;
        }
    }

    return max(cur_length, res);
}

int main()
{
    string str;
    cin >> str;

    int longest_word_length = LongestWordSearch(str);
    cout << "Length of the longest word: " << longest_word_length << endl;
}