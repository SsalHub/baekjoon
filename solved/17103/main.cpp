#include <iostream>
#include <vector>
#define _MAX_ 1000001
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> prime(_MAX_, true);
    vector<int> prime_list;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < _MAX_; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < _MAX_; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i < _MAX_; i++)
    {
        if (prime[i])
            prime_list.push_back(i);
    }
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        int cnt = 0;
        for (int p: prime_list)
        {
            if (N / 2 < p) break;
            if (prime[N - p]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}