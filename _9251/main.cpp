#include <iostream>
#include <cstring>

using namespace std;

int getLCSLen(char row[], char col[]);

int main()
{
    ios_base::sync_with_stdio(false);

    char s1[1001], s2[1001];

    cin >> s1 >> s2;
    cout << getLCSLen(s1, s2);

    return 0;
}

int getLCSLen(char row[], char col[])
{
    int rowLen = strlen(row), colLen = strlen(col);
    int table[colLen+1][rowLen+1] = { 0, };
    int i, j;

    for (i = 1; i < colLen+1; i++)
    {
        
    }

    return 0;
}
