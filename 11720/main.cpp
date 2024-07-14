#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, sum = 0, i = 0;
    std::cin >> N;
    char str[N + 1];
    std::cin >> str;
    while (str[i])
        sum += str[i++] - 48;
    std::cout << sum << "\n";
    return 0;
}