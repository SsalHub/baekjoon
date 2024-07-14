#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, v, input, arr[201] = {
                         0,
                     };
    std::cin >> N;
    while (N--)
    {
        std::cin >> input;
        arr[input + 100]++;
    }
    std::cin >> v;
    std::cout << arr[v + 100] << "\n";
    return 0;
}