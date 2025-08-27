#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    int N, M;
    cin >> N;
    unordered_map<int, int> cards;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (cards.find(n) != cards.end())
            cards[n]++;
        else
            cards[n] = 1;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        if (cards.find(n) != cards.end())
            cout << cards[n] << ' ';
        else
            cout << 0 << ' ';
    }
    return 0;
}