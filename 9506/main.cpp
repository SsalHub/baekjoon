#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int divisor[1000] = {
        0,
    };
    int n, idx, i, j, sum;
    while (1)
    {
        cin >> n;
        if (n == -1)
            break;
        sum = 1;
        idx = 0;
        divisor[idx++] = 1;
        for (i = 2; i * i <= n; i++)
        {
            if (n % i)
                continue;
            divisor[idx++] = i;
            sum += i + (n / i);
            if (i * i == n)
                sum -= i;
        }
        if (sum != n)
        {
            cout << n << " is NOT perfect." << "\n";
        }
        else
        {
            cout << n << " = " << divisor[0];
            for (j = 1; j < idx; j++)
                cout << " + " << divisor[j];
            if (divisor[j - 1] * divisor[j - 1] == n) // if square number
                idx--;
            for (j = idx - 1; 0 < j; j--)
                cout << " + " << (n / divisor[j]);
            cout << "\n";
        }
    }
    return 0;
}