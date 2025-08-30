#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first > b.first;
    return a.second < b.second; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int mem[101], cost[101];
    pair<int, int> apps[101];   // first = memory, second = cost
    for (int i = 0; i < N; i++)
        cin >> apps[i].first;
    for (int i = 0; i < N; i++)
        cin >> apps[i].second;
    sort(apps, apps+N, compare);
    int min_cost = 10001;
    for (int i = 0; i < N; i++)
    {
        int m_sum = apps[i].first, c_sum = apps[i].second;
        int j = i + 1;
        while (j < N && m_sum < M)
        {
            m_sum += apps[j].first;
            c_sum += apps[j].second;
            j++;
        }
        if (m_sum < M) continue;
        min_cost = min(min_cost, c_sum);
    }
    cout << min_cost;
    return 0;
}
