#include <stdio.h>

void mergeSort(int* arr, int* sub, int left, int mid, int right);
void merge(int* arr, int* sub, int left, int mid, int right);


int main() {
    int n, m, sum;
    int *card, *sub, *find;

    scanf("%d", &n);
    card = new int[n];
    sub = new int[n];

    for(int i=0; i<n; i++) {
        scanf("%d", card+i);
    }

    scanf("%d", &m);
    find = new int[m];

    for(int i=0; i<m; i++) {
        scanf("%d", find+i);
    }

    mergeSort(card, sub, 0, (n-1)/2, n-1);

    for(int i=0; i<m; i++) {
        int count = 0, j = 0;
        while(j < n && find[i] != card[j]) {
            j++;
        }
        if(j >= n) {
            printf("0 ");
            continue;
        }

        while(j < n && find[i] == card[j]) {
            count++; j++;
        }
        printf("%d ", count);
    }

    delete []card;
    delete []sub;
    delete []find;

    return 0;
}

void mergeSort(int* arr, int* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(arr, sub, left, (left+mid)/2, mid);
        mergeSort(arr, sub, mid+1, ((mid+1)+right)/2, right);
    }
    merge(arr, sub, left, mid, right);
}

void merge(int* arr, int* sub, int left, int mid, int right) {
    int i=left, j=mid+1, k=0;

    while(i<=mid && j<=right) {
        if(arr[i] < arr[j]) {
            sub[k++] = arr[i++];
        }
        else {
            sub[k++] = arr[j++];
        }
    }

    while(i<=mid ^ j<=right) {
        if(i <= mid) {
            sub[k++] = arr[i++];
        }
        else {
            sub[k++] = arr[j++];
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        arr[i] = sub[k++];
    }
}