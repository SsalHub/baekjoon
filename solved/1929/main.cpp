#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int M, N;
    std::cin >> M >> N;
    bool prime[N + 1] = {
        false,
    };
    prime[1] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
            continue;
        for (int j = i * i; j <= N; j += i)
        {
            prime[j] = true;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (prime[i])
            continue;
        std::cout << i << "\n";
    }
    return 0;
}