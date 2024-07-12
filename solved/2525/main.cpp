#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int A, B, C;
    std::cin >> A >> B >> C;
    A += C / 60;
    B += C % 60;
    std::cout << (60 <= B ? A + 1 : A) % 24 << " " << B % 60 << "\n";
    return 0;
}