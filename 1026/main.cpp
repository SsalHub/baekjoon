#include <stdio.h>

struct Graph {
    int a;
    int b;
};

int main() {
    int a[101] = { 0 };
    int b[101] = { 0 };
    int n, sum, i, j;

    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        a[input]++;
    }

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        b[input]++;
    }

    sum = i = 0;
    j = 100;
    for(int k=0; k<n; k++) {
        while(a[i] == 0) {
            i++;
        }

        while(b[j] == 0) {
            j--;
        }

        sum += i * j;
        a[i]--;
        b[j]--;
    }

    printf("%d\n", sum);

    return 0;
}