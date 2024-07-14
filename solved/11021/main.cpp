#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T, A, B;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
    {
        std::cin >> A >> B;
        std::cout << "Case #" << i << ": " << A + B << "\n";
    }
    return 0;
}