#include <iostream>

int main()
{
    int N, floor = 1, area;
    std::cin >> N;
    while (0 < N)
    {
        if (floor == 1)
            area = 1;
        else
            area = (floor - 1) * 6;
        N -= area;
        floor++;
    }
    floor--;
    std::cout << floor << "\n";
    return 0;
}