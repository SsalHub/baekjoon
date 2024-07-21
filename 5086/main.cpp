#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2;
    while (1)
    {
        cin >> n1 >> n2;
        if (!n1 && !n2)
            break;
        if (n1 < n2)
        {
            if (n2 % n1)
                cout << "neither\n";
            else
                cout << "factor\n";
        }
        else
        {
            if (n1 % n2)
                cout << "neither\n";
            else
                cout << "multiple\n";
        }
    }
    return 0;
}