#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    bool student[31] = {
        false,
    };
    int n;
    while (std::cin >> n)
        student[n] = true;
    for (int i = 1; i < 31; i++)
    {
        if (!student[i])
            std::cout << i << "\n";
    }
    return 0;
}