#include <iostream>
#include <queue>
#define _MAX_   101

using namespace std;

typedef struct Point {
    int x;
    int y;
    int depth;
} Point;

int getFastestDepth(const int w, const int h, char maze[][_MAX_]);

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
    depth = getFastestDepth(m, n, maze);
    cout << depth << '\n';
    return 0;
}

int getFastestDepth(const int w, const int h, char maze[][_MAX_])
{
    int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    bool visited[_MAX_][_MAX_] = { false };
    Point start = { 1, 1, 1 };
    queue<Point> q;
    visited[start.y][start.x] = true;
    q.push(start);
    while (q.size())
    {
        Point v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point n = { v.x + next[i][1], v.y + next[i][0], v.depth + 1 };
            if ((n.x <= w && n.y <= h) && maze[n.y][n.x] == '1' && !visited[n.y][n.x])
            {
                if (n.x == w && n.y == h)
                    return n.depth;
                visited[n.y][n.x] = true;
                q.push(n);
            }
        }
    }
    return -1;
}