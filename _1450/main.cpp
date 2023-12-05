#include <iostream>

using namespace std;

int packKnapsack(int itemWeight[], int items, int knapsackWeight);

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

int packKnapsack(int itemWeight[], int items, int knapsackWeight)
{
    int i, len = items + 1, table[][] = { 0, };
    
    for (i=1; i<len; i++)
    {
        
    }

    return 0;
}