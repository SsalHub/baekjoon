import sys

input = sys.stdin.readline
T = int(input().strip())
for _ in range(T):
    k = int(input().strip())
    n = int(input().strip())
    apart = [[i for i in range(n+1)] for _ in range(k + 1)]
    for i in range(1, k + 1):
        for j in range(1, n + 1):
            apart[i][j] = apart[i][j-1] + apart[i-1][j]
    print(apart[k][n])