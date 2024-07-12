#include <iostream>

int main()
{
    int y;
    std::cin >> y;
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        std::cout << "1" << "\n";
    else
        std::cout << "0" << "\n";
    return 0;
}