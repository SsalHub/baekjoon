#include <iostream>
#include <cstring>

#define _WEIGHT_    0
#define _VALUE_     1

int knapsack(int items[][2], int n, int k);

int main()
{
    int i, n, k, items[100][2];

    std::cin >> n >> k;
    for (i=0; i<n; i++)
    {
        std::cin >> items[i][_WEIGHT_] >> items[i][_VALUE_];
    }
    std::cout << knapsack(items, n, k);

    return 0;
}

int knapsack(int items[][2], int n, int k)
{
    int i, j, include, exclude, table[n+1][k+1];

    memset(table, 0, sizeof(table));
    for (i=1; i<n+1; i++)
    {
        for (j=1; j<k+1; j++)
        {
           /* OverWeight : Record highest value */
            if (j < items[i-1][_WEIGHT_])
            {
                table[i][j] = table[i-1][j];
                continue;
            }
            /* UnderWeight : Record max(highest) value between 'put in' case and 'not put in' case */
            exclude = table[i-1][j];
            include = table[i-1][j-items[i-1][_WEIGHT_]] + items[i-1][_VALUE_];
            table[i][j] = std::max(exclude, include);
        }
    }

    return table[n][k];
}