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
    int i, j, table[n+1][k+1];

    memset(table, 0, sizeof(table));

    for (i=1; i<n+1; i++)
    {
        for (j=1; j<k+1; j++)
        {
            /*
                무게를 비교하고 적절하면 items[][_VALUE_] 기록하기
            */
        }
    }

    return 0;
}