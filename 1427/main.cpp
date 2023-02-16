#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[10] = { 0 };
    char c;

    while(true) {
        c = std::cin.get();
        if(c == '\n') break;
        arr[c-48]++;
    }

    for(int i=9; 0<=i; i--) {
        for(int j=0; j<arr[i]; j++) {
            std::cout << i;
        }
    }

    return 0;
}