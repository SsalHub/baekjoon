#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, card[101];
vector<int> combi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> card[i];
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                combi.push_back(card[i] + card[j] + card[k]);
            }
        }
    }
    sort(combi.begin(), combi.end());
    int idx = lower_bound(combi.begin(), combi.end(), M) - combi.begin();
    if (combi[idx] != M) idx--;
    cout << combi[idx];
    return 0;
}