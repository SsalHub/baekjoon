#include <iostream>
#include <string.h>

#define HP 99

int dp(int n, int L[], int J[]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    int L[N], J[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> L[i];
    }
    for (int i = 0; i < N; i++)
    {
        std::cin >> J[i];
    }
    std::cout << dp(N, L, J);
    return 0;
}

int dp(int n, int L[], int J[])
{
    int table[n + 1][HP + 1], include, exclude;
    memset(table, 0, sizeof(table));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < HP + 1; j++)
        {
            if (L[i - 1] <= j)
            {
                include = table[i - 1][j - L[i - 1]] + J[i - 1];
                exclude = table[i - 1][j];
                table[i][j] = std::max(include, exclude);
            }
            else
            {
                if (HP < L[i - 1])
                    table[i][j] = table[i][j - 1];
                else
                    table[i][j] = table[i][j - 1];
            }
        }
    }

    std::cout << "\n"
              << "[ table print ]" << "\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < HP + 1; j++)
        {
            std::cout << table[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return table[n][HP];
}