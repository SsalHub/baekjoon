#include <iostream>
#include <cstring>

#define _MAX_LEN_ 1000

int getLCSLen(char col[], char row[]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    char s1[_MAX_LEN_+1], s2[_MAX_LEN_+1];

    std::cin >> s1 >> s2;
    std::cout << getLCSLen(s1, s2);

    return 0;
}

int getLCSLen(char col[], char row[])
{
    int i, j, colLen = strlen(col), rowLen = strlen(row), table[colLen+1][rowLen+1];

    memset(table, 0, sizeof(table));
    for (i=1; i<colLen+1; i++)
    {
        for (j=1; j<rowLen+1; j++)
        {
            if (col[i-1] != row[j-1])
            {
                table[i][j] = std::max(table[i][j-1], table[i-1][j]);
                continue;
            }
            table[i][j] = table[i-1][j-1] + 1;
        }
    }

    return table[colLen][rowLen];
}
