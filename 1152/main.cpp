#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char S[1000001];
    int words = 0;
    while (cin >> S)
    {
        words++;
    }
    cout << words << "\n";
    return 0;
}