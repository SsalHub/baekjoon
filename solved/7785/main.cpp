#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    set<string> emp;
    while (N--)
    {
        string name, status;
        cin >> name >> status;
        if (status == "enter")
            emp.insert(name);
        else
            emp.erase(name);
    }
    for (auto e = emp.rbegin(); e != emp.rend(); e++)
    {
        cout << *e << '\n';
    }
    return 0;
}