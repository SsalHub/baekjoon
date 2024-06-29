#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int avg = 0, mid, arr[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        avg += arr[i];
    }
    avg /= 5;

    mid = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (abs(arr[i] - avg) < abs(mid - avg))
            mid = arr[i];
    }

    cout << avg << "\n"
         << mid;

    return 0;
}