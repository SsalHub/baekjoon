#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    while (b != 0)
    {
        long long int t = b;
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
    long long int A, B;
    cin >> A >> B;
    cout << A * B / gcd(A, B);
    return 0;
}