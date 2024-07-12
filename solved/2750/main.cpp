#include <stdio.h>

void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);

int main() {
    int n;
    int arr[1000];

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void quickSort(int* arr, int left, int right) {
    if(left < right) {
        int q = partition(arr, left, right);

        quickSort(arr, left, q);
        quickSort(arr, q+1, right);
    }
}

int partition(int* arr, int left, int right) {
    int middle = (left + right) / 2;
    int pivot = arr[middle];
    int low = left - 1;
    int high = right + 1;

    do {
        do {
            low++;
        } while(low <= right && arr[low] < pivot);

        do {
            high--;
        } while(left <= high && pivot < arr[high]);

        if(low < high) {
            swap(arr+low, arr+high);
        }
    } while(low < high);

    return high;
}

void swap(int* a, int* b) {
    if(*a == *b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}