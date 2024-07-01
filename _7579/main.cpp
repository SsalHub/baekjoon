#include <iostream>
#include <vector>

using namespace std;

int getMinCost(int n, int m, vector<int> mems, vector<int> costs);

int main()
{
    std::ios_base::sync_with_stdio();
    int n, m, mems_total = 0, costs_total = 0;
    vector<int> mems, costs;

    cin >> n >> m;
    mems.resize(n);
    costs.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mems[i];
        mems_total += mems[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
        costs_total += costs[i];
    }

    getMinCost(n, mems_total - m, mems, costs);
}

int getMinCost(int n, int m, vector<int> mems, vector<int> costs)
{
    int table[n + 1][m + 1] = {
        0,
    };
    int include, exclude;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (mems[i - 1] <= j)
            {
                include = table[i - 1][j] + costs[i - 1];
                exclude = table[i][j - 1];
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
}