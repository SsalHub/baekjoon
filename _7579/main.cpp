#include <iostream>
#include <string.h>

#define MEM 0
#define COST 1

using namespace std;

int partition(int arr[][2], int left, int right);
void qsort(int arr[][2], int left, int right);
void swap(int &num1, int &num2);

int main()
{
    std::ios_base::sync_with_stdio();
    int apps[100][2], n, m, mem_sum = 0, cost_sum = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> apps[i][MEM];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> apps[i][COST];
    }

    qsort(apps, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (m <= mem_sum)
            break;
        mem_sum += apps[i][MEM];
        cost_sum += apps[i][COST];
    }
    cout << cost_sum;
    return 0;
}

int partition(int arr[][2], int left, int right)
{
    int pivot = left, l = left, r = right + 1;

    do
    {
        do
        {
            l++;
        } while (arr[l][COST] <= arr[pivot][COST]);

        do
        {
            r--;
        } while (arr[pivot][COST] <= arr[r][COST]);

        if (l < r)
        {
            swap(arr[l][MEM], arr[r][MEM]);
            swap(arr[l][COST], arr[r][COST]);
        }
    } while (l < r);

    if (arr[r][COST] < arr[pivot][COST])
    {
        swap(arr[pivot][MEM], arr[r][MEM]);
        swap(arr[pivot][COST], arr[r][COST]);
    }
    return r;
}

void qsort(int arr[][2], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        qsort(arr, left, pivot - 1);
        qsort(arr, pivot + 1, right);
    }
}

void swap(int &num1, int &num2)
{
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}