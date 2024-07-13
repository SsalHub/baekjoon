#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, X, A;
    std::cin >> N >> X;
    while (N--)
    {
        std::cin >> A;
        if (A < X)
            std::cout << A << " ";
    }
    return 0;
}