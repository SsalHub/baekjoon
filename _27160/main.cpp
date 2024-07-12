#include <iostream>
#include <string>

using namespace std;

int getHash(int n, string k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, X, fruit[29] = {
                  0,
              };
    string S;

    cin >> N;
    while (N--)
    {
        cin >> S >> X;
        fruit[getHash(29, S)] += X;
    }
    for (int i = 0; i < 29; i++)
    {
        if (fruit[i] == 5)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}

int getHash(int n, string k)
{
    return (int)k[0] % n;
}