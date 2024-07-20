#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int units[4] = {25, 10, 5, 1};
    int T, C;
    cin >> T;
    while (T--)
    {
        cin >> C;
        for (int i = 0; i < 4; i++)
        {
            cout << (C / units[i]) << " ";
            C %= units[i];
        }
        cout << "\n";
    }
    return 0;
}