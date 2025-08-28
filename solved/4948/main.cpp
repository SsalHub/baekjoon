#include <iostream>
#define MAX 123456
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool prime[MAX * 2 + 1];
    fill(prime, prime + MAX * 2 + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAX * 2; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAX * 2; j += i)
            {
                prime[j] = false;
            }
        }
    }
    while (1)
    {
        int N;
        cin >> N;
        if (N == 0) break;
        int cnt = 0;
        for (int i = N + 1; i <= N * 2; i++)
        {
            if (prime[i]) 
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}