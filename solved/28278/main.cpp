#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> st;
    while (N--)
    {
        int cmd, v;
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cin >> v;
            st.push(v);
            break;
        case 2:
            if (st.size())
            {
                cout << st.top() << '\n';
                st.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
            break;
        case 3:
            cout << st.size() << '\n';
            break;
        case 4:
            v = st.size() ? 0 : 1;
            cout << v << '\n';
            break;
        case 5:
            if (st.size())
            {
                cout << st.top() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
            break;
        }
    }
    return 0;
}