#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> trees(N);
    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    vector<int> dist(N - 1);
    for (int i = 1; i < N; i++)
    {
        dist[i - 1] = trees[i] - trees[i - 1];
    }

    int min_gcd = dist[0];
    for (int i = 1; i < (int)dist.size(); i++)
    {
        min_gcd = gcd(min_gcd, dist[i]);
    }

    int add_trees = 0;
    for (int d : dist)
    {
        add_trees += d / min_gcd - 1;
    }
    cout << add_trees;
    return 0;
}