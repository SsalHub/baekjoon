#include <iostream>
#include <cstring>

#define MAX_N 1000
#define ARRAY_WIDTH 2

typedef struct Homework
{
    float deadline;
    int score;
} Homework;

typedef enum PriorityType
{
    _DEADLINE_,
    _SCORE_,
} PriorityType;

int partition(Homework arr[], PriorityType priority[], int left, int right);
void qsort(Homework arr[], PriorityType priority[], int left, int right);
void swap(Homework* e1, Homework* e2);
int compare(Homework arr[], PriorityType priority[], int idxLeft, int idxRight);
int getFinalScore(int len, Homework orderInDeadline[], Homework orderInScore[]);
int getHighestScore(int len, int today, Homework order[], Homework orderInDeadline[], Homework orderInScore[]);
void printArray(Homework arr[], int start, int end);

int main()
{
    Homework orderInDeadline[MAX_N], orderInScore[MAX_N];
    PriorityType priority[ARRAY_WIDTH];
    int i, n;

    std::cin >> n;

    for (i = 0; i < n; i++)
    {
        std::cin >> orderInDeadline[i].deadline;
        std::cin >> orderInDeadline[i].score;
    }
    memcpy(orderInDeadline, orderInScore, n * sizeof(int));

    /* First Sorting By _DEADLINE_, Increasing Sort */
    priority[0] = _DEADLINE_;
    priority[1] = _SCORE_;
    qsort(orderInDeadline, priority, 0, n-1);
    printArray(orderInDeadline, 0, n);
    
    /* Second Sorting By _SCORE_, Decreasing Sort */
    priority[0] = _SCORE_;
    priority[1] = _DEADLINE_;
    qsort(orderInScore, priority, 0, n-1);
    printArray(orderInScore, 0, n);

    std::cout << getFinalScore(n, orderInDeadline, orderInScore);

    return 0;
}

int partition(Homework arr[], PriorityType priority[], int left, int right)
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
            swap(arr+low, arr+high);
    }
    if (compare(arr, priority, pivot, high) < 0)
        swap(arr+pivot, arr+high);
    printArray(arr, left, right);
    return high;
}

void qsort(Homework arr[], PriorityType priority[], int left, int right)
{
    if (!(left < right))
        return;
    int pivot = partition(arr, priority, left, right);
    qsort(arr, priority, left, pivot-1);
    qsort(arr, priority, pivot+1, right);
}

void swap(Homework* e1, Homework* e2)
{
    if (e1 == e2) return;
    int tmp[ARRAY_WIDTH];

    memcpy(tmp, e1, ARRAY_WIDTH*sizeof(int));
    memcpy(e1, e2, ARRAY_WIDTH*sizeof(int));
    memcpy(e2, tmp, ARRAY_WIDTH*sizeof(int));
}

/* If left is bigger, return -1. When equal returns 0, or 1.*/
int compare(Homework arr[], PriorityType priority[], int idxLeft, int idxRight)
{
    int i;

    for (i = 0; i < ARRAY_WIDTH; i++)
    {
        switch (priority[i])
        {
            case _DEADLINE_:
                if (arr[idxLeft].deadline == arr[idxRight].deadline)
                    {
                        if (arr[idxLeft].score < arr[idxRight].score)
                            arr[idxLeft].deadline += 0.1;
                        else
                            arr[idxRight].deadline += 0.1;
                        break;  // continue
                    }
                else
                    {
                        if (arr[idxLeft].deadline < arr[idxRight].deadline)
                            return 1;
                        else 
                            return -1;
                    }

            case _SCORE_:
                if (arr[idxLeft].score == arr[idxRight].score)
                    {
                        break;  // continue
                    }
                else
                    {
                        if (arr[idxLeft].score < arr[idxRight].score)
                            return 1;
                        else 
                            return -1;
                    }

            default:
                return 0;
        }
    }
}

int getFinalScore(int len, Homework orderInDeadline[], Homework orderInScore[])
{
    Homework order[MAX_N];
    
    /* Get Highest Score by Recursive BruteForce */
    return getHighestScore(len, 1, order, orderInDeadline, orderInScore);
}

int getHighestScore(int len, int today, Homework order[], Homework orderInDeadline[], Homework orderInScore[])
{
    int i = today - 1, j, d, s;

    /* Search Deadline Array To Find Satisfying 'deadline' Element */
    for (j = i; j < len; j++)
    {
        if (orderInDeadline[j].deadline < today)
            continue;
    }
    memcpy(order+j, orderInDeadline+j, sizeof(Homework));
    d = getHighestScore(len, today+1, order, orderInDeadline, orderInScore);

    /* Search Score Array To Find Satisfying 'deadline' Element */
    for (j = i; j < len; j++)
    {
        if (orderInScore[j].deadline < today)
            continue;
    }
    memcpy(order+j, orderInScore+j, sizeof(Homework));
    s = getHighestScore(len, today+1, order, orderInDeadline, orderInScore);

    return s > d ? s : d;
}

void printArray(Homework arr[], int start, int end)
{
    int i, j;

    std::cout << "\n*** NOW HOMEWORK ***" << std::endl;;
    for (i = start; i < end; i++)
    {
        std::cout << "[" << i << "] ";
        for (j = 0; j < ARRAY_WIDTH; j++)
        {
            std::cout << arr[i].deadline << ", " << arr[i].score << std::endl;
        }
        std::cout << "\b\b\n";
    }
    std::cout << "***              ***" << std::endl;
}