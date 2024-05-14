#include <iostream>

void qsort(int arr[][2]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;

    std::cin >> n;
    int meeting[n][2];
    for (int i = 0; i < n; i++)
    {
        std::cin >> meeting[i][0] >> meeting[i][1];
    }

    return 0;
}