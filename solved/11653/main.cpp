#include <iostream>

int main()
{
    int N, i = 2;
    std::cin >> N;
    while (1 < N)
    {
        if (N % i)
        {
            i++;
        }
        else
        {
            std::cout << i << "\n";
            N /= i;
        }
    }
    return 0;
}