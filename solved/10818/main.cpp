#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, input, min = 1000001, max = -1000001;
    cin >> N;
    while (N--)
    {
        cin >> input;
        if (input < min)
            min = input;
        if (max < input)
            max = input;
    }
    cout << min << " " << max << "\n";
    return 0;
}