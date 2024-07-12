#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int H, M;
    std::cin >> H >> M;
    std::cout << (M < 45 ? (H + 23) % 24 : H) << " " << ((M + 15) % 60) << "\n";
    return 0;
}