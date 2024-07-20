#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char N[100], c;
    int B, pow = 1, len, result = 0;
    cin >> N >> B;
    len = strlen(N);
    for (int i = 0; i < len; i++)
    {
        c = N[len - 1 - i];
        if (c <= '9')
            result += pow * (c - '0');
        else
            result += pow * (c - 'A' + 10);
        pow *= B;
    }
    std::cout << result << "\n";
    return 0;
}