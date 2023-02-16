#include <stdio.h>

void mergeSort(int*, int, int, int);
void merge(int*, int, int, int);

int main() {
    int* arr;
    int n, left, mid, right;

    scanf("%d", &n);

    arr = new int[n];

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    left = 0;
    right = n - 1;
    mid = (left + right) / 2;

    mergeSort(arr, left, mid, right);

    for(int i=left; i<=right; i++) {
        printf("%d\n", arr[i]);
    }

    delete []arr;

    return 0;
}

void mergeSort(int* arr, int left, int mid, int right) {
    int length = right - left + 1;
    if(length <= 1) return;
    int* sorted = new int[length];

    mergeSort(arr, left, (left+mid)/2, mid);
    mergeSort(arr, mid+1, ((mid+1)+right)/2, right);

    merge(arr, left, mid, right);
    delete []sorted;
}

void merge(int* arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int* sorted = new int[right-left+1];

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            sorted[k++] = arr[i++];
        } 
        else {
            sorted[k++] = arr[j++];
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sorted[k++] = arr[i++];
        }
        else {
            sorted[k++] = arr[j++];
        }
    }

    k = 0;
    for(int idx=left; idx<=right; idx++) {
        arr[idx] = sorted[k++];
    }

    delete []sorted;
}

#if 0
#include <stdio.h>
#include <vector>

void mergeSort(std::vector<int>&, std::vector<int>&, int, int, int);
void merge(std::vector<int>&, std::vector<int>&, int, int, int);

int main() {
    std::vector<int> v;
    std::vector<int> sorted;
    int n, left, mid, right;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    left = 0;
    right = n - 1;
    mid = (left + right) / 2;

    mergeSort(v, sorted, left, mid, right);

    for(int i=0; i<n; i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}

void mergeSort(std::vector<int>& v, std::vector<int>& sorted, int left, int mid, int right) {
    int length = right - left + 1;
    if(length <= 1) return;

    mergeSort(v, sorted, left, (left+mid)/2, mid);
    mergeSort(v, sorted, mid+1, ((mid+1)+right)/2, right);

    merge(v, sorted, left, mid, right);
}

void merge(std::vector<int>& v, std::vector<int>& sorted, int left, int mid, int right) {
    int i = left, j = mid + 1;

    while(i <= mid && j <= right) {
        if(v[i] < v[j]) {
            sorted.push_back(v[i++]);
        } 
        else {
            sorted.push_back(v[j++]);
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sorted.push_back(v[i++]);
        }
        else {
            sorted.push_back(v[j++]);
        }
    }

    for(int idx=left; idx<=right; idx++) {
        v[idx] = sorted.front();
        sorted.erase(sorted.begin());
    }

    sorted.clear();
}
#endif