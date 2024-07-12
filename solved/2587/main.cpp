#include <iostream>

using namespace std;

void quicksort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int &n1, int &n2);

int main()
{
    ios_base::sync_with_stdio(false);
    int total = 0, mid, arr[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    quicksort(arr, 0, 4);

    cout << total / 5 << "\n"
         << arr[2];

    return 0;
}

void quicksort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right)
{
    int pivot = left, l = left, r = right + 1;

    do
    {
        do
        {
            l++;
        } while (arr[l] < arr[pivot]);

        do
        {
            r--;
        } while (arr[pivot] < arr[r]);

        if (l <= r)
        {
            swap(arr[l], arr[r]);
        }
    } while (l <= r);
    swap(arr[pivot], arr[r]);
    return r;
}

void swap(int &n1, int &n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}