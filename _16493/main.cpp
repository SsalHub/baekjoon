#include <iostream>
#include <string.h>

int dp(int N, int W, int w[], int v[]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    int days[M], pages[M];
    for (int i = 0; i < M; i++)
    {
        std::cin >> days[i] >> pages[i];
    }
    std::cout << dp(M, N, days, pages);
    return 0;
}

int dp(int N, int W, int w[], int v[])
{
    int table[N + 1][W + 1], include, exclude;
    memset(table, 0, sizeof(table));
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (w[i - 1] <= j)
            {
                include = table[i - 1][j - w[i - 1]] + v[i - 1];
                exclude = table[i - 1][j];
                table[i][j] = std::max(include, exclude);
            }
            else
            {
                table[i][j] = std::max(table[i][j - 1], table[i - 1][j]);
            }
        }
    }
    return table[N][W];
}