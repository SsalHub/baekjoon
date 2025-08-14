def getShortestDepth(h, w, maze):
    np = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    visited = [[0] * w for _ in range(h)]
    sy, sx = 0, 0
    queue = [(sy, sx)]
    visited[sy][sx] = 1
    while queue:
        y, x = queue.pop(0)
        if x + 1 == w and y + 1 == h:
            return visited[y][x]    # result
        for dy, dx in np:
            nx, ny = x + dx, y + dy
            if nx < 0 or w <= nx or ny < 0 or h <= ny:
                continue
            if maze[ny][nx] == '1' and visited[ny][nx] == 0:
                queue.append((ny, nx))
                visited[ny][nx] = visited[y][x] + 1
    return -1

h, w = map(int, input().split())
maze = []
for _ in range(h):
    maze.append(input())
print(getShortestDepth(h, w, maze))