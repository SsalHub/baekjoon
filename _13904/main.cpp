#include <iostream>
#include <cstring>

#define MAX_N 1000

int partition(int arr[], int left, int right, bool incr);
void qsort(int arr[], int left, int right, bool incr);
void swap(int* e1, int* e2);
int compare(int n1, int n2, bool b);
int getMaxScore();

int main()
{
    int deadline[MAX_N], score[MAX_N];
    int i, n, maxScore;

    std::cin >> n;

    for (i = 0; i < n; i++)
    {
        std::cin >> deadline[i];
        std::cin >> score[i];
    }

    /* Increasing Sort 'deadline' Array */
    qsort(deadline, 0, n-1, true);

    /* Decreasing Sort 'deadline' Array */
    qsort(score, 0, n-1, false);

    maxScore = getMaxScore();

    std::cout << maxScore << std::endl; 

    return 0;
}

int partition(int arr[], int left, int right, bool incr)
{
    int pivot = left, tmp_left = left+1, low = tmp_left, high = right;

    while (low < high)
    {
        while (low <= right && compare(arr[low], arr[pivot], incr) <= 0)
        {
            low++;
        }
        while (tmp_left <= high && 0 <= compare(arr[pivot], arr[high], incr))
        {
            high--;
        }
        if (low < high)
            swap(arr+low, arr+high);
    }
    if (compare(arr[pivot], arr[high], incr) <= 0)
        swap(arr+pivot, arr+high);
    return high;
}

void qsort(int arr[], int left, int right, bool incr)
{
    if (!(left < right))
        return;
    int pivot = partition(arr, left, right, incr);
    qsort(arr, left, pivot-1, incr);
    qsort(arr, pivot+1, right, incr);
}

void swap(int* e1, int* e2)
{
    if (e1 == e2) return;
    *e1 ^= *e2;
    *e2 ^= *e1;
    *e1 ^= *e2;
}

int compare(int n1, int n2, bool b)
{
    
    if (n1 == n2) return 0;

    if (b)
    {
        if (n1 < n2) return 1;
        else return -1;
    }
    // else
    if (n1 < n2) return 1;
    else return -1;
}

int getMaxScore()
{
    sadsa
    return 0;
}