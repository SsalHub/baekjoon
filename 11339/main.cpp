#include <stdio.h>

void mergeSort(int*, int, int, int);
void merge(int*, int, int, int);

int main() {
    int n, left, mid, right, sum;
    int user[1000];

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        user[i] = input;
    }

    left = 0;
    right = n - 1;
    mid = (left + right) / 2;

    mergeSort(user, left, mid, right);

    sum = 0;
    for(int i=0; i<n; i++) {
        int _sum = 0;
        for(int j=0; j<=i; j++) {
            _sum += user[j];
        }
        sum += _sum;
    }

    printf("%d\n", sum);

    return 0;
}

void mergeSort(int* user, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(length <= 1) return;

    mergeSort(user, left, (left+mid)/2, mid);
    mergeSort(user, mid+1, ((mid+1)+right)/2, right);

    merge(user, left, mid, right);
}

void merge(int* user, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int length = (right - left) + 1;
    int* sorted = new int[length];

    while(i <= mid && j <= right) {
        if(user[i] < user[j]) {
            sorted[k++] = user[i++];
        }
        else {
            sorted[k++] = user[j++];
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sorted[k++] = user[i++];
        }
        else {
            sorted[k++] = user[j++];
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        user[i] = sorted[k++];
    }

    delete []sorted;
}
