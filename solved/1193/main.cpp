#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int X, i, _x, _y;
    cin >> X;
    for (i = 1; 0 < X; i++)
        X -= i;
    i--;
    if (i % 2)
    {
        _x = 1;
        _y = i;
        while (X++)
        {
            _x++;
            _y--;
        }
    }
    else
    {
        _x = i;
        _y = 1;
        while (X++)
        {
            _x--;
            _y++;
        }
    }
    cout << _x << "/" << _y << "\n";
    return 0;
}