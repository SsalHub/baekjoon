#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int matrix[9][9], input, max_X = 0, max_Y = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> input;
            matrix[i][j] = input;
            if (i == 0 && j == 0)
                continue;
            if (matrix[max_Y][max_X] < input)
            {
                max_X = j;
                max_Y = i;
            }
        }
    }
    cout << matrix[max_Y][max_X] << "\n"
         << max_Y + 1 << " " << max_X + 1 << "\n";
    return 0;
}