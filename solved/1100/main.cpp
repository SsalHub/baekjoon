#include <iostream>
#define SIZE 8

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, i, j;
    char c[SIZE+1];

    for (i = 0; i < SIZE; i++)
    {
        cin >> c;
        for (j = i % 2; j < SIZE; j += 2)
        {
            if (c[j] == 'F')
                n++;
        }
    }
    cout << n << '\n';
    return 0;
}