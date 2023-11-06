#include <iostream>
#include <cstring>
#include <cmath>

#define MAX_N 1000


int partition(int deadline[], int score[], int left, int right);
void qsort(int deadline[], int score[], int left, int right);
void swap(int deadline[], int score[], int idx1, int idx2);
int compare(int deadline[], int score[], int idx1, int idx2);
int getMaxScore(int n, int deadline[], int score[]);
void printArray(int deadline[], int score[], int beg, int end);

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

    qsort(deadline, score, 0, n-1);

    maxScore = getMaxScore(n, deadline, score);

    std::cout << maxScore << std::endl; 

    return 0;
}

int partition(int deadline[], int score[], int left, int right)
{
    int pivot = left, tmp_left = left+1, low = tmp_left, high = right;

    while (low < high)
    {
        while (low <= right && compare(deadline, score, low, pivot) < 0)
        {
            low++;
        }
        while (tmp_left <= high && 0 < compare(deadline, score, pivot, high))
        {
            high--;
        }

        if (low < high)
            swap(deadline, score, low, high);
    }
    if (compare(deadline, score, pivot, high) < 0)
        swap(deadline, score, pivot, high);

    printArray(deadline, score, left, right);

    return high;
}

void qsort(int deadline[], int score[], int left, int right)
{
    if (!(left < right))
        return;

    printArray(deadline, score, left, right);
    int pivot = partition(deadline, score, left, right);
    qsort(deadline, score, left, pivot-1);
    qsort(deadline, score, pivot+1, right);
}

void swap(int deadline[], int score[], int idx1, int idx2)
{
    if (idx1 == idx2) return;
    int tmp;

    tmp = deadline[idx1];
    deadline[idx1] = deadline[idx2];
    deadline[idx2] = tmp;

    tmp = score[idx1];
    score[idx1] = score[idx2];
    score[idx2] = tmp;
}

int compare(int deadline[], int score[], int idx1, int idx2)
{
    if (deadline[idx1] == deadline[idx2]) 
    {
        if (score[idx1] == score[idx2]) return 0;
        //else
        if (score[idx1] < score[idx2]) return 1;
        else return -1;
    }
    // else
    if (deadline[idx1] < deadline[idx2]) return 1;
    else return -1;
}

int getMaxScore(int n, int deadline[], int score[])
{
    //int len = sizeof(deadline) / sizeof(int);
    int len = pow(2, n);
    int table[n+1][len+1] = { 0, };
    int i, j, maxWith, maxWithout, max;

    std::cout << "[ Get Max Score ] " << std::endl;
    for (i = n; 0 < i; i--)     // recent day (reversed). it makes sure whether deadline is over.
    {
        std::cout << "[ ";
        for (j = 0; j < len; j++)
        {
            maxWith = score[i-1] + table[i-1][j-1];
            maxWithout = table[i-1][j-1];
            table[i-1][j] = std::max(maxWith, maxWithout);
            std::cout << table[i-1][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << " Result : " << table[1][len] << std::endl;

    return table[1][len];
}

void printArray(int deadline[], int score[], int beg, int end)
{
    int i;

    std::cout << "[ Print Array ] " << std::endl;
    std::cout << "* deadline array " << std::endl;
    std::cout << "[ ";
    for (i = beg; i <= end; i++)
    {
        std::cout << deadline[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "* score array " << std::endl;
    std::cout << "[ ";
    for (i = beg; i <= end; i++)
    {
        std::cout << score[i] << " ";
    }
    std::cout << "]" << std::endl;
}