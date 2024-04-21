#include <iostream>
#include <cstring>

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
    int i, j, minimum = len;

    if (x == 1)
        return 1;
    memset(table, x, len * len);

    for (i = 1; i < len; i++)
    {
        table[i][0] = table[i - 1][0]; // j = 0
        for (j = 1; j < len; j++)
        {
            if (table[i][j] == 1)
            {
                minimum = j - 1 < minimum ? j - 1 : minimum;
                continue;
            }

            if (table[i][j - 1] % 3 != 0)
                table[i][j] = table[i - 1][j] / 3;
            else if (table[i - 1][j] % 2 != 0)
                table[i][j] = table[i][j - 1] / 2;
            else if (table[i][j - 1] < table[i][j])
                table[i][j] = table[i - 1][j - 1] - 1;
        }
    }
    return minimum;
}