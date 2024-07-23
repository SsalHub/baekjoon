#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int A, B, V, day;
    cin >> A >> B >> V;
    day = (V - A) / (A - B) + 1;
    if ((V - A) % (A - B))
        day++;
    cout << day << "\n";
    return 0;
}