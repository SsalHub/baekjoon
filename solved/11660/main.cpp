#include <iostream>
#include <string.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, M, x1, y1, x2, y2, input;
    std::cin >> N >> M;
    int arr[N + 1][N + 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> input;
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + input;
        }
    }
    while (M--)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}