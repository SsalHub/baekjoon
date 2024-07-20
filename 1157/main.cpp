#include <iostream>

char getFreqAlphabet(char s[]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char S[1000001];
    std::cin >> S;
    std::cout << getFreqAlphabet(S);
    return 0;
}

char getFreqAlphabet(char s[])
{
    int i = 0, max = -1, freq[26] = {
                             0,
                         };
    char result = ' ';
    while (s[i])
    {
        if ('a' <= s[i] && s[i] <= 'z')
            freq[s[i] - 'a']++;
        else
            freq[s[i] - 'A']++;
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        if (max < freq[i])
        {
            max = freq[i];
            result = i + 'A';
        }
        else if (max == freq[i])
            result = '?';
    }
    return result;
}