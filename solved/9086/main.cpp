#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    char str[1001];
    std::cin >> T;
    while (T--)
    {
        std::cin >> str;
        std::cout << str[0] << str[strlen(str) - 1] << "\n";
    }
    return 0;
}