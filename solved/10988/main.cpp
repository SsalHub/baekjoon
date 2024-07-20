#include <iostream>
#include <cstring>

using namespace std;

int isPalindrome(char s[]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char pal[101];
    cin >> pal;
    cout << isPalindrome(pal) << "\n";
    return 0;
}

int isPalindrome(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return 0;
    }
    return 1;
}