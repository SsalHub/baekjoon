#include <iostream>
#include <cstring>

#define MAX_N 1000
#define PRIO_LEN 2

typedef struct Homework
{
    int deadline;
    int score;
} Homework;

typedef struct TreeNode
{
    Homework data;
    struct TreeNode *child[PRIO_LEN];
} TreeNode;

typedef enum PriorityType
{
    _DEADLINE_,
    _SCORE_,
} PriorityType;

int partition(Homework arr[], PriorityType priority[], int left, int right);
void qsort(Homework arr[], PriorityType priority[], int left, int right);
void swap(Homework* e1, Homework* e2);
int compare(Homework arr[], PriorityType priority[], int idxLeft, int idxRight);
int getMaxScore();
void printArray(Homework arr[], PriorityType priority[], int start, int end);

int main()
{
    Homework orderInDeadline[MAX_N], orderInScore[MAX_N];
    PriorityType priority[PRIO_LEN];
    int i, n, maxScore;

    std::cin >> n;

    for (i = 0; i < n; i++)
    {
        std::cin >> orderInDeadline[i].deadline;
        std::cin >> orderInDeadline[i].score;
    }
    memcpy(orderInScore, orderInDeadline, n * sizeof(Homework));

    /* First Sorting By _DEADLINE_, Increasing Sort */
    priority[0] = _DEADLINE_;
    priority[1] = _SCORE_;
    qsort(orderInDeadline, priority, 0, n-1);
    printArray(orderInDeadline, priority, 0, n);
    
    /* Second Sorting By _SCORE_, Decreasing Sort */
    priority[0] = _SCORE_;
    priority[1] = _DEADLINE_;
    qsort(orderInScore, priority, 0, n-1);
    printArray(orderInScore, priority, 0, n);

    maxScore = getMaxScore();

    std::cout << maxScore << std::endl; 

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
    int tmp[PRIO_LEN];

    memcpy(tmp, e1, PRIO_LEN*sizeof(int));
    memcpy(e1, e2, PRIO_LEN*sizeof(int));
    memcpy(e2, tmp, PRIO_LEN*sizeof(int));
}

/* Returns the bigger one. If left is bigger, returns -1. When they're equal, returns 0, or 1.*/
int compare(Homework arr[], PriorityType priority[], int idx1, int idx2)
{
    int i;

    for (i = 0; i < PRIO_LEN; i++)
    {
        switch (priority[i])
        {
            case _DEADLINE_:
                if (arr[idx1].deadline != arr[idx2].deadline)
                {
                    if (arr[idx1].deadline < arr[idx2].deadline)
                        return 1;
                    else 
                        return -1;
                }
                else
                {
                    break;     // continue loop
                }

            case _SCORE_:
                if (arr[idx1].score != arr[idx2].score)
                {
                    //if (arr[idx1].score < arr[idx2].score)
                    if (arr[idx1].score >= arr[idx2].score)     // reversed (to make decreasing sort)
                        return 1;
                    else 
                        return -1;
                }
                else
                {
                    break;     // continue loop
                }

            default:
                return 0;
        }
    }

    /* Checked with Every Priority Element == Those Two Data Equal, So It Returns 0. */
    return 0;
}

int getMaxScore()
{

    return 0;
}

void printArray(Homework arr[], PriorityType priority[], int start, int end)
{
    int i, j;

    std::cout << "\n*** NOW HOMEWORK ***" << std::endl;
    std::cout << "Best Priority : ";
    switch (priority[0])
    {
        case _DEADLINE_:
            std::cout << "Deadline";
            break;
            
        case _SCORE_:
            std::cout << "Score";
            break;
        
        default:
            break;
    }
    std::cout << std::endl;
    for (i = start; i < end; i++)
    {
        std::cout << "[" << i << "] " << arr[i].deadline << ", " << arr[i].score << std::endl;
    }
    std::cout << "***              ***" << std::endl;
}