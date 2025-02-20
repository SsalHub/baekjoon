#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int input, n = -1, times = 0;

    cin >> input;
    while (input != n)
    {
        if (n == -1) n = input;
        if (n < 10)
            n = n + (n * 10);
        else
            n = ((n / 10) + (n % 10)) % 10 + (n % 10 * 10);
        times++;
    }
    cout << times << '\n';
    return 0;
}