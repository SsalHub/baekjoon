#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int fib[41] = {};
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= N; i++) fib[i] = fib[i - 1] + fib[i - 2];
    cout << fib[N] << ' ' << N-2;
    return 0;
}