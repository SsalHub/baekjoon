#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char matrix[5][16];
    std::fill(&(matrix[0][0]), &(matrix[4][16]), 0);
    for (int i = 0; i < 5; i++)
    {
        std::cin.getline(matrix[i], 16);
    }
    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (matrix[i][j])
                std::cout << matrix[i][j];
        }
    }
    std::cout << "\n";
    return 0;
}