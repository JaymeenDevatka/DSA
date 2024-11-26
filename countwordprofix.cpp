#include <iostream>
#include <vector>
using namespace std;

int CountPrefixMatches(vector<string> &words, string &str)
{
    int count = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].substr(0, str.size()) == str)
            count++;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    string str;
    cin >> str;

    int result = CountPrefixMatches(words, str);

    cout << result << endl;

    return 0;
}