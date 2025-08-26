#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int days[21], pages[21];
    for (int i = 0; i < M; i++)
    {
        cin >> days[i] >> pages[i];
    }
    int table[21][201] = {0};
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j < days[i - 1])
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = max(table[i - 1][j - days[i - 1]] + pages[i - 1], table[i - 1][j]);
            }
        }
    }
    cout << table[M][N];
    return 0;
}