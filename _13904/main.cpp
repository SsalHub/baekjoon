#include <iostream>
#include <cstring>

#define MAX_N 1000
#define ARRAY_WIDTH 2
#define DAY_IDX 0
#define WORTH_IDX 1

int partition(int arr[][ARRAY_WIDTH], int priority[], int left, int right);
void qsort(int arr[][ARRAY_WIDTH], int priority[], int left, int right);
void swap(int* e1, int* e2);
void setPriority(int priority[], int prio1, int prio2);
int getPriorityIndex(int arr[][ARRAY_WIDTH], int priority[], int idx1, int idx2);
int compare(int arr[][ARRAY_WIDTH], int priority[], int idxLeft, int idxRight);
int getFinalScore(int homework[][ARRAY_WIDTH], int n);
void printArray(int arr[][ARRAY_WIDTH], int start, int end);

int main()
{
    int i, n;
    int homework[MAX_N][ARRAY_WIDTH], priority[ARRAY_WIDTH], score[ARRAY_WIDTH];

    std::cin >> n;


    for (i = 0; i < n; i++)
    {
        std::cin >> homework[i][DAY_IDX];
        std::cin >> homework[i][WORTH_IDX];
    }

    /* First Sorting By DAY, increasing sort */
    setPriority(priority, DAY_IDX, WORTH_IDX);
    qsort(homework, priority, 0, n-1);
    printArray(homework, 0, n);
    score[DAY_IDX] = getFinalScore(homework, n);
    std::cout << "------ SORT PROCESS DONE ------" << std::endl;
    
    /* First Sorting By WORTH, decreasing sort */
    setPriority(priority, WORTH_IDX, DAY_IDX);
    qsort(homework, priority, 0, n-1);
    printArray(homework, 0, n);
    score[WORTH_IDX] = getFinalScore(homework, n);

    std::cout << (score[DAY_IDX] > score[WORTH_IDX] ? score[DAY_IDX] : score[WORTH_IDX]) << std::endl;

    return 0;
}
        // 파티션에 두개짜리 배열이 왓을때 => 0번은 피벗되고, 1번이 left겸 right 해서 low겸 high???????
int partition(int arr[][ARRAY_WIDTH], int priority[], int left, int right)
{
    int pivot = left, tmp_left = left+1, low = tmp_left, high = right;

    while (low < high)
    {
        while (low <= right && 0 <= compare(arr, priority, low,  pivot))
        {
            low++;
        }
        while (tmp_left <= high && 0 <= compare(arr, priority, pivot, high))
        {
            high--;
        }
        if (low < high)
            swap(arr[low], arr[high]);
    }
    if (compare(arr, priority, pivot, high) < 0)
        swap(arr[pivot], arr[high]);
    printArray(arr, left, right+1);
    return high;
}

void qsort(int arr[][ARRAY_WIDTH], int priority[], int left, int right)
{
    if (!(left < right))
        return;
    int pivot = partition(arr, priority, left, right);
    qsort(arr, priority, left, pivot-1);
    qsort(arr, priority, pivot+1, right);
}

void swap(int* e1, int* e2)
{
    if (e1 == e2) return;
    int tmp[ARRAY_WIDTH];

    memcpy(tmp, e1, ARRAY_WIDTH*sizeof(int));
    memcpy(e1, e2, ARRAY_WIDTH*sizeof(int));
    memcpy(e2, tmp, ARRAY_WIDTH*sizeof(int));
}

/* Initialize array quickly. */
void setPriority(int priority[], int prio1, int prio2)
{
    int i = 0;

    priority[i++] = prio1;
    priority[i++] = prio2;
}

/* Return priority index which is not equals when compared by two index(idx1,2) in arr[][]. */
int getPriorityIndex(int arr[][ARRAY_WIDTH], int priority[], int idx1, int idx2)
{
    int i = 0;
    
    while (i < ARRAY_WIDTH && arr[idx1][priority[i]] == arr[idx2][priority[i]]) i++;

    return i < ARRAY_WIDTH ? i : -1;
}

/* If left is bigger, return -1. When equal returns 0, or 1.*/
int compare(int arr[][ARRAY_WIDTH], int priority[], int idxLeft, int idxRight)
{
    int p = getPriorityIndex(arr, priority, idxLeft, idxRight), offset;
    if (p == -1) return 0;

    switch (priority[p])
    {
        case DAY_IDX:
            offset = 1;     // incresing sort
            break;

        case WORTH_IDX:
            offset = -1;    // decresing sort
            break;    
    }

    if (arr[idxLeft][priority[p]] > arr[idxRight][priority[p]])
        return -1 * offset;
    else
        return 1 * offset;
}

int getFinalScore(int homework[][ARRAY_WIDTH], int n)
{
    int i, currDay = 1, score = 0;

    for (i = 0; i < n; i++)
    {
        if (currDay <= homework[i][DAY_IDX])
        {
            score += homework[i][WORTH_IDX];
            currDay++;
        }
    }

    return score;
}

void printArray(int arr[][ARRAY_WIDTH], int start, int end)
{
    int i, j;

    std::cout << "\n*** NOW HOMEWORK ***" << std::endl;;
    for (i = start; i < end; i++)
    {
        std::cout << "[" << i << "] ";
        for (j = 0; j < ARRAY_WIDTH; j++)
        {
            std::cout << arr[i][j] << ", ";
        }
        std::cout << "\b\b\n";
    }
    std::cout << "***              ***" << std::endl;
}