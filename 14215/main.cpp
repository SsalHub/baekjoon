#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, sum, hyp;
    cin >> a >> b >> c;
    sum = a + b + c;
    hyp = max(a, max(b, c));
    if (sum - hyp <= hyp)
        sum = 2 * (sum - hyp) - 1;
    cout << sum << "\n";
    return 0;
}