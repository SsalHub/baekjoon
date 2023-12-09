#include <iostream>
#include <cstring>

int combineCoin(int coin[], int n, int currCoin, int currValue);

int main()
{
    int i, n, k, *coin;

    std::cin >> n >> k;
    coin = new int[n];
    for (i=0; i<n; i++)
    {
        std::cin >> coin[i];
    }
    std::cout << combineCoin(coin, n, 0, k);

    delete []coin;
    return 0;
}

int combineCoin(int coin[], int n, int currCoin, int currValue)
{
    if (currValue < 0) return 0;
    if (currValue == 0) return 1;

    int i, result = 0;
    for (i=currCoin; i<n; i++)
    {
        result += combineCoin(coin, n, i, currValue - coin[i]);
    }

    return result;
}