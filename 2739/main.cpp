#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    for (int i = 1; i <= 9; i++)
    {
        std::cout << N << " * " << i << " = " << N * i << "\n";
    }
    return 0;
}