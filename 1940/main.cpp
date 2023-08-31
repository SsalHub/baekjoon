#include <iostream>

int conquer(int*, int, int);
void quicksort(int*, int, int);
void switchData(int*, int*);
int countArmor(int*, int, int);

int main()
{
    const int MAX_INPUT = 15000;
    int arr[MAX_INPUT] = { 0 };
    int i, n, m, input, result;

    std::cin >> n;
    std::cin >> m;
    for(i=0; i<n; i++)
    {
        std::cin >> input;
        arr[i] = input;
    }

    quicksort(arr, 0, n-1);
    result = countArmor(arr, n, m);

    std::cout << result;
    return 0;
}

int conquer(int* arr, int left, int right)
{
    int mid = (left+right)/2, pivot = arr[mid], i = left, j = right+1;
    switchData(arr+left, arr+mid);
    do
    {
        do
        {
            if (pivot < arr[++i]) break; 
        } while (i <= right && i <= j);

        do
        {
            if (arr[--j] < pivot) break;
        } while (left < j && i <= j);

        if (i < j) switchData(arr+i, arr+j);
    } while(i < j);
    switchData(arr+left, arr+j);
    return j;
}

void quicksort(int* arr, int left, int right)
{
    int mid = (left + right) / 2, len = right-left, pivot;
    if (len < 1) return;
    pivot = conquer(arr, left, right);
    quicksort(arr, left, pivot); 
    quicksort(arr, pivot+1, right);
}

void switchData(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int countArmor(int* arr, int len, int condition)
{
    int i = 0, j = len, armor = 0;

    while (i < j)
    {
        do {
            j--;
        }
        while(condition < arr[i] + arr[j]);

        while(arr[i] + arr[j] < condition) 
        {
            i++;
        }

        if (condition == arr[i] + arr[j] && i < j) 
        {
            armor++;
        }
    }
    return armor;
}