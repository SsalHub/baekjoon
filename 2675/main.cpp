#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T, R, i;
    char S[21];
    std::cin >> T;
    while (T--)
    {
        std::cin >> R >> S;
        i = 0;
        while (S[i])
        {
            for (int x = 0; x < R; x++)
            {
                std::cout << S[i];
            }
            i++;
        }
        std::cout << "\n";
    }
    return 0;
}