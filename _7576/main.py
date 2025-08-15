def getUnitRipeDays(w, h, graph, visited, start):
    np = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    si, sj = start
    queue = [(si, sj)]
    days = 1
    visited[si][sj] = days
    while queue:
        vi, vj = queue.pop(0)
        for di, dj in np:
            ni, nj = vi + di, vj + dj
            if ni < 0 or h <= ni or nj < 0 or w <= nj:
                continue
            if graph[ni][nj] == 0 and visited[ni][nj] == 0:
                visited[ni][nj] = visited[vi][vj] + 1
                days = visited[ni][nj]
                queue.append((ni, nj))
    return days

def getBoxRipeDays(w, h, box):
    visited = [[0] * w for _ in range(h)]
    days = 0
    for i in range(h):
        for j in range(w):
            if box[i][j] == 1 and visited[i][j] == 0:
                days = max(days, getUnitRipeDays(w, h, box, visited, (i, j)))


M, N = map(int, input().split())
box = []
for i in range(N):
    box.append(list(map(int, input().split())))
getBoxRipeDays(M, N, box)