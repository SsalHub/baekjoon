#include <iostream>
#include <cstring>

#define MAX_N 1000
#define ARRAY_WIDTH 2
#define DAY 0
#define WORTH 1
#define EQUALS(n1, n2) n1 == n2

using namespace std;

int partition(int arr[][ARRAY_WIDTH], int priority[], int left, int right);
void qsort(int arr[][ARRAY_WIDTH], int priority[], int left, int right);
void swap(int* e1, int* e2);
void setPriority(int priority[], int bestP, int betterP);
int getPriorityIndex(int arr[][ARRAY_WIDTH], int priority[], int idx1, int idx2);
int compare(int arr[][ARRAY_WIDTH], int priority[], int idxLeft, int idxRight);
int getFinalScore(int homework[][ARRAY_WIDTH], int n);

int main()
{
    int i, n;
    int homework[MAX_N][ARRAY_WIDTH], priority[ARRAY_WIDTH], score[ARRAY_WIDTH];

    cin >> n;


    for (i = 0; i < n; i++)
    {
        cin >> homework[i][DAY];
        cin >> homework[i][WORTH];
    }

    /* First Sorting By DAY */
    setPriority(priority, DAY, WORTH);
    qsort(homework, priority, 0, n-1);
    score[DAY] = getFinalScore(homework, n);
    
    /* First Sorting By WORTH */
    setPriority(priority, WORTH, DAY);
    qsort(homework, priority, 0, n-1);
    score[WORTH] = getFinalScore(homework, n);

    cout << (score[DAY] > score[WORTH] ? score[DAY] : score[WORTH]) << endl;

    return 0;
}

/* Incresing Sorting with priority array. */
int partition(int arr[][ARRAY_WIDTH], int priority[], int left, int right)
{
    int pivot = left, tmp_left = left+1, low = tmp_left, high = right;

    while (low < high)
    {
        // while (low <= right && arr[low][priority] <= arr[pivot][priority])
        
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
    swap(arr[pivot], arr[high]);
    return high;
}

void qsort(int arr[][ARRAY_WIDTH], int priority[], int left, int right)
{
    if (!(right <= left))
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
void setPriority(int priority[], int bestP, int betterP)
{
    priority[0] = bestP;
    priority[1] = betterP;
}

/* Return priority index which is not equals when compared by two index(idx1,2) in arr[][]. */
int getPriorityIndex(int arr[][ARRAY_WIDTH], int priority[], int idx1, int idx2)
{
    int i;
    
    i = 0;
    while (EQUALS(arr[idx1][priority[i]], arr[idx2][priority[i]])) continue;

    return i;
}

/* If left is bigger, return -1. Equal returns 0, or 1.*/
int compare(int arr[][ARRAY_WIDTH], int priority[], int idxLeft, int idxRight)
{
    int p = getPriorityIndex(arr, priority, idxLeft, idxRight);
    
    if (arr[idxLeft][priority[p]] > arr[idxRight][priority[p]])
        return -1;
    else
    {
        if (arr[idxLeft][priority[p]] == arr[idxRight][priority[p]])
            return 0;
        else
            return 1;
    }
}

int getFinalScore(int homework[][ARRAY_WIDTH], int n)
{
    int i, score = 0;

    for (i = 0; i < n; i++)
    {
        if (homework[i][DAY] <= i)
            score += homework[i][WORTH];
    }

    return score;
}