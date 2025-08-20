import sys
from collections import deque

def getRipeDays(w, h, box):
    next = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    depth = [[-1] * w for _ in range(h)]
    total, ripe = 0, 0
    queue = deque([])
    for i in range(h):
        for j in range(w):
            if box[i][j] != -1:
                total += 1
            if box[i][j] == 1:
                queue.append((i, j))
                depth[i][j] = 0
                ripe += 1
    # bfs
    max_depth = 0
    while queue:
        vi, vj = queue.popleft()
        for di, dj in next:
            ni, nj = vi + di, vj + dj
            if ni < 0 or h <= ni or nj < 0 or w <= nj:
                continue
            if 0 <= ni < h and 0 <= nj < w and box[ni][nj] == 0 and depth[ni][nj] == -1:
                queue.append((ni, nj))
                depth[ni][nj] = depth[vi][vj] + 1
                max_depth = depth[ni][nj]
                ripe += 1
                queue.append((ni, nj))
    return max_depth if total == ripe else -1

input = sys.stdin.readline
M, N = map(int, input().split())
box = []
for i in range(N):
    box.append(list(map(int, input().split())))
print(getRipeDays(M, N, box))