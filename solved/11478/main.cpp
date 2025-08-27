#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S;
    cin >> S;
    unordered_set<string> subs;
    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 1; j <= S.length(); j++)
        {
            subs.insert(S.substr(i, j));
        }
    }
    cout << (int)subs.size();
    return 0;
}