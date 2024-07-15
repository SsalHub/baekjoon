#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int pieces[6] = {1, 1, 2, 2, 2, 8};
    int input;
    for (int i = 0; i < 6; i++)
    {
        std::cin >> input;
        std::cout << pieces[i] - input << " ";
    }
    return 0;
}