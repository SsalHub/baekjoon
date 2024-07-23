#include <iostream>

int main()
{
    float pos[4][2], line_len, hyp_len = -1, center_pos[4][2];
    int hyp_idx, i, j;
    for (i = 0; i < 3; i++)
        std::cin >> pos[i][0] >> pos[i][1];
    for (i = 0; i < 3; i++)
    {
        j = (i + 1) % 3;
        center_pos[i][0] = (pos[i][0] + pos[j][0]) / 2;
        center_pos[i][1] = (pos[i][1] + pos[j][1]) / 2;
        line_len = (pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]);
        if (hyp_len < line_len)
        {
            hyp_len = line_len;
            hyp_idx = i;
        }
    }
    i = (hyp_idx + 2) % 3;
    pos[3][0] = 2 * center_pos[hyp_idx][0] - pos[i][0];
    pos[3][1] = 2 * center_pos[hyp_idx][1] - pos[i][1];
    std::cout << pos[3][0] << " " << pos[3][1] << "\n";
    return 0;
}
