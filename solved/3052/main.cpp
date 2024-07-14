#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    bool arr[42] = {
        false,
    };
    int input, result = 0;
    for (int i = 0; i < 10; i++)
    {
        std::cin >> input;
        if (!arr[input % 42])
        {
            arr[input % 42] = true;
            result++;
        }
    }
    std::cout << result << "\n";
    return 0;
}