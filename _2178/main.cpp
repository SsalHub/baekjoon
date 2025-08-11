#include <iostream>
#define _MAX_   101

using namespace std;

int getFastestDepth(int w, int h, char maze[][_MAX_], bool visited[][_MAX_], int curr_x, int curr_y, int curr_depth);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, depth;
    char maze[_MAX_][_MAX_] = { '0' };
    bool visited[_MAX_][_MAX_] = { false };
    cin >> n >> m;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            // fill array by '0'
            maze[i][j] = '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> &(maze[i][1]);
    }
    depth = getFastestDepth(m, n, maze, visited, 1, 1, 1);
    cout << depth << '\n';
    return 0;
}

int getFastestDepth(int w, int h, char maze[][_MAX_], bool visited[][_MAX_], int curr_x, int curr_y, int curr_depth)
{
    int next[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    int depth, next_x, next_y;
    visited[curr_y][curr_x] = true;
    cout << "(" << curr_x << ", " << curr_y << ")\n";
    if (curr_x == w && curr_y == h)
        return curr_depth;
    depth = curr_depth;
    for (int i = 0; i < 4; i++)
    {
        next_x = curr_x + next[i][0];
        next_y = curr_y + next[i][1];
        if (w < next_x || h < next_y)
            continue;
        if (maze[next_y][next_x] == '1' && !visited[next_y][next_x])
        {
            depth = max(depth, getFastestDepth(w, h, maze, visited, next_x, next_y, curr_depth + 1));
        }
    }
    if (depth == curr_depth)
        return -1;
    return depth;
}