#include <iostream>
#define _MAX_ 10001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool prime[_MAX_] = {
        false,
    };
    prime[1] = true;
    for (int i = 2; i < _MAX_; i++)
    {
        if (prime[i])
            continue;
        for (int j = i + i; j < _MAX_; j += i)
            prime[j] = true;
    }
    int M, N, sum = 0, min = _MAX_;
    cin >> M >> N;
    for (int i = N; M <= i; i--)
    {
        if (prime[i])
            continue;
        sum += i;
        min = i;
    }
    if (!sum)
        cout << -1 << "\n";
    else
        cout << sum << "\n"
             << min << "\n";
    return 0;
}