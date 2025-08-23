import sys

def getMaxScore(N, T, time, score):
    table = [[0] * (T + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(1, T + 1):
            if j < time[i - 1]:
                table[i][j] = table[i-1][j]
            else:
                include = table[i - 1][j - time[i - 1]] + score[i - 1]
                exclude = table[i - 1][j]
                table[i][j] = max(include, exclude)
    return table[N][T]

input = sys.stdin.readline
N, T = map(int, input().split())
K = []
S = []
for _ in range(N):
    k, s = map(int, input().split())
    K.append(k)
    S.append(s)
print(getMaxScore(N, T, K, S))