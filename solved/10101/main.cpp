#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A + B + C != 180)
    {
        cout << "Error";
    }
    else
    {
        if (A == 60 && B == 60)
        {
            cout << "Equilateral";
        }
        else
        {
            if (A == B || B == C || A == C)
            {
                cout << "Isosceles";
            }
            else
            {
                cout << "Scalene";
            }
        }
    }
    return 0;
}