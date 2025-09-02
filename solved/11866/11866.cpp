#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    vector<int> v;
    for (int i = 1; i <= N; i++) q.push(i);
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0) cout << ", ";
        cout << v[i];
    }
    cout << ">";
    return 0;
}