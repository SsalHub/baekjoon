#include <iostream>

int main()
{
    long long int n;
    std::cin >> n;
    std::cout << n * (n - 1) * (n - 2) / 6 << "\n"
              << 3 << "\n";
    return 0;
}