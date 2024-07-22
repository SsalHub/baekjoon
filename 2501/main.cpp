#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K, result = 0;
    cin >> N >> K;
    for (int i = 1; K && i <= N / 2; i++)
    {
        if (N % i)
            continue;
        K--;
        if (!K)
            result = i;
    }
    if (K == 1)
        result = N;
    cout << result << "\n";
    return 0;
}