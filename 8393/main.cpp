#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, s = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        s += i;
    }
    std::cout << s << "\n";
    return 0;
}