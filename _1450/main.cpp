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
items[]�� lows, highs �迭�� �����ڿ�
���� �κ���, ������ �κ��յ��� ���� ����ؼ� ���� �迭�� ����ְ�
�κ��յ�� ���
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