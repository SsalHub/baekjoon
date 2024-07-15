#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char dial[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
    char word[16];
    int t = 0, i = 0;
    std::cin >> word;
    while (word[i])
        t += dial[word[i++] - 'A'];
    std::cout << t << "\n";
    return 0;
}