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
        if (input < 10)
            n = input + 0;
        else
            n = (input / 10) + (input % 10);
        times++;
    }
    cout << times << '\n';
    return 0;
}