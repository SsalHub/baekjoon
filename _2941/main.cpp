#include <iostream>

void setCroAlpbArray(char arr[]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char croAlpb[127] = {
        0,
    };
    setCroAlpbArray(croAlpb);
    char S[101];
    std::cin >> S;
    int i = 0, j, result = 0;
    while (S[i])
    {
        j = 0;
        if (croAlpb[S[i]] == 0)
        {
            i++;
            continue;
        }
        }
    return 0;
}

void setCroAlpbArray(char arr[])
{
    arr['c'] = ' ';
    arr[('c' - 'a') * 2] = 'z';
    arr[('c' - 'a') * 2 + 1] = '-';
    arr['d'] = ' ';
    arr[('d' - 'a') * 2] = 'z';
    arr[('d' - 'a') * 2 + 1] = '-';

    arr['l'] = 'j';
    arr['n'] = 'j';
    arr['s'] = '=';
    arr['z'] = '=';
}