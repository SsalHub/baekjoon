#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char input[5];
    int n;
    while (1)
    {
        std::cin.getline(input, 5);
        if (!input[0])
            break;
        n = ((int)input[0] - 48) + ((int)(input[2]) - 48);
        std::cout << n << "\n";
    }
    return 0;
}