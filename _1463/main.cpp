#include <iostream>
#include <cstring>
#include <cmath>

int dp(int x);

int main()
{
    std::ios_base::sync_with_stdio(false);
    int x, result;

    std::cin >> x;
    result = dp(x);
    std::cout << result;

    return 0;
}

int dp(int x)
{
    const int len = x + 1;
    int table[len][len];
    int i, j, row, col, attempt;

    memset(table, x, len * len);

    for (i = 1; i < len; i++)
    {
        for (j = 1; j < len; j++)
        {
            if (table[i - 1][j] % 3 == 0)
                row = table[i - 1][j] / 3;
            else
                row = table[i - 1][j] - 1;

            if (table[i][j - 1] % 2 == 0)
                col = table[i][j - 1] / 2;
            else
                col = table[i][j - 1] - 1;

            table[i][j] = std::min(row, col);

            if (table[i][j] == 1)
            {
                attempt = j - 1;
                break;
            }
        }
    }
    return attempt;
}