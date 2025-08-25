#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int data[500001], count[8001] = { 0 }, avg;
    cin >> N;
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> data[i];
    }
    for (int i = 0; i < N; i++)
    {
        sum += data[i];
        count[data[i] + 4000]++;
    }
    avg = round(sum / N);
    sort(data, data + N);
    int max_n = 0, max_idx = count[0], max_cnt = 1;
    for (int i = 1; i <= data[N-1] + 4000; i++)
    {
        if (count[max_idx] < count[i])
        {
            max_idx = i;
            max_cnt = 1;
        }
        else if (count[max_idx] == count[i])
        {
            if (max_cnt < 2)
                max_idx = i;
            max_cnt++;
        }
    }
    max_n = max_idx - 4000;
    cout << avg << '\n' << data[N/2] << '\n' << max_n << '\n' << data[N-1] - data[0];
    return 0;
}