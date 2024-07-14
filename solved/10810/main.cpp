#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, i, j, k;
    cin >> N >> M;
    int basket[N + 1] = {
        0,
    };
    while (M--)
    {
        cin >> i >> j >> k;
        fill(basket + i, basket + j + 1, k);
    }
    for (int x = 1; x <= N; x++)
    {
        cout << basket[x] << " ";
    }
    cout << "\n";
    return 0;
}