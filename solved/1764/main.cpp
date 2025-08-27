#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    unordered_set<string> never_heard, never_seen;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        never_heard.insert(name);
    }
    for (int i = 0; i < M; i++)
    {
        string name;
        cin >> name;
        never_seen.insert(name);
    }
    vector<string> answer;
    for (auto p: never_heard)
    {
        if (never_seen.find(p) != never_seen.end())
            answer.push_back(p);
    }
    sort(answer.begin(), answer.end());
    cout << (int)answer.size() << '\n';
    for (string p: answer)
    {
        cout << p << '\n';
    }
    return 0;
}