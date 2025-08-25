#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n[5], min, result;

    for (int i = 0; i < 5; i++)
    {
        cin >> n[i];
    }
    sort(n, n + 5);
    min = n[0];
    while (1)
    {
        int count = 0;
        for (int i = 0; i < 5; i++)
        {
            if (min % n[i] == 0)
            {
                count++;
            }    
        }
        if (3 <= count)
        {
            break;
        }
        min++;
    }
    cout << min << '\n';
    return 0;
}