#include <iostream>

using namespace std;

int getgcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int numerator = A * D + C * B, denominator = B * D;
    int gcd = getgcd(numerator, denominator);
    cout << numerator / gcd << ' ' << denominator / gcd;
    return 0;
}