#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, input, i, j;

    cin >> N;
    int A[N + 1] = {
        0,
    };
    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        A[i] = A[i - 1] + input;
    }
    cin >> M;
    while (0 < M--)
    {
        cin >> i >> j;
        cout << A[j] - A[i - 1] << "\n";
    }
    return 0;
}