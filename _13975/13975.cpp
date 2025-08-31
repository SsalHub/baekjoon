#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        priority_queue<int, vector<int>, greater<>> file;
        for (int i = 0; i < K; i++)
        {
            int n;
            cin >> n;
            file.push(n);
        }
        int sum = 0;
        while (2 <= file.size())
        {
            int a, b;
            a = file.top();
            file.pop();
            b = file.top();
            file.pop();
            sum += a + b;
            file.push(a + b);
        }
        cout << sum << '\n';
    }
    return 0;
}