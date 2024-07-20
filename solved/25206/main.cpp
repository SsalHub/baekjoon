#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char subName[51], subAvg[5];
    float myScore, avgScore, totalAvg = 0, totalScore = 0;
    for (int i = 0; i < 20; i++)
    {
        cin >> subName >> myScore >> subAvg;
        avgScore = 0;
        if (0 < (subAvg[0] - 'E') * -1)
        {
            // A, B, C, D
            avgScore += (subAvg[0] - 'E') * -1;
            if (subAvg[1] == '+')
                avgScore += 0.5;
        }
        else
        {
            // F, P
            if (subAvg[0] == 'P')
                continue;
        }
        totalAvg += myScore * avgScore;
        totalScore += myScore;
    }
    cout << totalAvg / totalScore << "\n";
    return 0;
}