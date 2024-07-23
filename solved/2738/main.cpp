#include <iostream>
#include <cstring>

#define MAX 100

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int matrix[MAX][MAX], N, M, input;
    std::cin >> N >> M;
    std::fill(&(matrix[0][0]), &(matrix[MAX - 1][MAX]), 0);
    for (int i = 0; i < N * 2; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> input;
            matrix[i % N][j] += input;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}