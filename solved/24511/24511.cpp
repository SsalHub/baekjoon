#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> type(N);
    deque<int> qs;
    int x;
    for (int i = 0; i < N; i++)
        cin >> type[i];
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (type[i] == 0) qs.push_back(n);
    }
    int M;
    cin >> M;
    while (M--) {
        cin >> x;
        qs.push_front(x);
        int n = qs.back();
        qs.pop_back();
        cout << n << ' ';
    }
    return 0;
}