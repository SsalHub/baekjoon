#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, i, j, tmp;
    std::cin >> N >> M;
    int arr[N + 1] = {
        0,
    };
    for (int idx = 1; idx <= N; idx++)
    {
        std::cin >> tmp;
        arr[idx] = arr[idx - 1] + tmp;
    }
    while (M--)
    {
        std::cin >> i >> j;
        std::cout << arr[j] - arr[i - 1] << "\n";
    }
    return 0;
}