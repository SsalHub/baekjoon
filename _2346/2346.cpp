#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    deque<pair<int, int>> ballon(N);
    deque<int> out;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        ballon[i].first = i + 1;
        ballon[i].second = n;
    }
    while (!ballon.empty())
    {
        pair<int, int> b = ballon.front();
        int next = b.second;
        out.push_back(b.first);
        ballon.pop_front();
        if (next < 0)
        {
            for (int i = 0; i < -next; i++)
            {
                b = ballon.back();
                ballon.pop_back();
                ballon.push_front(b);
            }
        }
        else
        {
            for (int i = 0; i < next - 1; i++)
            {
                b = ballon.front();
                ballon.pop_front();
                ballon.push_back(b);
            }
        }
    }
    for (int n : out)
        cout << n << ' ';
    return 0;
}