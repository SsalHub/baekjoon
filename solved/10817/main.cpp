#include <stdio.h>
#include <string>

void swap(int*, int*);

int main() {
    const int SIZE = 3;
    int n;
    int arr[SIZE];
    std::string str;

    int input;
    scanf("%d %d %d", arr+0, arr+1, arr+2);

    for(int i=0; i<SIZE-1; i++) {
        for(int j=1; j<SIZE; j++) {
            if(arr[j] < arr[i]) swap(arr+i, arr+j);
        }
    }

    printf("%d", arr[1]);

    return 0;
}

void swap(int* n1, int* n2) {
    if(*n1 == *n2) return;
    *n1 ^= *n2;
    *n2 ^= *n1;
    *n1 ^= *n2;
}