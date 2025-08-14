def searchUnit(apart_size, apart, visited, si, sj, unit_idx):
    np = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    size = 1
    queue = [(si, sj)]
    visited[si][sj] = unit_idx
    while queue:
        pi, pj = queue.pop(0)
        for di, dj in np:
            ni, nj = pi + di, pj + dj
            if ni < 0 or apart_size <= ni or nj < 0 or apart_size <= nj:
                continue
            if apart[ni][nj] == '1' and visited[ni][nj] == 0:
                size += 1
                queue.append((ni, nj))
                visited[ni][nj] = unit_idx
    return size

def getUnits(apart_size, apart):
    visited = [[0] * apart_size for _ in range(apart_size)]
    units = []
    unit_idx = 0
    for i in range(apart_size):
        for j in range(apart_size):
            if apart[i][j] == '1' and visited[i][j] == 0:
                unit_idx += 1
                units.append(searchUnit(apart_size, apart, visited, i, j, unit_idx))
    return units

n = int(input())
apart = []
for _ in range(n):
    apart.append(input())
units = sorted(getUnits(n, apart))
print(len(units))
for size in units:
    print(size)