#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int dp(int N, int W, int w[], int v[]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, T;
    cin >> N >> T;
    int w[N], v[N];
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << dp(N, T, w, v) << "\n";
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
            if (j < w[i - 1])
            {
                table[i][j] = table[i][j - 1];
            }
            else
            {
                include = table[i - 1][j - w[i - 1]] + v[i - 1];
                exclude = table[i][j - 1];
                table[i][j] = max(include, exclude);
            }
        }
    }
    return table[N][W];
}