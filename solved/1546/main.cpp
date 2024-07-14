#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, score, max = -1;
    float avg = 0.0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> score;
        if (max < score)
            max = score;
        avg += score;
    }
    avg = avg / (max * N) * 100.0;
    std::cout << avg << "\n";
    return 0;
}