#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, seq[1001], increase[1001];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }
    fill(increase, increase + N, 1);
    for (int i = 1; i < N; i++)
    {
        for (int j = i - 1; 0 <= j; j--)
        {
            if (seq[j] < seq[i])
            {
                increase[i] = max(increase[j] + 1, increase[i]);
            }
        }
    }
    int max_len = -1;
    for (int i = 0; i < N; i++)
    {
        max_len = max(max_len, increase[i]);
    }
    cout << max_len;
    return 0;
}