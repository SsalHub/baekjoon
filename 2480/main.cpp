#include <iostream>
#include <cmath>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int input, best, dice[7] = {
                         0,
                     };
    for (int i = 0; i < 3; i++)
    {
        std::cin >> input;
        dice[input]++;
    }
    for (int i = 1; i <= 6; i++)
    {
        if (2 <= dice[i])
        {
            std::cout << std::pow(10, dice[i] + 1) + i * std::pow(10, dice[i]) << "\n";
            return 0;
        }
        if (dice[i] == 1)
            best = i;
    }
    std::cout << best * 100 << "\n";
    return 0;
}