#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    N /= 4;
    while (N--)
    {
        std::cout << "long ";
    }
    std::cout << "int" << "\n";
    return 0;
}