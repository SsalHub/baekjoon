#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    cin.tie(NULL);
    cin >> N >> M;
    int mem[101], cost[101];
    for (int i = 0; i < N; i++) cin >> mem[i];
    for (int i = 0; i < N; i++) cin >> cost[i];
    // dp
    const int MAX_COST = 100 * N;
    int dp[10001] = {};
    for (int i = 0; i < N; i++)
    {
        for (int j = MAX_COST; j >= cost[i]; j--)
        {
            if (cost[i] <= j)
            {
                dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
            }
        }
    }
    int min_cost = 0;
    for (min_cost = 0; min_cost < MAX_COST; min_cost++)
    {
        if (M <= dp[min_cost]) break;
    }
    cout << min_cost;
    return 0;
}