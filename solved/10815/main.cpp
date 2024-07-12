#include <stdio.h>

void mergeSort(int* arr, int* sub, int left, int mid, int right);
void merge(int* arr, int* sub, int left, int mid, int right);
bool binarySearch(int* arr, int left, int mid, int right, int data);


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
        if(binarySearch(card, 0, (n-1)/2, n-1, find[i])) printf("1 ");
        else printf("0 ");
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

bool binarySearch(int* arr, int left, int mid, int right, int data) {
    if(arr[mid] == data) return true;

    if(left < right) {
        if(data < arr[mid]) {
           return binarySearch(arr, left, (left+(mid-1))/2, mid-1, data); 
        }
        else {
            return binarySearch(arr, mid+1, ((mid+1)+right)/2, right, data);
        }
    }

    return false;
}
