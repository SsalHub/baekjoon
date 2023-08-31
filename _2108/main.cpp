#include <stdio.h>
#include <map>

void sort(int* arr, std::map<int, int>* map, int len);

int main() {
    int n, i, result, max;
    int* arr;
    std::map<int, int> map;

    scanf("%d", &n);
    arr = new int[n];

    for(int i=0; i<n; i++) {
        int input;
        scanf("%d", &input);
        arr[i] = input;
        map[input]++;
    }

    i = 0;
    for(auto const& [key, val] : map) {
        for(; i<val; i++) {
            arr[i++] = key;
        }
    }


    result = 0;
    for(int i=0; i<n; i++) {
       result += arr[i] ;
    }

    printf("%d\n", result / n);

    printf("%d\n", arr[n/2]);

    max = -1;
    for(auto const& [key, value] : map) {
        max = max < map[key] ? map[key] : max; 
    }

    printf("%d\n", max);

    printf("%d\n", arr[n-1] - arr[0]);

    return 0;
}