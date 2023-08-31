#include <stdio.h>

void mergeSort(int* arr, int* sub, int left, int mid, int right);
void merge(int* arr, int* sub, int left, int mid, int right);
int binarySearch(int* arr, int left, int mid, int right, int data);

int main() {
    int *card, *sub, *find;
    int n, m;

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
        int data = find[i], j, bin, _left, _right;
        int idx = binarySearch(card, 0, (n-1)/2, n-1, data);
        if(idx == -1) {
            printf("0 ");
            continue;
        }

        j = idx - 1;
        while(0 <= j && card[j] == data) {
            j /= 2;
            if()
        }
        _left = j + 1;

        j = idx + 1;
        while(j <= n-1 && card[j] == data) j++;
        _right = j - 1;

        printf("%d ", _right - _left + 1);
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

int binarySearch(int* arr, int left, int mid, int right, int data) {
    if(arr[mid] == data) return mid;

    if(left < right) {
        if(data < arr[mid])
            return binarySearch(arr, left, (left+(mid-1))/2, mid-1, data);
        else 
            return binarySearch(arr, mid+1, ((mid+1)+right)/2, right, data);
    }

    return -1;
}