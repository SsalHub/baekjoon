#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char result[100], temp;
    int N, B, n, i = 0;
    cin >> N >> B;
    while (N)
    {
        n = N % B;
        if (n < 10)
            n += '0';
        else
            n = (n - 10) + 'A';
        result[i++] = n;
        N /= B;
    }
    result[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        temp = result[j];
        result[j] = result[i - 1 - j];
        result[i - 1 - j] = temp;
    }
    cout << result << "\n";
    return 0;
}