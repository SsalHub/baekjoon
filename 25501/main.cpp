#include <iostream>
#include <cstring>

#define _STRLEN_ 1001

int isPalindrome(const char *s);
int recursion(const char *s, int l, int r, int recur_round);

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, result;

    std::cin >> n;
    std::cin.ignore();
    char pal[n][_STRLEN_];
    for (int i = 0; i < n; i++)
    {
        std::cin.getline(pal[i], _STRLEN_);
    }

    for (int i = 0; i < n; i++)
    {
        result = isPalindrome(pal[i]);

        if (0 <= result)
            std::cout << "0 " << result << "\n";
        else
            std::cout << "1 " << -result << "\n";
    }

    return 0;
}

int isPalindrome(const char *s)
{
    return recursion(s, 0, strlen(s) - 1, 1);
}

int recursion(const char *s, int l, int r, int recur_round)
{
    if (r <= l)
        return -recur_round;
    else if (s[l] != s[r])
        return recur_round;
    else
        return recursion(s, l + 1, r - 1, recur_round + 1);
}