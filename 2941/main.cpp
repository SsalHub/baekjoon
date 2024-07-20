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
    char S[101], key;
    std::cin >> S;
    int i = 0, j, result = 0;
    while (S[i])
    {
        if (!croAlpb[S[i]])
        {
            // fail
            i++;
            result++;
            continue;
        }
        key = S[i];
        j = 1;
        while (croAlpb[key])
        {
            if (croAlpb[key] != '\n')
            {
                if (croAlpb[key] == S[i + j])
                {
                    key = croAlpb[key];
                    j++;
                }
                else
                {
                    // fail
                    j = 0;
                    break;
                }
            }
            else
            {
                char value_1 = croAlpb[(key - 'a') * 2], value_2 = croAlpb[(key - 'a') * 2 + 1];
                if (S[i + j] == value_1)
                {
                    key = value_1;
                    j++;
                }
                else
                {
                    if (S[i + j] == value_2)
                    {
                        key = value_2;
                        j++;
                    }
                    else
                    {
                        // fail
                        j = 0;
                        break;
                    }
                }
            }
        }
        if (!j) // fail
            i++;
        else // success
            i += j;
        result++;
    }
    std::cout << result << "\n";
    return 0;
}

void setCroAlpbArray(char arr[])
{
    arr['c'] = '\n';
    arr[('c' - 'a') * 2] = '=';
    arr[('c' - 'a') * 2 + 1] = '-';
    arr['d'] = '\n';
    arr[('d' - 'a') * 2] = 'z';
    arr[('d' - 'a') * 2 + 1] = '-';

    arr['l'] = 'j';
    arr['n'] = 'j';
    arr['s'] = '=';
    arr['z'] = '=';
}