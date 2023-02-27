#include <stdio.h>
#include <map>

void sort(int* arr, std::map<int, int> *map, int len);

int main() {
    int n;
    int* arr;
    std::map<int, int> map; 

    scanf("%d", &n);
    arr = new int[n];

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    sort(arr, &map, n);

    return 0;
}

void sort(int* arr, std::map<int, int> *map, int len) {
    for(int i=0; i<len; i++) {
        (*map)[arr[i]] += 1;
    }
}