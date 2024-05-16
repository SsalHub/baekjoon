#include <iostream>

void qsort(int arr[][2], int left, int right);
int partition(int arr[][2], int left, int right);

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

void qsort(int arr[][2], int left, int right)
{
    if (right <= left)
        return;
    int pivot = partition(arr, left, right);
    qsort(arr, left, pivot - 1);
    qsort(arr, pivot + 1, right);
}

int partition(int arr[][2], int left, int right)
{
    int pivot = left, l = left + 1, r = right;

    return 0;
}