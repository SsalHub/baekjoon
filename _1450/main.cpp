#include <iostream>
#include <cstring>

using namespace std;

unsigned int packKnapsack(int items[], int n, int c);
unsigned int findCombi(int arr[], int len, int left, int right);

int main()
{
    int i, n, c, items[30];

    scanf("%d%d", &n, &c);
    for (i=0; i<n; i++)
    {
        scanf("%d", items+i);
    }

    cout << packKnapsack(items, n, c);

    return 0;
}

/*
items[]를 lows, highs 배열로 나눈뒤에
왼쪽 부분합, 오른쪽 부분합들을 전부 계산해서 각각 배열에 집어넣고
부분합들로 계산
*/

unsigned int packKnapsack(int items[], int n, int c)
{
    unsigned int cases;

    return cases;
}

unsigned int findCombi(int arr[], int len, int left, int right)
{
    int i;
    unsigned int cases = 0;


    return 0;
}