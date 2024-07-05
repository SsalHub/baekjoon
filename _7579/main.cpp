#include <iostream>
#include <string.h>

int getMaxCost(int n, int m, int mems[], int costs[]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, m, mems_total = 0, costs_total = 0;

    std::cin >> n >> m;
    int mems[n], costs[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> mems[i];
        mems_total += mems[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> costs[i];
        costs_total += costs[i];
    }

    std::cout << costs_total - getMaxCost(n, mems_total - m, mems, costs);
}

int getMaxCost(int n, int m, int mems[], int costs[])
{
    int table[n + 1][m + 1];
    int include, exclude;

    memset(table, 0, sizeof(table));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (mems[i - 1] <= j)
            {
                include = table[i - 1][j - mems[i - 1]] + costs[i - 1];
                exclude = table[i - 1][j];
                table[i][j] = std::max(include, exclude);
            }
            else
            {
                table[i][j] = table[i][j - 1];
            }
        }
    }

    return table[n][m];
}