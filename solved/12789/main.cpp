#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int students[1001];
    for (int i = 0; i < N; i++) cin >> students[i];
    stack<int> waiting;
    int order = 1, s = 0;
    while (s < N || !waiting.empty())
    {
        if (!waiting.empty() && waiting.top() == order)
        {
            waiting.pop();
            order++;
            continue;
        }
        else if (s < N && students[s] == order)
        {
            s++;
            order++;
        }
        else if (s < N)
        {
            waiting.push(students[s++]);
        }
        else
        {
            break;
        }
    }
    cout << (waiting.empty() ? "Nice" : "Sad");
    return 0;
}