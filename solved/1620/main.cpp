#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    unordered_map<string, string> pokemon;
    for (int i = 1; i < N + 1; i++)
    {
        string p, idx;
        cin >> p;
        idx = to_string(i);
        pokemon[idx] = p;
        pokemon[p] = idx;
    }
    for (int i = 0; i < M; i++)
    {
        string q;
        cin >> q;
        cout << pokemon[q] << '\n';
    }
    return 0;
}