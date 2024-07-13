#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int A, B;
    while (1)
    {
        std::cin >> A >> B;
        if (!A && !B)
            break;
        std::cout << A + B << "\n";
    }
    return 0;
}