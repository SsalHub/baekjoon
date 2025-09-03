#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

int N;
unordered_map<char, int> X, Y;

int fun(int idx)
{
    int ret = 0;
    for (int i = X[97 + idx]; i <= Y[97 + idx]; i++)
    {
        if (idx >= N)
            ret = (ret + 1) % 1000000007;
        else
            ret = fun(idx + 1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    string x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        if (isalpha(x[0]))
            X[97 + i] = X[x[0]];
        else
            X[97 + i] = atoi(x.c_str());
        if (isalpha(y[0]))
            Y[97 + i] = X[y[0]];
        else
            Y[97 + i] = atoi(y.c_str());
    }
    cout << fun(0) << '\n';
    return 0;
}