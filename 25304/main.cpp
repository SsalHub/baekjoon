#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int X, N, a, b;
    std::cin >> X >> N;
    while (N--)
    {
        std::cin >> a >> b;
        X -= a * b;
    }
    if (X)
        std::cout << "No" << "\n";
    else
        std::cout << "Yes" << "\n";
    return 0;
}