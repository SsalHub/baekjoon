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
    int i, j, cell;

    memset(table, x, len);

    for (i = 1; i < len; i++)
    {
        for (j = 1; j < len; j++)
        {
            if (table[i-1][j] % 3 != 0 && table[i-1][j] / 3 < table[i][j])
                table[i][j] = table[i-1][j] / 3;
            if (table[i][j-1] % 2 != 0 && table[i][j-1] / 2 < table[i][j])
                table[i][j] = table[i][j-1] / 2;
            
            if (table[i-1][j-1] < table[i][j])
                table[i][j] = table[i-1][j-1] - 1;
        }
    }
}