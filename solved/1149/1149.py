import sys
input = sys.stdin.readline

N = int(input().strip())
house = [list(map(int, input().strip().split())) for _ in range(N)]
cost = [[0, 0, 0] for _ in range(N+1)]
for i in range(1, N+1):
    cost[i][0] = house[i-1][0] + min(cost[i-1][1], cost[i-1][2])
    cost[i][1] = house[i-1][1] + min(cost[i-1][0], cost[i-1][2])
    cost[i][2] = house[i-1][2] + min(cost[i-1][0], cost[i-1][1])
print(min(cost[N][0], min(cost[N][1], cost[N][2])))