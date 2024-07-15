#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char S[10];
    int n, max = -1;
    for (int i = 0; i < 2; i++)
    {
        std::cin >> S;
        n = (S[2] - 48) * 100 + (S[1] - 48) * 10 + (S[0] - 48);
        max = max < n ? n : max;
    }
    std::cout << max << "\n";
    return 0;
}