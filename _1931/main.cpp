#include <stdio.h>

struct Graph {
    int x;
    int y;
};

void mergeSort(Graph*, Graph*, int, int, int);
void merge(Graph*, Graph*, int, int, int);
int getCount(Graph* arr, int* visited, int size, int idx);

int main() {
    Graph *arr, *sub;
    int n, count, max;
    int* visited;

    scanf("%d", &n);
    arr = new Graph[n];
    sub = new Graph[n];
    visited = new int[n] {0, };

    for(int i=0; i<n; i++) {
        scanf("%d %d", &(arr[i].x), &(arr[i].y));
    }

    mergeSort(arr, sub, 0, (n-1)/2, n-1);

    max = 0;
    for(int i=0; i<n-max; i++) {
        count = getCount(arr, visited, n, i);
        max = max < count ? count : max;
    }

    printf("%d\n", max);

    delete []arr;
    delete []sub;
    delete []visited;

    return 0;
}

void mergeSort(Graph* arr, Graph* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(arr, sub, left, (left+mid)/2, mid);
        mergeSort(arr, sub, mid+1, ((mid+1)+right)/2, right);
    }

    merge(arr, sub, left, mid, right);
}

void merge(Graph* arr, Graph* sub, int left, int mid, int right) {
    int i, j, k;

    i = left;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= right) {
        if(arr[i].x < arr[j].x) {
            sub[k].x = arr[i].x;
            sub[k].y = arr[i].y;
            k++; i++; 
        }
        else if(arr[i].x > arr[j].x) {
            sub[k].x = arr[j].x;
            sub[k].y = arr[j].y;
            k++; j++;
        }
        else {
            if(arr[i].y < arr[j].y) {
                sub[k].x = arr[i].x;
                sub[k].y = arr[i].y;
                k++; i++; 
            }
            else {
                sub[k].x = arr[j].x;
                sub[k].y = arr[j].y;
                k++; j++;
            }
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sub[k].x = arr[i].x;
            sub[k].y = arr[i].y;
            k++; i++;
        }
        else {
            sub[k].x = arr[j].x;
            sub[k].y = arr[j].y;
            k++; j++;
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        arr[i].x = sub[k].x;
        arr[i].y = sub[k].y;
        k++;
    }
}

int getCount(Graph* arr, int* visited, int size, int idx) {
    if(visited[idx] != 0) return visited[idx];
    int i, max;

    i = idx + 1;
    while(i<size && arr[idx].y>arr[i].x) {
        i++;
    }

    if(i >= size) {
        visited[idx] = 1;
        return 1;
    }

    max = 0;
    for(int j=i; j<size; j++) {
        int count = getCount(arr, visited, size, j);
        max = max < count ? count : max;
    }
    visited[idx] = max + 1;
    return visited[idx];
}
        