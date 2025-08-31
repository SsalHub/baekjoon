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
        priority_queue<long long int, vector<long long int>, greater<>> file;
        for (int i = 0; i < K; i++)
        {
            int n;
            cin >> n;
            file.push(n);
        }
        long long int sum = 0;
        while (2 <= file.size())
        {
            long long int a, b;
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