#include <iostream>

using namespace std;

bool isGroupWord(char s[]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, groupWord = 0;
    cin >> n;
    char s[101];
    while (n--)
    {
        cin >> s;
        if (isGroupWord(s))
            groupWord++;
    }
    cout << groupWord << "\n";
    return 0;
}

bool isGroupWord(char s[])
{
    bool alphabet[26] = {
        false,
    };
    int i = 0, j;
    while (s[i])
    {
        if (alphabet[s[i] - 'a'])
            return false;
        alphabet[s[i] - 'a'] = true;
        j = i + 1;
        while (s[i] == s[j])
            j++;
        i = j;
    }
    return true;
}