
def getRipeDays(w, h, box):
    days = 0
    visited = [[0] * w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            if box[i][j] == 1 and visited[i][j] == 0:
                pass

M, N = map(int, input().split())
box = []
for i in range(N):
    box.append(list(map(int, input().split())))
