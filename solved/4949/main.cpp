#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (getline(cin, s))
    {
        if (!s.compare("."))
            break;
        stack<char> bracket;
        for (char c: s)
        {
            if (c == ')')
            {
                if (bracket.size() == 0 || bracket.top() != '(')
                {
                    bracket.push(c);
                    break;
                }
                bracket.pop();
            }
            else if (c == ']')
            {
                if (bracket.size() == 0 || bracket.top() != '[')
                {
                    bracket.push(c);
                    break;
                }
                bracket.pop();
            }
            else if (c == '(' || c == '[')
            {
                bracket.push(c);
            }
        }
        if (bracket.size())
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}