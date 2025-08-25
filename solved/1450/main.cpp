#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
int items[30];

void makeCombi(vector<int> &v, int idx, int w, int end)
{
    if (C < w) return;
    if (idx == end)
    {
        v.push_back(w);
        return;
    }
    makeCombi(v, idx + 1, w + items[idx], end);
    makeCombi(v, idx + 1, w, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> lCombi, rCombi;
    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> items[i];
    makeCombi(lCombi, 0, 0, N/2);
    makeCombi(rCombi, N/2, 0, N);
    sort(rCombi.begin(), rCombi.end());

    int answer = 0;
    for (int w: lCombi)
    {
        answer += upper_bound(rCombi.begin(), rCombi.end(), C - w) - rCombi.begin();
    }
    cout << answer;
    return 0;
}