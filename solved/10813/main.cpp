#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, M, i, j, temp;
    std::cin >> N >> M;
    int basket[N + 1] = {
        0,
    };
    while (M--)
    {
        std::cin >> i >> j;
        temp = !basket[i] ? i : basket[i];
        basket[i] = !basket[j] ? j : basket[j];
        basket[j] = temp;
    }
    for (int x = 1; x <= N; x++)
    {
        std::cout << (!basket[x] ? x : basket[x]) << " ";
    }
    std::cout << "\n";
    return 0;
}