#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int N, D, C;
    cin >> N >> D >> C;
    int dependency[100001][3];
    for (int i = 0; i < D; i++)
    {
        cin >> dependency[i][0] >> dependency[i][1] >> dependency[i][2];
    }
    // bfs
    
    return 0;
}