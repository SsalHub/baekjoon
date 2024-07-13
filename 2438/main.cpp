#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x = i;
        while (x--)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}