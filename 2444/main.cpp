#include <iostream>

int main()
{
    int N, i, j;
    std::cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = 0; j < N - i; j++)
            std::cout << " ";
        for (j = 0; j < 2 * i - 1; j++)
            std::cout << "*";
        std::cout << "\n";
    }
    for (i = N - 1; 0 < i; i--)
    {
        for (j = 0; j < N - i; j++)
            std::cout << " ";
        for (j = 0; j < 2 * i - 1; j++)
            std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}