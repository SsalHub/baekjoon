#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char S[1001];
    int i;
    std::cin >> S >> i;
    std::cout << S[i - 1] << "\n";
    return 0;
}