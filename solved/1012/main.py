
def findCabbages(w, h, field, visited, start):
    np = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    si, sj = start
    visited[si][sj] = False
    queue = [(si, sj)]
    while queue:
        vi, vj = queue.pop(0)
        for di, dj in np:
            ni, nj = vi + di, vj + dj
            if ni < 0 or h <= ni or nj < 0 or w <= nj:
                continue
            if field[ni][nj] and not visited[ni][nj]:
                visited[ni][nj] = True
                queue.append((ni, nj))

def getCabbageUnits(w, h, field):
    visited = [[False] * w for _ in range(h)]
    unit_idx = 0
    for i in range(h):
        for j in range(w):
            if field[i][j] and not visited[i][j]:
                unit_idx += 1
                findCabbages(w, h, field, visited, (i, j))
    return unit_idx

T = int(input())
units = []
for _ in range(T):
    M, N, K = map(int, input().split())
    field = [[False] * M for __ in range(N)]
    for ___ in range(K):
        X, Y = map(int, input().split())
        field[Y][X] = True
    units.append(getCabbageUnits(M, N, field))
for u in units:
    print(u)