#include <iostream>
using namespace std;

string LongestWord(string str)
{
    int n = str.length();
    int maxLength = 0, curLength = 0;
    string result = "";
    string currentWord = "";

    for (int i = 0; i <= n; i++)
    {
        if (i < n && str[i] != ' ') // Accumulating characters of the current word
        {
            currentWord += str[i];
            curLength++;
        }
        else // End of a word (or end of string)
        {
            if (curLength > maxLength)
            {
                maxLength = curLength;
                result = currentWord;
            }
            // Reset for the next word
            curLength = 0;
            currentWord = "";
        }
    }

    return result;
}

int main()
{
    string str = "There is a banana Tree";

    cout << "Longest word: " << LongestWord(str) << endl;

    return 0;
}