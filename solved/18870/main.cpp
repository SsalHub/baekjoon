#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    vector<int> X_ = X;
    sort(X_.begin(), X_.end());
    X_.erase(unique(X_.begin(), X_.end()), X_.end());
    for (int x: X)
    {
        int idx = lower_bound(X_.begin(), X_.end(), x) - X_.begin();
        cout << idx << " ";
    }
    return 0;
}