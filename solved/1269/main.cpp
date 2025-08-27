#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    set<int> A, B;
    vector<int> diff;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        A.insert(n);
    }
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        B.insert(n);
    }
    set_difference(
        A.begin(), A.end(),
        B.begin(), B.end(),
        back_inserter(diff)
    );
    set_difference(
        B.begin(), B.end(),
        A.begin(), A.end(),
        back_inserter(diff)
    );
    
    cout << (int)diff.size();
    return 0;
}