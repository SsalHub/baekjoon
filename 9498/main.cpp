#include <iostream>

int main()
{
    int score;
    std::cin >> score;
    if (score < 60)
    {
        std::cout << "F" << "\n";
    }
    else if (score < 70)
    {
        std::cout << "D" << "\n";
    }
    else if (score < 80)
    {
        std::cout << "C" << "\n";
    }
    else if (score < 90)
    {
        std::cout << "B" << "\n";
    }
    else
    {
        std::cout << "A" << "\n";
    }
    return 0;
}