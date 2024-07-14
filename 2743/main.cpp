#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char str[101];
    std::cin >> str;
    std::cout << strlen(str) << "\n";
    return 0;
}