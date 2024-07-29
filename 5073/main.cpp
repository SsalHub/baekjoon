#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int A, B, C, hyp;
    while (1)
    {
        cin >> A >> B >> C;
        if (!A && !B && !C)
            break;
        hyp = max(A, max(B, C));
        if (A + B + C - hyp <= hyp)
        {
            cout << "Invalid" << "\n";
        }
        else
        {
            if (A == B && B == C && A == C)
            {
                cout << "Equilateral" << "\n";
            }
            else
            {
                if (A != B && B != C && A != C)
                {
                    cout << "Scalene" << "\n";
                }
                else
                {
                    cout << "Isosceles" << "\n";
                }
            }
        }
    }
    return 0;
}