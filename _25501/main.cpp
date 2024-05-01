#include <iostream>
#include <cstring>
#include <string>

#define _STRLEN_ 1000

int isPalindrome(const char *s);
int recursion(const char *s, int l, int r, int recur_round);

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, is_pal, recur_round;

    std::cin >> n;
    char pal[n][_STRLEN_ + 1];
    for (int i = 0; i < n; i++)
    {
        std::cin.getline(pal[i], _STRLEN_);
        recur_round = isPalindrome(pal[i]);
        if (recur_round == 0)
        {
            is_pal = 1;
            recur_round = strlen(pal[i]) / 2 + 1;
        }
        else
        {
            is_pal = 0;
        }

        std::cout << is_pal << " " << recur_round << "\n";
    }

    return 0;
}

int isPalindrome(const char *s)
{
    return recursion(s, 0, strlen(s) - 1, 1);
}

/** if succeess, return 0. or return recur_round. */
int recursion(const char *s, int l, int r, int recur_round)
{
    if (r <= l)
        return 0;
    else if (s[l] != s[r])
        return recur_round;
    else
        return recursion(s, l + 1, r - 1, recur_round + 1);
}