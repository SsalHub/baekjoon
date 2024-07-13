#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int input, max_v = -1, max_i = -1, i = 1;
    for (; i <= 9; i++)
    {
        std::cin >> input;
        if (input <= max_v)
            continue;
        max_v = input;
        max_i = i;
    }
    std::cout << max_v << "\n"
              << max_i << "\n";
    return 0;
}