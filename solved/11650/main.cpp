#include <stdio.h>

struct Graph {
    int x;
    int y;
};

void mergeSort(Graph*, Graph*, int, int, int);
void merge(Graph*, Graph*, int, int, int);

int main() {
    Graph* graphs;
    Graph* sorted;
    int n, left, mid, right;

    scanf("%d", &n);
    graphs = new Graph[n];
    sorted = new Graph[n];

    for(int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graphs[i].x = x;
        graphs[i].y = y;
    }

    left = 0;
    right = n - 1;
    mid = (left + right) / 2;
    mergeSort(graphs, sorted, left, mid, right);

    for(int i=0; i<n; i++) {
        printf("%d %d\n", graphs[i].x, graphs[i].y);
    }

    delete []graphs;
    delete []sorted;

    return 0;
}

void mergeSort(Graph* graphs, Graph* sorted, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(graphs, sorted, left, (left+mid)/2, mid);
        mergeSort(graphs, sorted, mid+1, ((mid+1)+right)/2, right);
    }

    merge(graphs, sorted, left, mid, right);
}

void merge(Graph* graphs, Graph* sorted, int left, int mid, int right) {
    int i, j, k;

    i = left;
    j = mid + 1;
    k = 0;
    while(i<=mid && j<=right) {
        if(graphs[i].x < graphs[j].x) {
            sorted[k++] = graphs[i++];
        }
        else if(graphs[i].x > graphs[j].x) {
            sorted[k++] = graphs[j++];
        }
        else {
            if(graphs[i].y < graphs[j].y) {
                sorted[k++] = graphs[i++];
            }
            else if(graphs[i].y > graphs[j].y) {
                sorted[k++] = graphs[j++];
            }
            else {
                printf("메롱\n");
            }
        }
    }

    while(i<=mid ^ j<=right) {
        if(i<=mid) {
            sorted[k++] = graphs[i++];
        }
        else {
            sorted[k++] = graphs[j++];
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        graphs[i] = sorted[k++];
    }
}