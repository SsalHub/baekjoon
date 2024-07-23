#include <iostream>
#define _MAX_ 1001

int main()
{
    std::cin.tie(0);
    bool prime[_MAX_] = {
        false,
    };
    prime[1] = true;
    for (int i = 2; i < _MAX_; i++)
    {
        if (prime[i])
            continue;
        for (int j = i * i; j <= _MAX_; j += i)
            prime[j] = true;
    }
    int T, N, prime_nums = 0;
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        if (!prime[N])
            prime_nums++;
    }
    std::cout << prime_nums << "\n";
    return 0;
}