#include <iostream>
#include <cmath>

int main()
{
    long long int result;
    int N;
    std::cin >> N;
    result = std::pow(2 + std::pow(2, N) - 1, 2);
    std::cout << result << "\n";
    return 0;
}

// (2^15+1)^2 == 2^30 + 2^16 + 1
