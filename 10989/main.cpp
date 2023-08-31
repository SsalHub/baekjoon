#include <iostream>
#include <string>



int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, input;
    int arr[10001] = { 0 };
    
    std::cin >> n;
    
    for(int i=0; i<n; i++) {
        std::cin >> input;
        arr[input] += 1;
        
    }
    
    for(int i=1; i<=10000; i++) {
        for(int j=0; j<arr[i]; j++) {
            std::cout << i << '\n';
        }
    }

    return 0;
}