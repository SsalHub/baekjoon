#include <iostream>

int main()
{
    int a, b, c, n;
    std::cin >> a >> b >> c >> n;
    if (a == 0)
        n = 1;
    std::cout << ((a * n + b <= c * n) && (a * 10000 + b <= c * 10000)) << "\n";
    return 0;
}
