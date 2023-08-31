#include <stdio.h>

void mergeSort(int* height, int* sub, int left, int mid, int right);
void merge(int* height, int* sub, int left, int mid, int right);

int main() {
    const int SIZE = 9;
    int height[SIZE] = { 0 };
    int sub[SIZE] = { 0 };
    int subidx, sum;

    for(int i=0; i<SIZE; i++) {
        scanf("%d", height+i);
    }
    
    mergeSort(height, sub, 0, (SIZE-1)/2, SIZE-1);

    for(int i=0; i<SIZE-1; i++) {
        for(int j=i+1; j<SIZE; j++) {
            subidx = sum = 0;

            for(int k=0; k<SIZE; k++) {
                if(k == i || k == j) continue;
                sub[subidx++] = height[k];
                sum += height[k];
            }

            if(sum == 100) {
                for(int i=0; i<7; i++) {
                    printf("%d\n", sub[i]);
                }
                return 0;
            }
        }
    }


    return 0;
}

void mergeSort(int* height, int* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(height, sub, left, (left+mid)/2, mid);
        mergeSort(height, sub, mid+1, ((mid+1)+right)/2, right);
    }

    merge(height, sub, left, mid, right);
}

void merge(int* height, int* sub, int left, int mid, int right) {
    int i=left, j=mid+1, k=0;

    while(i <= mid && j <= right) {
        if(height[i] < height[j]) {
            sub[k++] = height[i++];
        }
        else {
            sub[k++] = height[j++];
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sub[k++] = height[i++];
        }
        else {
            sub[k++] = height[j++];
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        height[i] = sub[k++];
    }
}