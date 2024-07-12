#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T, A, B;
    std::cin >> T;
    while (T--)
    {
        std::cin >> A >> B;
        std::cout << A + B << "\n";
    }
    return 0;
}