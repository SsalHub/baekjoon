#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int alphabet[26], i = 0;
    char S[101];
    std::fill(alphabet, alphabet + 26, -1);
    std::cin >> S;
    while (S[i])
    {
        if (alphabet[S[i] - 'a'] == -1)
            alphabet[S[i] - 'a'] = i;
        i++;
    }
    for (int x = 0; x < 26; x++)
    {
        std::cout << alphabet[x] << " ";
    }
    std::cout << "\n";
    return 0;
}