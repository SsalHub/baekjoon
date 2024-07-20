#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    bool field[100][100];
    int N, W, H, area = 0;
    std::fill(&(field[0][0]), &(field[99][100]), 0);
    std::cin >> N;
    while (N--)
    {
        std::cin >> W >> H;
        for (int i = 0; i < 10; i++)
        {
            std::fill(&(field[H - 1 + i][W - 1]), &(field[H - 1 + i][W - 1 + 10]), 1);
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (field[i][j])
                area++;
        }
    }
    std::cout << area << "\n";
    return 0;
}