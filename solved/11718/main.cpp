#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char S[101];
    while (1)
    {
        std::cin.getline(S, 101);
        if (std::cin.eof())
            break;
        std::cout << S << "\n";
    }
    return 0;
}