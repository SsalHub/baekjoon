#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int x, y, n;
    std::cin >> x >> y;
    if (0 < y)
    {
        if (0 < x)
            std::cout << "1" << "\n";
        else
            std::cout << "2" << "\n";
    }
    else
    {
        if (0 < x)
            std::cout << "4" << "\n";
        else
            std::cout << "3" << "\n";
    }
    return 0;
}