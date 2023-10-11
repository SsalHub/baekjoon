#include <iostream>
#include <cstring>

#define MAX_N 1000
#define ARRAY_WIDTH 2

typedef struct Homework
{
    int deadline;
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
int getFinalScore(Homework hw1[], Homework hw2[], int n);
void printArray(Homework arr[], int start, int end);

int main()
{
    int i, n;
    Homework orderInDeadline[MAX_N], orderInScore[MAX_N];
    PriorityType priority[ARRAY_WIDTH];

    std::cin >> n;

    for (i = 0; i < n; i++)
    {
        std::cin >> orderInDeadline[i].deadline;
        std::cin >> orderInDeadline[i].score;
    }
    memcpy(orderInDeadline, orderInScore, n * sizeof(int));

    /* First Sorting By _DEADLINE_, increasing sort */
    priority[0] = _DEADLINE_;
    priority[1] = _SCORE_;
    qsort(orderInDeadline, priority, 0, n-1);
    printArray(orderInDeadline, 0, n);
    std::cout << "------ SORT PROCESS DONE ------" << std::endl;
    
    /* First Sorting By WORTH, decreasing sort */
    qsort(orderInScore, priority, 0, n-1);
    printArray(orderInScore, 0, n);



    std::cout << getFinalScore(homework, n);

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
                    break;  // continue
                else
                    if (arr[idxLeft].deadline < arr[idxRight].deadline)
                        return 1;
                    else 
                        return -1;
            
            case _SCORE_:
                if (arr[idxLeft].score == arr[idxRight].score)
                    break;  // continue
                else
                    if (arr[idxLeft].score < arr[idxRight].score)
                        return 1;
                    else 
                        return -1;
            default:
                return 0;
        }
    }
}

int getFinalScore(Homework hw1[], Homework hw2[], int n)
{
    Homework order[MAX_N];
    int i, currDay = 1, score = 0;

    /* Unconditionally bring high score homework on First Day */
    order[0] = hw2[0];

    // hw1 == deadline, hw2 == score
    for (i = 1; i < n; i++)
    {
        order[i] = hw2[i];
    }

    /*
    0. 브루트포스? 근양 싹다해볼까?



    1. 제일 개꿀인걸 땡겨온다
    2. 별로인 과제가 뒤로 밀린다
    3. 다음날에도 개꿀인 과제를 땡겨오되, 밀린 과제와 비교
    i일에 a 과제를 했을 경우와 b 과제를 했을 경우를 모두 계산해보기
    int doHomework(today, hw1, hw2) -> return score?

    */



    return score;
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
            std::cout << arr[i][j] << ", ";
        }
        std::cout << "\b\b\n";
    }
    std::cout << "***              ***" << std::endl;
}