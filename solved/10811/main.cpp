#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, i, j, temp;
    cin >> N >> M;
    int basket[N + 1] = {
        0,
    };
    while (M--)
    {
        cin >> i >> j;
        for (int x = 0; x < (j - i + 1) / 2; x++)
        {
            temp = !basket[i + x] ? i + x : basket[i + x];
            basket[i + x] = !basket[j - x] ? j - x : basket[j - x];
            basket[j - x] = temp;
        }
    }
    for (int x = 1; x < N + 1; x++)
    {
        cout << (!basket[x] ? x : basket[x]) << " ";
    }
    cout << "\n";
    return 0;
}