#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, blank, star;
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        blank = N - i;
        while (blank--)
            std::cout << " ";
        star = i;
        while (star--)
            std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}