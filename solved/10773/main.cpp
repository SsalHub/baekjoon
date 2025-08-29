#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    stack<int> book;
    while (K--)
    {
        int N;
        cin >> N;
        if (N == 0)
            book.pop();
        else
            book.push(N);
    }
    int sum = 0;
    while (book.size())
    {
        sum += book.top();
        book.pop();
    }
    cout << sum << '\n';

    return 0;
}